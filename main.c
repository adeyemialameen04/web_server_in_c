#include "server.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void launch(server_t *server)
{
	char buffer[30000];
	char *hello = "HTTP/1.1 200 OK\n"													   // HTTP response line
				  "Date: Sun, 31 Mar 2024 12:11:30 WAT\n"								   // Date header
				  "Server: Apache/2.2.14 (Win32)\n"										   // Server header
				  "Last-Modified: Monday, 1 Apr 2024 19:15:56 WAT\n"					   // Last-Modified header
				  "Content-Type: text/html\n"											   // Content-Type header
				  "Connection: Closed\n\n"												   // Connection header
				  "<html><body><h1>Hello my creator</h1> <p>yare yare</p> </body></html>"; // HTML body
	int new_socket;
	socklen_t addr_len = sizeof(server->address);
	while (1)
	{
		printf("==== WAITING FOR CONNECTION... ====\n");
		new_socket = accept(server->socket, (struct sockaddr *)&server->address, &addr_len);
		read(new_socket, buffer, 30000);
		printf("%s\n", buffer);
		write(new_socket, hello, strlen(hello));
		close(new_socket);
	}
}

int main(void)
{
	server_t server = server_constructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
	server.launch(&server);
	return (0);
}
