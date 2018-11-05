#include <stdio.h>

struct student{

  char name[100];
  char grade;
  long int student_id;
};

int main(){

  struct student dave = { "Dave", '?', 2600000000 };
  
  printf( "The struct entries are:\n name: %s\n grade: %c\n student_id: %ld\n", dave.name, dave.grade, dave.student_id );
  
  printf( "The size of the struct is %ld.\n", sizeof(struct student) );
  
  printf( "The addresses fields relative to the struct are:\n full struct: %ld\n name: %ld\n grade: %ld\n student_id: %ld\n",
            (long int)&dave - (long int)&dave, (long int)&(dave.name) - (long int)&dave, (long int)&(dave.grade) - (long int)&dave, (long int)&(dave.student_id) - (long int)&dave );
  
  return 0;

}

