//
// This file is an example of what not to do
// The programmer has not matched up the array bounds
// with the loop limit, and so this program will read
// beyond the end of the valid array.
//
// Run it with different array limits (including really big ones
// in millions or billions to see what happens.
//

#include <stdio.h>

int main(){

	int array[10];
	for( int i=0; i<100; i++ )
		printf( "Value of array at %d is %d.\n", i, array[i] );
	return 0;
}
