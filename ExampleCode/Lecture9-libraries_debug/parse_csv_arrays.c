#include <stdio.h>

int main(){

  FILE *fp = fopen( "hurricane_data.csv", "r" );
  
  if( !fp ) return -1;
  
  fseek( fp, 0, SEEK_END );
  int size = ftell( fp );
  rewind(fp);
  
  char array[size+1];
  fread( array, 1, size+1, fp );
  
  int this_word_start=0;
  
  for( int pos=0; pos<size; pos++ ){
    if( array[pos] == ',' || array[pos] == '\n' ){
      array[pos] = '\0';
      printf( "Word was: %s\n", array+this_word_start );
      this_word_start=pos+1;
    }
  }
}
