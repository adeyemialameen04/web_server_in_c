#include "server.h"
#include <stdio.h>
#include <stdlib.h>

server_t server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct server *server))
{
	int bind_res;
	server_t server;

	server.domain = domain;
	server.service = service;
	server.protocol = protocol;
	server.interface = interface;
	server.port = port;
	server.backlog = backlog;

	server.address.sin_family = domain;
	server.address.sin_port = htons(port);
	server.address.sin_addr.s_addr = htonl(interface);

	server.socket = socket(domain, service, protocol);
	if (server.socket == 0)
	{
		perror("Failed to connect to socket...\n");
		exit(EXIT_FAILURE);
	}

	bind_res = bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address));
	if (bind_res < 0)
	{
		perror("Failed to bind to socket...\n");
		exit(EXIT_FAILURE);
	}

	if ((listen(server.socket, server.backlog)) < 0)
	{
		perror("Failed to listen to socket...\n");
		exit(EXIT_FAILURE);
	}

	server.launch = launch;

	return (server);
}
