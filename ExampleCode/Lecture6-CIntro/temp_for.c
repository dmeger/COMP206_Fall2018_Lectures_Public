/* FILE: temp_for.c
 *
 * A second version of the same functionality as temp.c to show
 * the for loop syntax in a C program
 *
 */

#include <stdio.h>
int main(){
	int fahr;
	for( fahr=0; fahr<=300; fahr = fahr + 20 )
		printf( "%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

