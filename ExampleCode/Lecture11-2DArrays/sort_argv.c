#include <stdio.h>
#include <string.h>

int main( int argc, char *argv[] ){

	// Consider one argument at a time
	for( int pos=0; pos<argc; pos++ ){

		// Find the "first" word alphabetically from here on
		char *current_min = argv[pos];
		int min_pos = -1;		
		for( int pos2=pos+1; pos2<argc; pos2++ ){
			// Recall, str1 < str2 not OK, need strcmp
			if( strcmp( argv[pos2], current_min ) < 0 ){ 
				current_min = argv[pos2];
				min_pos = pos2;
			}
		}

		// If the initial min changed, we found a word out of order, swap 
		if( current_min != argv[pos] ){
			char *temp = argv[pos];
			argv[pos] = current_min;
			argv[min_pos] = temp;
		}
	}

	// Print the result, should be sorted!
	for( int pos=0; pos<argc; pos++ )
		printf( "%s\n", argv[pos] );

	return 0;
}
			
