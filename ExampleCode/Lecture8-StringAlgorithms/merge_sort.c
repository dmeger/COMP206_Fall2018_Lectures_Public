/* File: merge_sort.c is a simple example of one of the easiest
   O(nlgn) sorting algorithms. We break the input in half
   repeatedly until we hit pieces of size 1. Then, we begin
   to merge neighboring pieces, where merge sorts the result
   if and only if both pieces were already sorted. Since
   a piece of size 1 is automatically sorted, merge_sort
   succeeeds to sort the entire input.

   This is an example of a recursive C program that you 
   should consider as en example to help with A2.

   Autho: David Meger
*/ 

#include <stdio.h>
#define type int

// Merge is a simple algorithm that tries to shuffle pieces like a deck of cards.
int merge(  type left[], type right[], type result[], int left_size, int right_size, int result_size ){

	int pos_left=0; 
	int pos_right=0;

	for( int pos=0; pos<result_size; pos++ ){
		if( pos_right == right_size || ( pos_left < left_size && left[pos_left] < right[pos_right]) ){
			result[pos] = left[pos_left];
			pos_left++;
		}else{
			result[pos] = right[pos_right];
			pos_right++;
		}
	}
}

int merge_sort( type target[], int target_size ){

	// This is the base case that stops the recursion. Size 1 piece is returned doing nothing.
	if( target_size == 1 ){
		return 0;
	}

	// Some work to split the array in half. Make two pices and copy stuff.
	int new_size = target_size/2;
	type left[new_size];
	type right[target_size-new_size];
	for( int pos=0; pos<new_size; pos++ ){ left[pos] = target[pos]; }
	for( int pos=new_size; pos<target_size; pos++ ){ right[pos-new_size] = target[pos]; }

	// NOTE these are the key recursive call lines. Call the same function with 
        // smaller sizes, so we will definitely end up at the base case.
	merge_sort( left, new_size );
	merge_sort( right, target_size-new_size );
	merge( left, right, target, new_size, target_size-new_size, target_size );
}

int main(){

	int data[10] = { 6, 2, 100, 32, 68, 11, 20, 93, 18, 1 };
	merge_sort( data, 10 ); 
	
	for( int pos=0; pos<10; pos++ )
		printf( "%d ", data[pos] );

	printf("\n");
}
