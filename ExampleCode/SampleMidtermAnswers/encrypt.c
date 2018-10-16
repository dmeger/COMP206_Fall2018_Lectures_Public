#include <stdio.h>
#include <stdlib.h>

void encrypt( char source[], char destination[], int key ){

	// Your code starts here
	int length = 0;
	while( source[length] != '\0'){
		length++;
	}

	char *ptr2 = destination + length;
	*ptr2 = '\0';
	ptr2--;
	char* ptr = source;

	while( *ptr ){
		*ptr2 = *ptr;

		for( int shift=0; shift<key; shift++ ){
	
			if( *ptr2 == 'Z' )
				*ptr2 = 'A';
			else if( *ptr2 == 'z' )
				*ptr2 = 'a';
			else
				(*ptr2)++;
		}

		ptr2--;
		ptr++;
	}

	// Your code ends here
}

int main( int argc, char* argv[] ){

	char destination[100];
	int key = atoi(argv[2]);

	encrypt( argv[1], destination, key );

	printf( "From source %s, with key %d, destination is %s.\n", 
		   argv[1], key, destination );

	return 0;
}
