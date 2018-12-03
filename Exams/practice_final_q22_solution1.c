#include <stdio.h>
#define MAX_ARGS 1000

void parseArgs( char* raw_command_line, int *argc, char *argv[MAX_ARGS] ){
// You fill in this code during the exam

	*argc=0;
	argv[(*argc)++] = raw_command_line;

	while( *raw_command_line ){
		if( *raw_command_line == ' ' ){
			*raw_command_line = '\0';
			argv[(*argc)++] = raw_command_line + 1;
		}
		raw_command_line++;
	}	

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
