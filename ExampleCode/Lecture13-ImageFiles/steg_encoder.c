/* The file steg_encoder.c
   is a larger systems example to demonstrate
   input, output and memory manipulation in C.
   
   Build this file with: 
   gcc -o encoder steg_encoder.c
   
   When both this, and the paired decoder are compiled, 
   then you can pass a message using a bmp file with these commands:
   
   $ ./encoder mario_16_bit.bmp mario_message.bmp Your Message Here.
   $ ./decoder mario_message.bmp
   
   Make sure to view the original mario bitmap and the 
   mario_message file to verify that you cannot visually detect the change.
  
   Author: David Meger
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[] )
{
  const int bmp_header_size = 54;
  const int max_msg_size = 1000;
  int i;
  int curr_message_position=0;
  int read_code;
  int msg_idx = 0;
  int img_idx = 0;
  int bit_idx = 0;
  char c;
  char msg[max_msg_size];
  FILE *img_in = NULL;
  FILE *img_out = NULL;
  
  if( argc < 4 ){
    printf( "Usage: %s source_bmp output_bmp message.\n", argv[0] );
    return 1;
  }
  
  img_in = fopen( argv[1], "rb" );
  if( img_in == NULL ){
    printf( "Could not open the input image file.\n" );
    return 1;
  }

  img_out = fopen( argv[2], "wb" );
  if( img_out == NULL ){
    printf( "Could not open the output file.\n" );
    return 1;
  }  

  // This for loop is specific to the way the encoder puts the entire sentence 
  // typed on the command-line into the image as a single string. 
  // We loop over the arguments, which each hold one word of the sentence
  // and build up msg, placing spaces as appropriate. At its end, msg
  // holds the correct string we want to encode.
  for( i=3; i<argc; i++ ){
    strcpy( msg+curr_message_position, argv[i] );
    curr_message_position += strlen(argv[i]);

    if( i<argc-1 )
      msg[curr_message_position] = ' ';
      curr_message_position++;
  }
  msg[curr_message_position] = '\0';
  
  // This while loop is the main place where steganography encoding happens.
  // The bits of msg are woven into the lowest-order bit in each byte of the image
  while( ( read_code = fgetc( img_in )) != EOF ){
    c = (char)read_code; // c holds the original pixel value

    // We must not modify the first 54 bytes of the image, because its 
    // a special "header" rather than actual image data. So it is not safe
    // to modify even one of these bits. 
    if( img_idx >= bmp_header_size && msg_idx <= strlen( msg ) ){ 
    
      // bit_mask will have exactly one "1" bit and seven "0" bits
      // See the lecture slides on bit-wise operations for details
      char bit_mask = 1 << bit_idx;
      
      // Use bit_mask to probe the appropriate bit in the message.
      // If it is 1, then use the OR operation to set the lowest-order
      // bit of c to 1. If it is 0, then use the AND operation to set the
      // lowest-order bit of c to 0. Again, details in the class slides.
      if( ( msg[msg_idx] & bit_mask) > 0 )
        c |= 1;
      else
        c &= 254;

      // Move the bit index forward 
      bit_idx++;

      // When we complete all 8 bits in a byte, move to the next byte
      if( bit_idx >= 8 ){
        bit_idx = 0;
        msg_idx++;
      }      
    }

    // Always write the resulting c value to the output file. Note that this will
    // sometimes be an exact copy from img_in (like for the header, or when we're
    // past the end of our string), and sometimes we'll have modified c with 
    // bits from the message.
    fputc( c, img_out );
    img_idx++;
  }

  printf( "I have hidden the secret within an image of %d bytes.\n", img_idx );

  fclose(img_in);
  fclose(img_out);

  return 0;
}
