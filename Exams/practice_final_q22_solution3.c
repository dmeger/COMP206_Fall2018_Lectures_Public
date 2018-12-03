#include <stdio.h>
#include <stdlib.h>
#define MAX_ARGS 1000

void parseArgs( char* raw_command_line, int *argc, char *argv[MAX_ARGS] ){
// You fill in this code during the exam

	int rawPos = 0;
	char argArray[MAX_ARGS][MAX_ARGS];
	int lenArray[MAX_ARGS];

	for( int arg=0; arg<MAX_ARGS; arg++ ){
		int argPos = 0;
		while( raw_command_line[rawPos] != ' ' && raw_command_line[rawPos] != '\0' )
			argArray[arg][argPos++] = raw_command_line[rawPos++];

		argArray[arg][argPos++] = '\0';
		lenArray[arg] = argPos;

		if( raw_command_line[rawPos] == '\0' ){
			*argc = arg+1;
			break;
		}
		rawPos++;
	}

	for( int arg=0; arg<*argc; arg++ ){
		argv[arg] = (char*)malloc( lenArray[arg] * sizeof(char) );

		for( int argPos=0; argPos<lenArray[arg]; argPos++ ){
			argv[arg][argPos] = argArray[arg][argPos];
		}
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
