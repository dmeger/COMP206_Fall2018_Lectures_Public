#include <stdio.h>
#include <stdlib.h>

int main(){

	long int dynamic_array_size = 2;
	char *dynamic_array;
	
	while(1){

		dynamic_array = (char*)malloc( dynamic_array_size*sizeof(char) );

		if( dynamic_array == NULL ){
			printf( "I failed to allocate string of size %ld.\n", dynamic_array_size );
			break;
		}

		printf( "I managed to allocate a string of size %ld.\n", dynamic_array_size );

		dynamic_array[dynamic_array_size-1] = '2';
		printf( "The last element holds %c.\n", dynamic_array[dynamic_array_size-1] );

		free(dynamic_array);
		dynamic_array_size *= 2;
	}

	dynamic_array_size /= 2; // The last one that worked
	dynamic_array = (char*)malloc( dynamic_array_size*sizeof(char) );

	if( dynamic_array != NULL ){
		printf( "OK, populating an array of size %ld... how long will this take?\n", dynamic_array_size );
		for( long int pos=0; pos<dynamic_array_size; pos++ ){
			dynamic_array[pos] = '2';
		}
	}

	return 0;
}
