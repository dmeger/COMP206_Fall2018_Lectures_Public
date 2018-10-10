/* This code is incorrect! It illustrates the problems with keeping
   pointers to stack memory, which disappears once the function returns.

   Unless you're very lucky, you will not see hello world printed twice, 
   and it's even possible for this program to crash with segfault.
*/

#include <stdio.h>
#include <string.h>

char* f( int size ){

	char stack_array[size];
	strcpy( stack_array, "hello world" );
	return stack_array;
}

int main()
{
	char *ptr = f(20);	
	ptr[0] = 'j';
	printf( "%s\n", ptr );	
	
	char *ptr2 = f(20);			
	ptr2[0] = 'j';
	printf( "%s\n", ptr2 );
	
	return 0;
}
