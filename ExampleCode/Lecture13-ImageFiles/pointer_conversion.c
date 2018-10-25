#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  char a[4];
  memset( a, '\0', 4 );
  a[0] = 'a';
  int *p = (int*)a;
  
  printf( "The value of *p is %d.\n", *p );

  int i = 257;
  char *cp = (char*)&i;

  printf( "The value of *cp is %d.\n", *cp );
  
  return 0;
}
