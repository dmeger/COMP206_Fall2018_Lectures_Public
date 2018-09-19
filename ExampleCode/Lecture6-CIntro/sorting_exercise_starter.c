/* FILE: sorting_excersize_starter.c
 * 
 * Please fill this in with some code to sort. You can use the 
 * linear sort algorithm suggested on the Lecture 6 slides
 * or something you learned in a previous course.
 * Good luck!
 *
 * Author: David Meger
 * Date:   Sept 19, 2018
 */

#include <stdio.h>

int main(){

	int array[4];

	array[0] = 4;
	array[1] = 2;
	array[2] = 1;
	array[3] = 3;

	// Write your code here, try to sort the array

	printf( "The array holds: " );
	for( int i=0; i<4; i++ )
		printf( "%d ", array[i] );

	printf("\n");

	printf( "If you coded it correctly, you should see 1 2 3 4\n");
	
	return 0;	 
}
