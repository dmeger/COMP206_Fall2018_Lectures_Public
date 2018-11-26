#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

	int x = fork();

	if( x == -1 ){
		perror( "fork failed" );
		return 1;
	} else if( x == 0 ){
		// Child
		char *argument = "directory_that_doesnt_exist";
		execl( "/bin/ls", "ls", argument, (char*)NULL);
		perror( "/bin/ls" );
		return(1);
	} else{
		// Parent
		int status, pid;
		printf( "I am about to wait for ls to run.\n" );
		pid = wait( &status );
		printf( "pid %d exit status %d\n", pid, WEXITSTATUS(status));
		return 0;
	}
}
