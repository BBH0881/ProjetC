#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_LENGTH 4096

int afficher(char * fic) 
{
    
    
    FILE * inputFile = fopen( fic,"r");
    if ( inputFile == NULL ) 
    {
        printf( "Pas d'historique \n");
        exit( -1 );
    }
    if (fgetc(inputFile)==EOF)
    {
            printf("Aucun résultat\n");
    }
    else
    {
    char * buffer = (char *) malloc( MAX_LENGTH );
    while ( ! feof( inputFile ) )
    {
        fgets( buffer, MAX_LENGTH, inputFile );
        if ( ferror( inputFile ) )
        {
            fprintf( stderr, "Reading error with code %d\n", errno );
            break;
        }
        
        printf("%s", buffer );        
    }

    free( buffer );
    fclose( inputFile );
    }
    return 0;
}