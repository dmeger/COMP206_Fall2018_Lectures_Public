// An example of using semaphores
// to control the order of counting.
//
// Compile with -lpthread

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <semaphore.h>
#include <fcntl.h>

#define MAX_COUNT 200
#define BUF_SIZE 100

sem_t *s1;
sem_t *s2; 

int main(){

	pid_t pid;
	int i;
	char buf[BUF_SIZE];

	sem_unlink("first");
	sem_unlink("second");
	s1 = sem_open( "first", O_CREAT, 0066, 1 );
	s2 = sem_open( "second", O_CREAT, 0066, 0 );

	int x = fork();
	pid = getpid();

	for( i=1; i<= MAX_COUNT; i++ ){

		if( x == 0 ){
			sem_wait( s1 );
		}
		else{
			sem_wait( s2 );
		}

		sprintf( buf, "This line is from pid %d, value = %d\n", pid, i );
		write( 1, buf, strlen(buf));

		if( x==0 ){
			sem_post(s2);
		}
		else{
			sem_post(s1);
		}
	}

	sem_close(s1);
	sem_close(s2);
}

