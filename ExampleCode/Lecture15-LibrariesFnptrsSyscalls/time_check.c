#include <stdio.h>
#include <time.h>


int check_time( )
{
	time_t t = time(NULL);
	
	struct tm tm = *localtime(&t);

	printf("Now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  // Set up a tm struct to may 1st 2018
	tm.tm_year = 119;
	tm.tm_mon = 01;
	tm.tm_mday = 01;
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;

	time_t due_date = mktime( &tm );
  printf( "The time_t value on the due date is: %ld.\n", due_date );

	if( t < due_date )
	{
		printf( "I will not tell you the answer until after the due date:\n" );
		printf( "%d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec );
		return 0;
	}

	printf( "The answer is 42.\n" );
	
	return 0;
}
