/* FILE: temp.c 
 *  
 * A first overview at using variables in C and while loops
 *
 * Author: David Meger
 * Date:   Sept 19, 2018
 */

#include <stdio.h>
int main(){
	int fahr, celcius;
	int lower, upper, step;

	lower=0;
	upper=300;
	step=20;
	fahr = lower;

	while( fahr <= upper ){
		celcius = 5 * (fahr-32)/9;
		printf( "%d\t%d\n", fahr, celcius);
		fahr = fahr + step;
	}
}

