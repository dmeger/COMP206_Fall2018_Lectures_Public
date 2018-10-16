#include <stdio.h>

int main( int argc, char *argv[] ){


	if( argc<2 ){
		printf( "Argument required: filename.\n" );
		return -1;
	}

	FILE* fp = fopen( argv[1], "r" );
	
	if( !fp ){
		printf( "Unable to open file %s.\n", argv[1] );
		return -1;
	}


	fseek( fp, 0, SEEK_END );
	size_t size = ftell( fp );
	rewind( fp );

	char file_data[ size ];

	fread( file_data, 1, size, fp );

	char *pos = file_data;

	
	while( *pos ){
		printf( "%c\n", *pos );
		pos++;

		while( *pos != '\r' && *pos != '\n' && *pos != ' ' ){
			if( *pos == '\0' )
				break;
			pos++;
		}

		while( *pos == '\n' || *pos == '\r' || *pos == ' ' )
			pos++;

	}			
		

	return 0;
}
