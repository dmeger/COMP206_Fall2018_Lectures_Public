/* FILE: simple_web_client.c implements the HTTP interface
 *       in order to download information from the web.
 *       Compile and run it with a web address like example.com
 *       in order to see the pages returned.
 *
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char** argv) {

    struct addrinfo hints;
    memset(&hints, 0, sizeof hints); 
    hints.ai_family = AF_INET ; 
    hints.ai_socktype = SOCK_STREAM;
    struct addrinfo *servinfo; 
    int status = getaddrinfo(argv[1], "80",
                                &hints, &servinfo);
    int sockfd = socket(servinfo->ai_family,
                        servinfo->ai_socktype,
                        servinfo->ai_protocol);
    connect(sockfd, 
           servinfo->ai_addr,
           servinfo->ai_addrlen); 
           
    char header[1000];
    sprintf(header, "GET /index.html HTTP/1.1\r\nHost:%s\r\n\r\n", argv[1] );
    int n = write(sockfd, header, strlen(header));
 
    char buffer[2048];
    n = read(sockfd, buffer, 2048);
    printf("%s", buffer);
 
    return (EXIT_SUCCESS);
}

