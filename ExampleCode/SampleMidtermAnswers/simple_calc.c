#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] ){


	int result = atoi(argv[1]);
	argv += 2;

	while( *argv ){

		if( strcmp( *argv, "x" ) == 0 )
			result *= atoi(argv[1]);
		else if( strcmp( *argv, "/" ) == 0 )
			result /= atoi(argv[1]);
		else if( strcmp( *argv, "+" ) == 0 )
			result += atoi(argv[1]);
		else if( strcmp( *argv, "-" ) == 0 )
			result -= atoi(argv[1]);
		else{
			printf( "There was an error. Operator %s not OK.\n", *argv );
			return -1;
		}
		
		argv += 2;
	}

	printf( "%d\n", result );
	

	return 0;
}
