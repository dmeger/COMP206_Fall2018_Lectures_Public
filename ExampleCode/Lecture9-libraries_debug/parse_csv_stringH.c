#include <stdio.h>
#include <string.h>

int main(){

  FILE *fp = fopen( "hurricane_data.csv", "r" );
  
  if( !fp ) return -1;
  
  fseek( fp, 0, SEEK_END );
  int size = ftell( fp );
  rewind(fp);
  
  char array[size+1];
  fread( array, 1, size+1, fp );
  
  char *this_word = array;
  char *word_end = strtok(array,",\n");  
  
  while( this_word != NULL ){
      printf( "Word was: %s\n", this_word );
      this_word = strtok( NULL, ",\n");
  }
}
