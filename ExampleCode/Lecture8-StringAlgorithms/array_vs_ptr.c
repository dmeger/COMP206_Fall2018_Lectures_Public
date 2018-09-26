#include <stdio.h>

int main(){

	char array[1000];

	for( int pos=0; pos<1000; pos++ ){
		array[pos] = 'a'+(pos%26);
	}	
	array[999] = '\0';
	printf( "Array holds: %s\n", array );
		
	char *ptr = "hello";
	ptr[0] = 'a';
	//for( int pos=0; pos<1000; pos++ ){
	//	ptr[pos] = 'a'+(pos%26);
	//}
	//ptr[999] = '\0';

	printf( "Ptr holds: %s\n", ptr );

}
