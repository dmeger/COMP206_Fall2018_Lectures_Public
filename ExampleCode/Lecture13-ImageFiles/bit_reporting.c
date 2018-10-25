/* File bit_reporting.c 
   
   Uses the bit-wise operations left-shift and
   bitwise logical AND to sequentially check the
   bits within a single byte (character).
   Prints the results to screen and ensures
   the sum of the bitwise values adds up to the
   original number.
 
   Author: David Meger
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	unsigned char c = 42;
	int bit_number;
	int bit_contribution;
	int total_value = 0;

	printf( "Considering the one-byte integer %d.\n", c );

	for( bit_number=0; bit_number<8; bit_number++ )
	{
		bit_contribution = c & (1<<bit_number );

		if( bit_contribution > 0 )
			printf( "Bit number %d was 1.\n", bit_number );
		else
			printf( "Bit number %d was 0.\n", bit_number );

		printf( "bit %d of c contributes %d.\n", bit_number, bit_contribution );

		total_value += bit_contribution;
	}

	printf( "The total value of c was %d\n.", total_value );

	return EXIT_SUCCESS;
}

