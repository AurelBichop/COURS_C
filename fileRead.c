#include<stdio.h>
#include<stdlib.h>

#define TAILLE_TAB 100

int main(){
    FILE* pt_fichier = fopen("hello.txt","r");

    if(pt_fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier");
        return -1;
    }

    char lecture[TAILLE_TAB];
    char* retour;

    while(retour != NULL){
        printf("%s",lecture);
        retour = fgets(lecture,TAILLE_TAB,pt_fichier);
    };

    int resultat = fclose(pt_fichier);
    if(resultat != 0)
    {
        printf("Erreur lors de la fermeture du fichier");
        return -2;
    }

    return 0;
}
