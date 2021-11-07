#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include "tree.conf"
#include "mylib.h"
int main(int argc, char **argv)
{
    system("clear");
    // affichage de l'aide s'il y à l'argument help ou -help ou --help
    int i;
    int aide = 0;
    if (argc>0)
    {
        for (i=1; i<argc;i++)
        {
            if ((strcmp(argv[i],"help")==0) ||(strcmp(argv[i],"-help")==0)||(strcmp(argv[i],"--help")==0))
                aide = 1;
        }
        if (aide == 1)
        {   
            afficher("help.help");
            printf(" \n");
            printf(" \n");
        }
        
    }
    char intero = 0;
    FILE* fichier = NULL;
    fichier =  fopen("ARBO.txt","w+"); // w+ permet d'ouvrir le fichier et le vider
    fclose(fichier);
    while ((intero!='1')&&(intero!='2')&&(intero!='3'))
    {
        printf("Quelques type de chargement?\n");
        printf("1 - Répertoire\n");
        printf("2 - Répertoire et fichier\n");
        printf("3 - fichier\n");
        printf("4 - Dernière recherche\n");
        scanf("%s[\n]",&intero);
        if (intero=='1') // a remplacer par case
            load(rootdir);   
        else
            if (intero=='2')
            loadaf(rootdir);
            else if (intero=='3')
                loadf(rootdir);
                else if (intero=='4')
                        {afficher("RECHERCHE.txt");
                        return 0;
                        }
                else
                    {
                        printf("Choix inconnu\n");
                       // intero = '0';
                    }
    }
    char research[4096];
    printf("Saisissez votre recherche\n");
    scanf("%s[\n]",research);
    fichier =  fopen("RECHERCHE.txt","w+"); // w+ permet d'ouvrir le fichier et le vider
    if (intero=='1')
        fprintf(fichier," Recherche de \'%s\' dans les répertoires contenu dans %s\n", research, rootdir);
    if (intero=='2')
        fprintf(fichier," Recherche de \'%s\' dans les répertoires et les fichiers contenu dans %s\n", research, rootdir);
    if (intero=='3')
        fprintf(fichier," Recherche de \'%s\' dans les fichiers contenu dans %s\n", research, rootdir);
    fprintf(fichier,"\n");
    fclose(fichier);
    search(research);
    afficher("RECHERCHE.txt");
    return 0;
}