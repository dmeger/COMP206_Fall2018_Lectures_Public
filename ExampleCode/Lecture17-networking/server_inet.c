/*
 * socket demonstrations:
 * This is the server side of an "internet domain" socket connection, for 
 * communicating over the network.
 */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int fd, clientfd;
    int len;
    socklen_t size;
    struct sockaddr_in r, q;
    char buf[80];

    /* "AF_INET" says we'll use the internet */
    if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return(1);
    }

    /* Specify port number. Note, we do not give our address here because
       the server's job is to listen. The whole computer has an address, so
       this is the only one we can listen on. */
    memset(&r, '\0', sizeof r);
    r.sin_family = AF_INET;
    r.sin_addr.s_addr = INADDR_ANY;
    r.sin_port = htons(1234);

    /* Bind connects the socket, tells the OS we're ready to use it. */
    if (bind(fd, (struct sockaddr *)&r, sizeof r) < 0) {
        perror("bind");
        return(1);
    }
    
    /* Listen blocks until a client tries to connect */
    if (listen(fd, 5)) {
    	perror("listen");
    	return(1);
    }

    /* Accept says, OK, let's talk! */
    size = sizeof q;
    if ((clientfd = accept(fd, (struct sockaddr *)&q, &size)) < 0) {
        perror("accept");
        return(1);
    }

    /* Read is now much like a file, we can keep grabbing data that's sent. */
    if ((len = read(clientfd, buf, sizeof buf - 1)) < 0) {
        perror("read");
        return(1);
    }
    buf[len] = '\0';
    /*
     * Here we should be converting from the network newline convention to the
     * unix newline convention, if the string can contain newlines. Ignoring for
     * now to keep it simple.
     */

    printf("The other side said: %s\n", buf);

    /* We're done listening to this client. */
    close(clientfd);

    /*
     * We didn't really have to do that since we're exiting.
     * But usually you'd be looping around and accepting more connections.
     */

    return(0);
}

