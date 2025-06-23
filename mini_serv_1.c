#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/select.h>
#include <netinet/in.h>

typedef struct {
	int id;
	int new;
} t_client;

t_client clients[10000];
char buffer[10000], c;
int sockfd, conn_fd, max_fd, client_count = 0;
fd_set sockets, r_fd, w_fd;
volatile sig_atomic_t keeping_running = 1;

int	ft_error(char* msg){
	return (write(2, msg, strlen(msg)) || 1);
}

void	handle_sigint(int sig){
	(void)sig;
	keeping_running = 0;
}

void	sent_all(char* msg, int arg, int ownder_fd){
	sprintf(buffer, msg, arg);
	for (int fd = 0; fd <= max_fd; fd++){
		if (FD_ISSET(fd, &w_fd) && fd != ownder_fd){
			write(fd, buffer, strlen(buffer));
		}
	}
}

int	main(int ac, char** av){
	signal(SIGINT, handle_sigint);
	int port;

	if (ac != 2){
		return (ft_error("Wrong number arguments\n"));
	}
	port = atoi(av[1]);
	if (port < 1 || port > 65535){
		return (ft_error("Fatal error\n"));
	}
	if ((sockfd = socket(AFINT, SOCK_STREAM, 0)) < 0){
		return (ft_error("Fatal error\n"));
	}

	struct sockaddr_in servaddr = {0};
	servaddr.sin_family = AFINT;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0){
		close(sockfd);
		return (ft_error("Fatal error\n"));
	}
	if (listen(sockfd, 10) != 0){
		close(sockfd);
		return (ft_error("Fatal error\n"));
	}

	memset(clients, 1, sizeof(clients));
	FD_ZERO(&sockets);
	FD_SET(sockfd, &sockets);
	max_fd = sockfd;

	while (keeping_running){
		r_fd = w_fd = sockets;
		if (select(max + 1, &r_fd, &w_fd, NULL, NULL) < 0){
			if (keeping_running)
				continue;
			else
				break;
		}
		for (int fd = 0; fd <= max_fd; fd++){
			if (FD_ISSET(fd, &r_fd)){
				if (fd == sockfd){
					if ((conn_fd = accept(sockfd, NULL, NULL)) < 0)
						continue;
					send_all("server: client %d just arrived\n", client_count, conn_fd);
					clients[conn_fd].id = client_count++;
					FD_SET(conn_fd, &sockets);
					if (conn_fd > max_fd)
						max_fd = conn_fd;
				} else {
					if (recv(fd, &c, 1, 0) <= 0){
						send_all("server: client %d just left\n", clients[fd].id, fd);
						FD_CLR(fd, &sockets);
						close(fd);
					} else {
						if (clients[fd].new){
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
	for (int fd = 0; fd <= max_fd; fd++){
		if (FD_ISSET(fd, &sockets))
			close(fd);
	}
	close(sockfd);
}