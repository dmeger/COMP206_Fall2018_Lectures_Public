/* FILE: bmp_2_white.c
 * 
 * Our first example of changing image data. 
 * Just sets it all to white.
 *
 */ 
#include <stdio.h>

int main(){

	// Open a binary bmp file
	FILE *bmpfile = fopen( "utah.bmp", "rb" );
	
	if( bmpfile == NULL ){
	  printf( "I was unable to open the file utah.bmp.\n" );
	  return -1;
	}

	// Read the overall file size 
	unsigned int overallFileSize;
	fread( &overallFileSize, 1, sizeof(unsigned int), bmpfile );
	printf( "The size was: %d.\n", overallFileSize );

	// Rewind file pointer to the beginning and read the entire contents.
	rewind(bmpfile);

	char imageData[overallFileSize];
	if( fread( imageData, 1, overallFileSize, bmpfile ) != overallFileSize ){
	  printf( "I was unable to read the requested %d bytes.\n", overallFileSize );
	  return -1;
	}

	// To modify the pixel data, we need to make sure we dont 
	// mess up the image header. Otherwise, image viewers will
	// no longer understand the file. Let's read the offset
	// and move a pointer forward.
	unsigned int* offsetp = (unsigned int*)(imageData+10);
	unsigned int offset = *offsetp;
	char *pixel_data = imageData + offset;

	// Now, indexing to pixel_data will only change the "visible"
	// data in the image. White is all of R, G and B = 255.
	// Warning! This changes the "padding" parts of the image also.
	// For A3, you will need a more sophisticated way of managing 
	// the image data.
	for( int pixel=0; pixel< overallFileSize-offset; pixel++ )
		pixel_data[pixel] = 255;

	// Time to output, just dump the binary data, inverse of reading.
	FILE* out_file = fopen( "utah_white.bmp", "wb" );
	if( out_file == NULL ){
		printf( "Unable to open utah_white.bmp for writing.\n" );
		return -1;
	}
	fwrite( imageData, 1, overallFileSize, out_file );
		
	return 0;
}

