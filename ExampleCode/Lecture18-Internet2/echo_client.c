#include <stdio.h>	//printf
#include <string.h>	//strlen
#include <sys/socket.h>	//socket
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
	int sock;
	struct sockaddr_in server;
	char message[2000] , server_reply[2000];
	char addr[20] = "127.0.0.1";
	unsigned short int port = 8888;

	if( argc>1 ){
		strcpy( addr, argv[1] );
	}

	if( argc>2 ){
		port = (unsigned short int)atoi( argv[2] );
	}
	
	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");
	
	server.sin_addr.s_addr = inet_addr( argv[1] );
	server.sin_family = AF_INET;
	server.sin_port = htons( port );

	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("connect failed. Error");
		return 1;
	}
	
	puts("Connected\n");
	
	//keep communicating with server
	while(1)
	{
		printf("Enter message : ");
		char* ret = fgets (message , 2000 , stdin);
		if( ret == NULL ){
			break;
		}
		
		//Send some data
		if( send(sock , message , 2000, 0) < 0)
		{
			puts("Send failed");
			return 1;
		}
		
		//Receive a reply from the server
		size_t read_size = recv(sock , server_reply , 2000 , 0);
		if( read_size < 0)
		{
			puts("recv failed");
			break;
		}
		server_reply[read_size] = '\0';
		
		printf("Server reply : %s\n", server_reply);
	}
	
	close(sock);
	return 0;
}
