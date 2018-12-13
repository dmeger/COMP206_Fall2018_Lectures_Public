/* FILE: A3_solutions.c is where you will code your answers for Assignment 3.
 * 
 * Each of the functions below can be considered a start for you. 
 *
 * You should leave all of the code as is, except for what's surrounded
 * in comments like "REPLACE EVERTHING FROM HERE... TO HERE.
 *
 * The assignment document and the header A3_solutions.h should help
 * to find out how to complete and test the functions. Good luck!
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "A3_provided_functions.h"

unsigned char*
bmp_open(     char* bmp_filename,        unsigned int *width, 
              unsigned int *height,      unsigned int *bits_per_pixel, 
              unsigned int *padding,     unsigned int *data_size, 
              unsigned int *data_offset  ){

  unsigned char *img_data=NULL;

  FILE *fp;
  if( ( fp = fopen( bmp_filename, "rb" ) ) == NULL ){
      printf( "Failed to open file %s.\n", bmp_filename );
      return NULL;
  }

  char b, m;
  fread( &b, 1, 1, fp );
  fread( &m, 1, 1, fp );

  fread( data_size, 1, sizeof(int), fp );

  rewind(fp);

  img_data = (unsigned char*)malloc(*data_size);
  
  if( img_data == NULL ){
    printf( "Error: Failed to malloc space for image of size %d.\n", *data_size );
    return img_data;
  }

  fread( img_data, 1, *data_size, fp );

  *data_offset = *((unsigned int*)(img_data+10));
  *width = *((unsigned int*)(img_data+18));
  *height = *((unsigned int*)(img_data+22));
  *bits_per_pixel = *( (unsigned short int*)(img_data+28));

  *padding = ( 4 - (*width * (*bits_per_pixel/8)) % 4) % 4;
  
  return img_data;  
}

// We've implemented bmp_close for you. No need to modify this function
void bmp_close( unsigned char **img_data ){

  if( *img_data != NULL ){
    free( *img_data );
    *img_data = NULL;
  }
}

unsigned char***  
bmp_scale( unsigned char*** pixel_array, unsigned char* header_data, unsigned int header_size,
           unsigned int* width, unsigned int* height, unsigned int num_colors,
           float scale )
{
  unsigned int new_width = *width * scale;
  unsigned int new_height = *height * scale;
  
  unsigned char*** new_pixel_array = (unsigned char***)malloc( sizeof(unsigned char**) * (new_height));
  if( new_pixel_array == NULL ){
    printf( "Error: Failed to allocate memory for image of height %d.\n", (new_height) );
    return NULL;
  }
  
  for( int row=0; row<new_height; row++ ){
    new_pixel_array[row] = (unsigned char**)malloc( sizeof(unsigned char*) * (new_width) );
    if( new_pixel_array[row] == NULL ){
      printf( "Error: Failed to allocate memory for an image row with width %d.\n", (new_width) );
      return NULL;
    }
    for( int col=0; col<new_width; col++ ){
      new_pixel_array[row][col] = (unsigned char*)malloc( sizeof(unsigned char) * (num_colors) );
      if( new_pixel_array[row][col] == NULL ){
        printf( "Error: Failed to allocate memory for an image pixel with number of colors: %d.\n", (num_colors) );
        return NULL;
      }
      for( int color=0; color<num_colors; color++ ){
        new_pixel_array[row][col][color] = pixel_array[(int)(row/scale)][(int)(col/scale)][color];
      }
    }
  }
  
  *width = new_width;
  *height = new_height;
  
  unsigned int new_padding = ( 4 - (new_width * num_colors) % 4) % 4;
  unsigned int new_row_width = (new_width*num_colors)+new_padding;
  unsigned int overall_image_size = header_size + new_height*new_row_width;

  memcpy( header_data+2, &overall_image_size, sizeof(unsigned int) );
  memcpy( header_data+18, &new_width, sizeof(unsigned int) );
  memcpy( header_data+22, &new_height, sizeof(unsigned int) );
  
  return new_pixel_array;
}         

int bmp_collage( char* background_image_filename, char* foreground_image_filename, char* output_collage_image_filename,
                 int row_offset,  int col_offset, float scale )
{
  unsigned char*   bg_img_header_data;
  unsigned int     bg_img_header_size, bg_img_width, bg_img_height, bg_img_num_colors;
  unsigned char*** bg_img_pixel_array = NULL;
  
  bg_img_pixel_array = bmp_to_3D_array( background_image_filename, &bg_img_header_data, 
                                        &bg_img_header_size,       &bg_img_width, 
                                        &bg_img_height,            &bg_img_num_colors   );
                          
  if( bg_img_pixel_array == NULL ){
    printf( "Unable to read bmp data from image file %s.\n", background_image_filename );
    return -1;
  }
  
  unsigned char*   fg_img_header_data;
  unsigned int     fg_img_header_size, fg_img_width, fg_img_height, fg_img_num_colors;
  unsigned char*** fg_img_pixel_array = NULL;
  
  fg_img_pixel_array = bmp_to_3D_array( foreground_image_filename, &fg_img_header_data, 
                                        &fg_img_header_size,       &fg_img_width, 
                                        &fg_img_height,            &fg_img_num_colors   );
                                 
  if( fg_img_pixel_array == NULL ){
    printf( "Error: Unable to read bmp data from image file %s.\n", foreground_image_filename );
    return -1;
  }
  
  fg_img_pixel_array = bmp_scale( fg_img_pixel_array, fg_img_header_data, fg_img_header_size,
                                  &fg_img_width,      &fg_img_height,     fg_img_num_colors,
                                  scale );
                                  
  if( fg_img_pixel_array == NULL ){
    printf( "Error: Call to bmp_scale failed.\n" );
    return -1;
  }

  unsigned int fg_row=0;
  for( unsigned int row=row_offset; row<row_offset+fg_img_height; row++ ){
    unsigned int fg_col=0;
    for( unsigned int col=col_offset; col<col_offset+fg_img_width; col++ ){
      if( fg_img_pixel_array[fg_row][fg_col][0] > 0 ){
        for( unsigned int color=0; color<4; color++ ){  // We are guaranteed only to work with RGBA images
          bg_img_pixel_array[row][col][color] = fg_img_pixel_array[fg_row][fg_col][color];
        }
      }
      fg_col++;
    }
    fg_row++;
  }
  
  return bmp_from_3D_array( output_collage_image_filename,          bg_img_header_data,           bg_img_header_size,     
                            bg_img_pixel_array,                     bg_img_width,  bg_img_height, bg_img_num_colors   );
}              

