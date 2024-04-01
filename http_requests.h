#ifndef _http_requests_H

enum HTTPMethods
{
	GET,
	POST,
	PUT,
	HEAD,
	PATCH,
	DELETE,
	CONNECT,
	OPTIONS,
	TRACE
};

typedef struct HTTPRequest
{
	int method;
	char *URI;
	float HTTP_version;
} HTTPRequest_t;

HTTPRequest_t http_request_constructor(char *request_string);

#endif /* _http_requests_H */
