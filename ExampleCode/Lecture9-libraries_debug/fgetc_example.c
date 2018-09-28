#include <stdio.h>

int main(){


  int input_char;
  
  FILE *fp = fopen( "myfile.txt", "r" );
  
  while( (input_char = fgetc( fp )) != EOF ){
  
    printf( "I read the character %c.\n", input_char );
  
  }
  
  printf( "The value of EOF is %d.\n", EOF );
  
  return 0;

}
