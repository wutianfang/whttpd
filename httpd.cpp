#include "httpd.h"
//#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <stdlib.h>

Httpd::Httpd(HttpConfig * config) {
	puts("Httpd Construct");
}

int Httpd::start(void) {
	int sockfd,request_fd;
	struct sockaddr_in request_addr;
	socklen_t  addr_size = sizeof(struct sockaddr_in);
	sockfd = initServiceSock();
	puts("httpd start!");
	while(true) {
		request_fd = accept(sockfd, (struct sockaddr*)&request_addr, &addr_size);
		puts("new request");
		if (-1==request_fd) {
			perror("accept");
			continue;
		}
		send(request_fd, "Hello, world!\n", 14, 0);
		shutdown(request_fd, 2);
	}

}

int Httpd::initServiceSock(void) {
	int sockfd;
	struct sockaddr_in my_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int opt = 1;
	setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
	if (-1==sockfd) {
		perror("socket");
		exit(1);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(config->getPort());
	my_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1) {
		perror("bind");
		exit(1);
	}

	if (listen(sockfd, config->getBacklog()) == -1) {
		perror("listen");
		exit(1);
	}
	return sockfd;	
}

int Httpd::stop(void) {
	puts("Httpd stop!");
}
