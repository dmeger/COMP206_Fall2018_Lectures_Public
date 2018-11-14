all: httpd http_client

http_client: simpleclient.c
	gcc simpleclient.c -o http_client

httpd: httpd.c
	gcc -W -Wall -lpthread -o httpd httpd.c

clean:
	rm httpd http_client

