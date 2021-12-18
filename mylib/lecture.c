#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_LENGTH 4096

char * lecture(char * fic) 
{
    
    //printf("%s\n",fic);
    FILE * inputFile = fopen( fic,"r");
    if ( inputFile == NULL ) 
    {
        printf( "root.data non existant \n");
        exit( -1 );
    }
    if (fgetc(inputFile)==EOF)
    {
            printf("Aucun résultat\n");
    }
    else
    {
    char * buffer = (char *) malloc( MAX_LENGTH );

    
        fgets( buffer, MAX_LENGTH, inputFile );
        return buffer;        
    

    free( buffer );
    fclose( inputFile );
    }
    return 0;
}