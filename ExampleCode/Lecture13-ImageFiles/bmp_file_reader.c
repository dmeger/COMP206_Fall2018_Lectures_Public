/* FILE: bmp_file_reader.c
 * 
 * Uses the binary file reading toolkit such as fopen with "rb"
 * and fread rather than the string-based operations like fgets.
 * This is so that we dont have to worry about special characters 
 * in the file and ensure we get all the header bytes.
 *
 * It should be a helpful start for Assignment 3 Question 1.
 */ 

#include <stdio.h>

int main(){

	// Open a binary bmp file
	FILE *bmpfile = fopen( "utah.bmp", "rb" );

	// Read the B and M characters into chars
	char b, m;
	fread (&b,1,1,bmpfile);
	fread (&m,1,1,bmpfile);

	// Print the B and M to terminal
	printf( "The first byte was: %c.\n", b );
	printf( "The second byte was: %c.\n", m );

	// Read the overall file size 
	unsigned int overallFileSize;
	fread( &overallFileSize, 1, sizeof(unsigned int), bmpfile );
	printf( "The size was: %d.\n", overallFileSize );

	// Close the file, re-open it to be at the beginning, and read the entire contents
	fclose(bmpfile);
	bmpfile = fopen("utah.bmp", "rb" );

	char imageData[overallFileSize];
	fread( imageData, 1, overallFileSize, bmpfile );
     
	// Read the width size into unsigned int (hope = 500 since this is the width of utah.bmp)
        unsigned int* wp = (unsigned int*)(imageData+18);
	unsigned int width = *wp;

	// Print the width size to terminal	
	printf( "The width is: %d.\n", width );
	
	return 0;
}
