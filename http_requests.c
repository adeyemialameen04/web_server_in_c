#include "http_requests.h"
#include <string.h>
#include <stdlib.h>

int method_select(char *method)
{
	if (strcmp(method, "GET") == 0)
	{
		return (GET);
	}
	else if (strcmp(method, "POST") == 0)
	{
		return (POST);
	}
	else if (strcmp(method, "PUT") == 0)
	{
		return (PUT);
	}
	else if (strcmp(method, "HEAD") == 0)
	{
		return (HEAD);
	}
	else if (strcmp(method, "PATCH") == 0)
	{
		return (PATCH);
	}
	else if (strcmp(method, "DELETE") == 0)
	{
		return (DELETE);
	}
	else if (strcmp(method, "CONNECT") == 0)
	{
		return (CONNECT);
	}
	else if (strcmp(method, "OPTIONS") == 0)
	{
		return (OPTIONS);
	}
	else if (strcmp(method, "TRACE") == 0)
	{
		return (DELETE);
	}
}

HTTPRequest_t http_request_constructor(char *request_string)
{
	HTTPRequest_t request;
	int req_str_len = strlen(request_string);
	char requested[req_str_len];
	strcpy(requested, request_string);
	int i;

	for (i = 0; i < strlen(requested) - 1; i++)
	{
		if (requested[i] == '\n' && requested[i + 1] == '\n')
		{
			requested[i + 1] = '|';
		}
	}

	char *request_line = strtok(requested, "\n");
	char *header_fields = strtok(NULL, "|");
	char *body = strtok(NULL, "|");

	char *method = strtok(request_line, " ");

	request.method = method_select(method);
	char *URI = strtok(NULL, " ");
	request.URI = URI;
	char *http_version = strtok(NULL, " ");
	http_version = strtok(http_version, "/");
	http_version = strtok(NULL, "/");
	request.HTTP_version = (float)atof(http_version);

		return (request);
}
