#include <stdio.h>
#include <stdlib.h>
#define MAX_ARGS 1000

void parseArgs( char* raw_command_line, int *argc, char *argv[MAX_ARGS] ){
// You fill in this code during the exam

	int argNumber = 0;	
	argv[argNumber] = (char*)malloc(MAX_ARGS*sizeof(char));

	int argPos = 0;

	while( *raw_command_line ){

	
		if( *raw_command_line != ' ' ){
			argv[argNumber][argPos] = *raw_command_line;
			argPos++;
		}
		else{
			argv[argNumber][argPos] = '\0';
			argNumber++;
			argv[argNumber] = (char*)malloc(MAX_ARGS*sizeof(char));
			argPos = 0;
		}

		raw_command_line++;
	}

	argv[argNumber][argPos] = '\0';
	*argc = argNumber + 1;

// End of your solution
}

void main_like( char *raw_command_line ){

	int argc;
	char *argv[MAX_ARGS];
	parseArgs(raw_command_line, &argc, argv );

	printf( "raw_command_line was %s\n", raw_command_line );
	for( int i=0; i<argc; i++ ){
		printf( "Argument %d is %s\n", i, argv[i] );
	}
}

int main(){

	char raw_command_line[1000] = "./a.out Hello world";

	main_like( raw_command_line );

	return 0;
}
