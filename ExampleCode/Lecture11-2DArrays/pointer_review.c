#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ){

	char letter = 'b';
	char sentence[100] = "2 words.";
	char *c_ptr1 = &letter;
	char *c_ptr2 = sentence;
	sentence[3] = 'i';
	c_ptr2[2] = *c_ptr1;

	printf( "letter holds: %c\n", letter );
	printf( "sentence holds: %s\n", sentence );	
	printf( "c_ptr1 holds: %c\n", *c_ptr1 );
	printf( "c_ptr2 holds: %s\n", c_ptr2 );
	
	int number = 42;
	int lotto_picks[7] = { 8, 18, 28, 38, 48, 58, 68 };
	int *i_ptr1 = &number;
	int *i_ptr2 = lotto_picks;
	lotto_picks[3] = number;
	i_ptr1 = i_ptr2;
	i_ptr2[1] = *i_ptr1;

	printf( "number holds: %d\n", number );
	printf( "lotto_picks holds:");
	for( int pos=0; pos<7; pos++ )
		printf( "%d ", lotto_picks[pos] );
	printf( "\n" );
	
	printf( "i_ptr1 holds: %d\n", *i_ptr1 );
	printf( "i_ptr2 holds:");
	for( int pos=0; pos<7; pos++ )
		printf( "%d ", i_ptr2[pos] );
	printf( "\n" );

	return 0;
}
