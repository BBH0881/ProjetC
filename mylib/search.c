#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#define MAX_LENGTH 4096

int search(char *recherche) 
{
    //printf("%s\n",recherche);
    FILE* fichier = NULL;
    fichier =  fopen("RECHERCHE.txt","a"); // w+ permet d'ouvrir le fichier et le vider
    fclose(fichier);
    
    FILE * inputFile = fopen( "ARBO.txt","r");
    if ( inputFile == NULL ) 
    {
        printf( "Cannot open file \n");
        exit( -1 );
    }
    char *buffer = (char *) malloc( MAX_LENGTH );

    while ( ! feof( inputFile ) )
    {
        fgets( buffer, MAX_LENGTH, inputFile );
        if ( ferror( inputFile ) )
        {
            fprintf( stderr, "Reading error with code %d\n", errno );
            break;
        }
        if (strstr(buffer,recherche)!=NULL)
        {
        FILE* fichier = NULL;
        fichier =  fopen("RECHERCHE.txt","a"); // "a" permet d'ajouter des données à la fin du fichier
                fprintf(fichier,"%s", buffer); // ajout du chemin à la fin du fichier txt
        fclose(fichier);
        }      
        
    }

    free( buffer );
    fclose( inputFile );
        
    return 0;
}