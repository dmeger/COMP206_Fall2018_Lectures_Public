#include <stdio.h>

int lt( char a, char b ){
	return a < b;
}

int gt( char a, char b){
	return a > b;
}

void sort( char* toSort, int (*comparison)(char,char), char max_val ){

	while( *toSort ){
		char *pos = toSort;
		char min = max_val;
		char *min_spot = NULL;
		while( *pos ){
	
			if( comparison( *pos, min ) ){
				min = *pos;
				min_spot = pos;
			}
			pos++;
		}
		if( min_spot ){
			char temp = *min_spot;
			*min_spot = *toSort;
			*toSort = temp;
		}
		toSort++;
	}
}

int main(){

	char toSort[100] = "tuiowerpjngklcadhgaioprejhalcx";
	//sort( toSort, lt, 'z' );
	sort( toSort, gt, 'a' );
	printf( "Sorted version: %s.\n", toSort );

	return 0;
}
