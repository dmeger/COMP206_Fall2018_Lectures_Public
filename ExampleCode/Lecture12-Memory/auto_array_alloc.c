#include <stdio.h>
#include <stdlib.h>

int main(){

	long int automatic_array_size = 2;
	while(1){

		char automatic_array[automatic_array_size];

		printf( "I managed to allocate a string of size %ld.\n", automatic_array_size );

		automatic_array[automatic_array_size-1] = '2';
		printf( "The last element holds %c.\n", automatic_array[automatic_array_size-1] );

		automatic_array_size *= 2;
	}

	return 0;
}
