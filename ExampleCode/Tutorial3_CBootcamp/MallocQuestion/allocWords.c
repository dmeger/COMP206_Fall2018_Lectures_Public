#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** allocWords( int numWords, int wordLengths[] ){

        // FILL IN FROM HERE
        //
        // TO HERE... so that the rest of hte program works!
}

int main( int argc, char *argv[] ){

        int wordLengths[argc-1];
        for( int word=1; word<argc; word++ ){
                wordLengths[word] = strlen(argv[word]);
        }

        char** wordArray = allocWords( argc-1, wordLengths );

        if( wordArray == NULL ){
                printf( "wordArray was NULL. Still need to finish function?\n" );
                return 0;
        }

        for( int word=1; word<argc; word++ ){
                strcpy( wordArray[word-1], argv[word] );
        }

        for( int word=1; word<argc; word++ ){
                printf( "Word %d is %s.\n", word, wordArray[word-1] );
        }

        return 0;
}
