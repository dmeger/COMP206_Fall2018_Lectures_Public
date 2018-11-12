#include <stdio.h>
#include <string.h>	//strlen
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr
#include <unistd.h>	//write
#include <stdlib.h>

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[2000];

	unsigned short int port = 8888;

	if( argc > 1 )
		port = (unsigned short int)atoi(argv[1]);
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		printf("Could not create socket");
	}
	puts("Socket created");
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( port );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return 1;
	}
	puts("bind done");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	puts("Waiting for incoming connections...");
	c = sizeof(struct sockaddr_in);
	
	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0)
	{
		perror("accept failed");
		return 1;
	}
	puts("Connection accepted");
	
	//Receive a message from client
	while( 1 ){
	  char temp[2000];
	  memset(client_message, '\0', 2000);
	  int bytes_read = 0;
	  while( bytes_read < 2000 ){
	    read_size = recv(client_sock , temp , 2000 , 0);
	    if(read_size <= 0){
		    puts("Client disconnected");
		    fflush(stdout);
		    close(client_sock);
		    close(socket_desc);
		    return 0;
	    }
	    memcpy( client_message+bytes_read, temp, read_size );
	    bytes_read += read_size;
	  }
	  
	  //Send the message back to client
	  write(client_sock , client_message , strlen(client_message));
	}
	
	close(client_sock);
	close(socket_desc);	
	
	return 0;
}
