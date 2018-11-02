#include <stdio.h>

int return5(){
	return 5;
}

void mult( int a, int b){

	printf( "%d\n", (a * b) );
}

void add( int a, int b ){

	printf( "%d\n", (a + b) );
}

void call( void(*fn)() ){

	fn( 5, 5 );
}

int main(){

	call( &add );
	call( &mult );

	int i;
	int *pi = &i;

	int (*fn)() = return5;

	*pi = return5();

	printf( "fn returned %d.\n", fn() );

	void (*p)(int, int);

	p = &add;
	p(5,5);

	p = mult;
	p(5,5);

	return 0;
}
