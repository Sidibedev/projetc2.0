#include <stdio.h>
#include <stdlib.h>

#include "header.h"
// les fonctions d'ajout de suppression etc seront ajoute ici


int main(int argc, char *argv[])
{
    FILE* fichier = NULL;
    fichier = fopen("C:\\Users\\HP\\Desktop\\INFORMATIQUE\\Licence\\I Fall\\Langage C\\projet-c-master\\projet-c-master\\fichier\\membres.xls", "w");

    if (fichier != NULL)
    {
        //void ajouter_membre_menu();
        void insertion(listechaine *Liste, Membre nvMembre);
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Impossible d'ouvrir le fichier test.txt");
    }
    return 0;
}

