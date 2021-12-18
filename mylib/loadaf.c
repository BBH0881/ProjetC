#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "mylib.h"

void loadaf(char* s)
{
    char chemin[4096];
    struct dirent *lecture;
    DIR *rep;
       
    rep = opendir(s);
    if (rep == NULL)
    {
       //perror(s); // permet d'afficher le code erreur si ouverture impossible
       return;
    }
        FILE* fichier = NULL;
        fichier =  fopen("ARBO.txt","a"); // "a" permet d'ajouter des données à la fin du fichier
                fprintf(fichier,"%s\n", s); // ajout du chemin à la fin du fichier txt
        fclose(fichier);
    while ((lecture = readdir(rep))!=NULL)
    {
        if (lecture->d_type == DT_DIR)
        {
          if (strcmp(lecture->d_name, ".")!=0 && strcmp(lecture->d_name, "..")!=0)
          { 
            strcpy(chemin, s);
            strcat(chemin,"/");
            strcat(chemin, lecture->d_name);
            loadaf(chemin);
      }
        }
        else
        {          
          strcpy(chemin, s);
          strcat(chemin,"/");
          strcat(chemin, lecture->d_name);
          fichier =  fopen("ARBO.txt","a"); // "a" permet d'ajouter des données à la fin du fichier
                 fprintf(fichier,"     %s/%s\n",s, lecture->d_name); // ajout du chemin à la fin du fichier txt
          fclose(fichier);

        }
    }
    closedir(rep);
}