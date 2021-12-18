#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "conf/tree.conf"
#include "mylib/mylib.h"

    int i;
    int aide = 0;//Pour savoir si l'argument help ou -help ou --help a été appeler
    DIR *rep;
    char intero = 0;//Pour les différentes options du menu
    FILE* root = NULL;
    FILE* fichier = NULL;
    char research[4096];
    int c;
    int nLignes = 0;
    int c2 = '\0';
    char aff = 'N';

void handler(int s)
{

    fichier =  fopen("RECHERCHE.txt","w+"); // w+ permet d'ouvrir le fichier et le vider
    fprintf(fichier," Recherche de \'%s\' dans %s\n", lecture(datafile), lecture(rootfile)); 
    fprintf(fichier,"\n");
    fclose(fichier);
    search(lecture(datafile));
    fichier =  fopen("RECHERCHE.txt","r");//Ouverture du fichier de résultat de recherche
    //Comptage du nombre de résultat
    while((c=fgetc(fichier)) != EOF)
    {
        if(c=='\n')
            nLignes++;
        c2 = c;
    }
    if(c2 != '\n')
	    nLignes++; 
    fclose(fichier);
    printf("Il y a %d résultats\n",(nLignes-2));
    printf("Afficher?(O / N)\n");
    scanf("%s[\n]",&aff);
    if (aff == 'O')
        afficher("RECHERCHE.txt");//Affichage du résultat si on l'a demandé
    kill (atoi(lecture(pidfile)),2);
    return;
}


int main(int argc, char **argv) 
{
    //Effacage du terminal
    system("clear");

    // etude des arguments
    if (argc>0)
    {
        for (i=1; i<argc;i++)
        {   // affichage de l'aide s'il y à l'argument help ou -help ou --help
            if ((strcmp(argv[i],"help")==0) ||(strcmp(argv[i],"-help")==0)||(strcmp(argv[i],"--help")==0))
                aide = 1;// si on tape help -help --help on n'affiche qu'une fois l'aide
            
            if ((strcmp(argv[i],"-c")==0) ||(strcmp(argv[i],"chemin")==0)||(strcmp(argv[i],"--chemin")==0))
            {
                //si le chemin a été spécifié en argument, on vérifie que celui ci existe
                rep = opendir(argv[i+1]);
                if (rep == NULL)
                {
                    perror(argv[i+1]); // permet d'afficher le code erreur si ouverture impossible
                    return 0;
                }
                //s'il existe on le met dans le fichier root.data
                root =  fopen(rootfile,"w+"); // "a" permet d'ajouter des données à la fin du fichier
                fprintf(root," %s", argv[i+1]); // ajout du chemin à la fin du fichier txt
                fclose(root);// test en fermant a la fin;
            }
        }
        if (aide == 1)
        {   //si l'aide est appelé en argument, on affiche le fichier help
            afficher(help);
            printf(" \n");
            printf(" \n");
        }
    }
    // Fin de l'étude des arguments

    //Initialisation du fichier ARBO.txt
    fichier =  fopen("ARBO.txt","w+"); // w+ permet d'ouvrir le fichier et le vider
    fclose(fichier);
    //cahrgement de l'arborescence dans ARBO.txt
    loadaf(lecture(rootfile));

    fichier = fopen(pidfile,"w+");
        fprintf(fichier," %d",getpid());
    fclose(fichier);
    signal(SIGHUP,handler) ; 
    for (;;) ;
    
    return 0;
}