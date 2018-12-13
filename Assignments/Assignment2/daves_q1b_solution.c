#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef DEBUG
  const char space = '#';
#else  
  const char space = ' ';
#endif 

int sierpinski_row( int row, int height, int level ){

  int width = 2*height - 1;
  
	if( level == 0 ){
	
	    int this_width = (row+1) * 2 - 1;
        int this_spaces = ( width - this_width ) / 2 ;

    for( int pos=0; pos<this_spaces; pos++ )
      printf( "%c", space );
	
    for( int pos=0; pos<this_width; pos++ )
      printf( "*" );
        
    for( int pos=0; pos<this_spaces; pos++ )
      printf( "%c", space);
        
	  return 0;
	}
	
	if( row < height/2 ){
	  for( int pos=0; pos<height/2; pos++ )
        printf( "%c", space );
    sierpinski_row( row, height/2, level-1 );
 	  for( int pos=0; pos<height/2; pos++ )
        printf( "%c", space );
  }
  else{
    sierpinski_row( row-width/4-1, height/2, level-1 );
    printf( "%c", space );
    sierpinski_row( row-width/4-1, height/2, level-1 );  
  }
    
	return 0;
}

int main( int argc, char *argv[] ){

	int height = atoi(argv[1]);
	int level = atoi(argv[2]);
	int width = height;
    height = height / 2 + 1;

    if( (height % (1 << (level-1)) ) != 0 ){
        printf( "ERROR: Height does not allow evenly dividing requested number of levels.\n" );
        return 1;
    }

	for( int row=0; row<height; row++ ){
		sierpinski_row( row, height, level-1 );
		printf( "\n" );
	}
	for( int row=height-2; row>=0; row-- ){
		sierpinski_row( row, height, level-1 );
		printf( "\n" );
	}

	return 0;
}
	
