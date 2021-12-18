Explication des différents fichiers : 

Auteur : Aurélien GODINEAU

A la racine : 

    - treeload.c : fichier c du programme treeload
        peut avoir comme argument (Facultatif):
         -c "chemin" pour modifier le chemin de l'arborescence; 
         -help ou --help ou help pour afficher l'aide; 

    - treesearch.c : fichier c du programme treesearch
        prend comme argument (obligatoire): 
         -s ou -search ou search "fichier à chercher". Enregistre l'argument suivant 
         dans le fichier ./conf/treeload.data

Dans le dossier /conf : 

    -help.help : fichier d'aide de l'application

    -root.data : fichier contenant la racine de l'arborescence à explorer

    -tree.conf : fichier contenant différentes variables : 
        -rootfile : adresse du fichier contenant la racine de l'arborescence à explorer
        -datafile : adresse du fichier contenant la recherche à faire
        -pidfile : adresse du fichier contenant le PID du treeload en cours d'exécution
        -help : adresse du fichier help

    -treeload.date : fichier contenant la recherche à faire

    -treeload.pid : fichier contenant le PID du treeload en cours d'exécution

Dans le dossier /mylib : 

    -afficher.c : programme permettant l'affichage du contenu d'un fichier
    -lecture.c  : programme qui lit le contenu de lpremière ligne d'un fichier 
    -load       : programme permettant d'enregistrer dans le fichier ARBO.txt l'arborescence
        complete des dossiers à partir du chemin contenu dans root.data
    -loadaf     : programme permettant d'enregistrer dans le fichier ARBO.txt l'arborescence
        complete des dossiers et des fichiers à partir du chemin contenu dans root.data
    -loadf      : programme permettant d'enregistrer dans le fichier ARBO.txt l'arborescence
        complete des fichiers à partir du chemin contenu dans root.data
    -search.c   : Programme qui effectue la recherche du contenu de treeload.data dans
        l'arborescence contenu dans ARBO.txt
    

