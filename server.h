#ifndef _SERVER_H_

#include <sys/socket.h>
#include <netinet/in.h>

typedef struct server
{
	int domain;
	int service;
	int protocol;
	u_long interface;
	int port;
	int backlog;

	struct sockaddr_in address;
	int socket;
	void (*launch)(struct server *server);
} server_t;

server_t server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct server *server));

#endif /* _SERVER_H_ */
