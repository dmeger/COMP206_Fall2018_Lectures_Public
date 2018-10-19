#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  char a[4];
  memset( a, '\0', 4 );
  int *p = (int*)a;
  
  printf( "The value of *p is %d.\n", *p );
  
  return 0;
}
