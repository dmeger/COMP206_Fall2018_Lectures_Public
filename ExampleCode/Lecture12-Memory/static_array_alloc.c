#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static char static_array[STATIC_ARRAY_SIZE];

int main(){

	printf( "I managed to statically allocate a string of size %ld.\n", (long int)STATIC_ARRAY_SIZE );	
	
	for( long int pos=0; pos<(long int)(STATIC_ARRAY_SIZE); pos++ )
		static_array[pos] = '2';

	printf( "The last element holds %c.\n", static_array[(long int)(STATIC_ARRAY_SIZE-1)] );
	int input;
	
	// This loop "pauses" execution so we can see the impact on our computer
	while( (input=getchar()) != 'q' ){ 
		usleep(10);
	}

	return 0;
}
