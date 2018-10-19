/* File endianness_test.c 
   
   Explores the byte-ordering of integers 
   on the system it's run on. By using a shorter
   pointer than the target data-type, we can access
   the int it one byte at a time. Most personal computer
   systems are "Little Endian".
 
   Author: David Meger
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	int a = 257;
	char *p = &a;

	printf( "The value at p is %d.\n", *p );
	printf( "The value at p+1 is %d.\n", *(p+1) );
	printf( "The value at p+2 is %d.\n", *(p+2) );
	printf( "The value at p+3 is %d.\n", *(p+3) );
	
}
