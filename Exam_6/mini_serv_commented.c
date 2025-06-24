#include <string.h>
#include <unistd.h>
#include <sys/select.h>   // for select(), fd_set, FD_* macros
#include <netinet/in.h>   // for sockaddr_in, htons, htonl
#include <stdlib.h>       // for atoi()
#include <stdio.h>        // for sprintf()
#include <signal.h>       // for signal(), sig_atomic_t

// Struct representing a client connection
typedef struct {
    int id;   // Unique client ID
    int new;  // Flag to indicate if next message starts a new line
} t_client;

t_client clients[10000];  // Array to store info about clients, indexed by file descriptor
char buffer[10000], c;    // Shared buffer for sending messages; char for receiving 1 byte at a time
int sockfd, conn_fd, max_fd, client_count = 0;  // Server socket, connection socket, max fd seen, total client count
fd_set sockets, r_fd, w_fd;  // fd_sets for all sockets, read-ready fds, write-ready fds
volatile sig_atomic_t keeping_running = 1;  // Signal-safe flag to control main loop

// Print error message and return failure
int ft_error(char* msg) {
    return write(2, msg, strlen(msg)) || 1;
}

// Handle SIGINT (Ctrl+C) to gracefully stop the server
void handle_sigint(int sig) {
    (void)sig;  // Unused parameter
    keeping_running = 0;
}

// Send formatted message to all connected clients except the owner
void send_all(char* msg, int arg, int owner_fd) {
    sprintf(buffer, msg, arg);  // Format message with client ID or arg
    for (int fd = 0; fd <= max_fd; fd++) {
        if (FD_ISSET(fd, &w_fd) && fd != owner_fd) {  // If fd is ready for writing and not the sender
            write(fd, buffer, strlen(buffer));
        }
    }
}

int main(int ac, char** av) {
	if (ac != 2){
        	return ft_error("Wrong number of arguments\n");
	}
	int port = atoi(av[1]);
    signal(SIGINT, handle_sigint);  // Register signal handler for graceful shutdown



    // Convert port argument to integer and validate
    if (port < 1 || port > 65535)
        return ft_error("Fatal error\n");

    // Create TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return ft_error("Fatal error\n");

    // Configure server address structure
    struct sockaddr_in servaddr = {0};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1 in network byte order
	servaddr.sin_port = htons(port);              // Convert port to network byte order

    // Bind socket to address and port
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        close(sockfd);
        return ft_error("Fatal error\n");
    }

    // Listen for incoming connections
    if (listen(sockfd, 10) != 0)
    {
        close(sockfd);
        return ft_error("Fatal error\n");
    }

    // Initialize clients array (set .new and .id to 1)
    memset(clients, 1, sizeof(clients));

    // Initialize fd_set
    FD_ZERO(&sockets);
	// storing sockfd into sockets
    FD_SET(sockfd, &sockets);
    max_fd = sockfd; // remember to set max_fd here

    // Main server loop
    while (keeping_running) {
        // Copy fd_sets because select() modifies them
        r_fd = w_fd = sockets;

        // Wait for activity on any file descriptor
        if (select(max_fd + 1, &r_fd, &w_fd, NULL, NULL) < 0) {
            if (keeping_running)
                continue;  // Ignore if interrupted by signal
            else
                break;     // Exit if keeping_running was set to 0
        }

        // Check each fd for readiness
        for (int fd = 0; fd <= max_fd; fd++) {
			// Is fd flagged as ready for reading by select() in the r_fd set
			// Non-zero (true) → The fd is set (fd is ready)
			// 0 (false) → The fd is not set (not ready)
            if (FD_ISSET(fd, &r_fd)) {  // fd ready for reading
                if (fd == sockfd) {
                    // New connection request
                    if ((conn_fd = accept(sockfd, NULL, NULL)) < 0)
                        continue;  // Skip if accept failed
                    send_all("server: client %d just arrived\n", client_count, conn_fd);
                    clients[conn_fd].id = client_count++;
					// storing connfd into sockets
                    FD_SET(conn_fd, &sockets);
                    if (conn_fd > max_fd)
                        max_fd = conn_fd;
                } else {
                    // Existing client sent data or disconnected
                    if (recv(fd, &c, 1, 0) <= 0) {
                        // Client disconnected
                        send_all("server: client %d just left\n", clients[fd].id, fd);
                        FD_CLR(fd, &sockets);
                        close(fd);
                    } else {
                        // Received a character
                        if (clients[fd].new) {
                            clients[fd].new = 0;
                            send_all("client %d: ", clients[fd].id, fd);
                        }
                        if (c == '\n')
                            clients[fd].new = 1;
                        send_all(&c, 0, fd);
                    }
                }
            }
        }
    }

    // Cleanup: close all fds
    for (int fd = 0; fd <= max_fd; fd++) {
        if (FD_ISSET(fd, &sockets))
            close(fd);
    }
    close(sockfd);
}

