#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int new;
} t_client;

t_client clients[10000];
char buffer[10000], c;
int sockfd, conn_fd, max_fd, client_count = 0;
fd_set sockets, r_fd, w_fd;
volatile sig_atomic_t keeping_runnning = 1;

int	ft_error(char* msg){
	return (write(2, msg, strlen(msg)) || 1);
}

void handle_sigint(int sig){
	(void)sig;
	keeping_runnning = 0;
}

void send_all(char* msg, int arg, int ownder_fd){
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
		return ft_error("Wrong number of arguments\n");
	}
	port = atoi(av[1]);
	if (port < 1 || port > 65535){
		return ft_error("Fatal error");
	}
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
		return ft_error("Fatal error");
	}

	struct sockaddr_in servaddr = {0};
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(port);

	if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0){
		close (sockfd);
		return ft_error("Fatal error");
	}
	if (listen(sockfd, 10) != 0){
		close (sockfd);
		return ft_error("Fatal error");
	}

	memset(clients, 1, sizeof(clients));
	FD_ZERO(&sockets);
	FD_SET(sockfd, &sockets);
	max_fd = sockfd;

	while (keeping_runnning){
		r_fd = w_fd = sockets;
		if (select(max_fd + 1, &r_fd, &w_fd, NULL, NULL) < 0){
			if (keeping_runnning)
				continue;
			else
				break;
		}
		for (int fd = 0; fd <= max_fd; fd++){
			if (FD_ISSET(fd, &r_fd)){
				
			}
		}
	}
}
