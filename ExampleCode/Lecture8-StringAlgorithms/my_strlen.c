#include <stdio.h>

int main(){

	char str_var[100] = "world";

	int length = 0;
	for( int pos=0; pos<100; pos++ ){
	
		if( str_var[pos] == '\0' ) break;
		length++;
	}
	
	printf( "The string %s has length %d.\n", str_var, length );

	return 0;
}
