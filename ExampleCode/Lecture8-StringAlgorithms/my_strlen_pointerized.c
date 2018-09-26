#include <stdio.h>

int main(){

	char str_var[100] = "world";

	int length = 0;
	char *ptr = str_var;

	while( *ptr ){
		ptr++;
		length++;
	}
	
	printf( "The string %s has length %d.\n", str_var, length );

	return 0;
}
