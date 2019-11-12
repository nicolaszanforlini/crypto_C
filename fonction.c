
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void crypter(char tab[50+1]){

    char carac = '\0';
    char carac_crypt = '\0';
    char perroquet[10+1];

    printf("entrer la sequence de donnees perroquet : ");
    __fpurge(stdin);
    gets(perroquet);

    FILE * fich_perroquet = NULL;
    fich_perroquet = fopen("peroq.def", "w+t");
    for(int i=0;i<strlen(perroquet);i++){
        fwrite(&perroquet[i],sizeof(perroquet[i]),1,fich_perroquet);
    }
    fclose(fich_perroquet);

    FILE * fich = NULL;
    fich = fopen(tab, "r");

    if(fich == NULL)
        printf("aucun fichier de ce nom !!!");

    else{
        printf("\nouverture du fichier...\n\n");

        FILE * fich_result = NULL;
        fich_result = fopen("dest.crt", "w+t");

        while(!feof(fich)){
            for(int i=0;i<strlen(perroquet);i++){
                    printf("\n\ntraitement de la donnee --> ");
                    fread(&carac,sizeof(carac),1,fich);
                    printf("%c avec %c //\n", carac, perroquet[i]);
                    carac_crypt = carac - perroquet[i];
                    printf("caractere crypter : %d", carac_crypt);
                    fwrite(&carac_crypt,sizeof(carac_crypt),1,fich_result);
            }
        }
        fclose(fich_result);
        fclose(fich);
    }
}

void decrypter(char tab[50+1]){

    char peroq[10+1];
    char carac = '\0';
    char carac_final = '\0';

    FILE * fich_perroquet = NULL;
    fich_perroquet = fopen("peroq.def", "r");

    if(fich_perroquet == NULL)
        printf("fichier peroq non ouvert !!!\n");
    else{printf("fichier peroq ouvert\n");}

    for(int i=0;!feof(fich_perroquet);i++){
        fread(&carac,sizeof(carac),1,fich_perroquet);
        if (!feof(fich_perroquet)){
            peroq[i] = carac;
        }
    }
    fclose(fich_perroquet);

    FILE * fich_crypt = NULL;
    fich_crypt = fopen(tab,"r");

    FILE * fich_decrypt = NULL;
    fich_decrypt = fopen("decrypt.txt", "w+t");

    while(!feof(fich_crypt)){
        for(int i=0;i<strlen(peroq);i++){
            if(!feof(fich_crypt)){
            fread(&carac,sizeof(carac),1,fich_crypt);
            printf("\ntraitement de la donnee : %d avec ---> %c", carac, peroq[i]);
            carac_final = carac + peroq[i];
            printf("\nresult = %c", carac_final);
            fwrite(&carac_final,sizeof(carac_final),1,fich_decrypt);
            }
        }
    }
    fclose(fich_crypt);
    fclose(fich_decrypt);

}







