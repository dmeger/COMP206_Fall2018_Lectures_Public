// This program reads in a whole file using fseek and ftell to get the size
// Then prints the AASCI code for each character in the resulting string.

#include <stdio.h>

int main(){

  FILE* fp;
  fp = fopen( "myfile.txt", "r" );
  fseek( fp, 0L, SEEK_END );
  int sz = ftell(fp);
  rewind(fp);
  
  char file_data_array[sz+1];
  fread( file_data_array, 1, sz+1, fp );
  printf( "File contents:\n%s\n", file_data_array );
  
  for( int pos=0; pos<sz+1; pos++ ){
    printf( "String character %d has AASCI value %d.\n", pos, file_data_array[pos] );
  }
  
  return 0;
}
  
