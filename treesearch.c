#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "./conf/tree.conf"
#include "mylib/mylib.h"

int main(int argc, char **argv) 
{
    char *PID[4096];
    int i=0;
    int aide = 0;
    FILE* root = NULL;
    FILE* fichier = NULL;
     if (argc>1)
     {
         for (i=1; i<argc;i++)
        {     
            if ((strcmp(argv[i],"-s")==0) ||(strcmp(argv[i],"-search")==0) ||(strcmp(argv[i],"search")==0)||(strcmp(argv[i],"--search")==0))
            {
                root =  fopen(datafile,"w+"); // "a" permet d'ajouter des données à la fin du fichier
                fprintf(root," %s", argv[i+1]); // ajout du chemin à la fin du fichier txt
                fclose(root);// test en fermant a la fin;
            }
        }
        kill (atoi(lecture(pidfile)),SIGHUP);
     }
     else
     {
         afficher(help);
         return 0;
     }
     return 0;
}