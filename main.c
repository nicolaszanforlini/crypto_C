
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int choix;
    char fichier_name[50+1];

    printf("\n================ MENU =================\n\n");
    printf("choix 1 : crypter un fichier\n");
    printf("choix 2 : decrypter un fichier\n\n");
    printf("entrer votre choix : ");
    __fpurge(stdin);
    choix = getchar();


    switch (choix){

    case '1' :
        printf("nom du fichier a crypter : ");
        __fpurge(stdin);
        gets(fichier_name);
        crypter(fichier_name);
        break;

    case '2' :
        printf("nom du fichier a decrypter : ");
        __fpurge(stdin);
        gets(fichier_name);
        decrypter(fichier_name);
        break;


    default :
        printf("choix invalid recommencer !!!\n");
        break;
    }


    return 0;
}
