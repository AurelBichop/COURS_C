#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 100
int main()
{
    int taille_max = 100;
    int taille_liste = 3;

    char** liste_nom = NULL;
    liste_nom = (char**)malloc(taille_liste*sizeof(char*));
    if(liste_nom == NULL)
    {
        return -1;
    }

    for(int i=0;i<taille_liste;i++)
    {
        char* nom = NULL;
        nom = (char*)malloc((taille_max+1)*sizeof(char));
            if(nom == NULL)
            {
                free(liste_nom);
                return -2;
            }

            printf("indiquez le nom :");
            scanf("%s",nom);

            //adapte la taille d'allocation mémoire
            nom = realloc(nom,(strlen(nom)+1)*sizeof(char));
            if(nom == NULL)
            {
                free(liste_nom);
                return -3;
            }

            *(liste_nom+i)=nom;
    }


    for(int i=0;i<taille_liste;i++)
    {
        printf("Bonjour %s\n", liste_nom[i]);
        free(*(liste_nom+i));
    }

    free(liste_nom);

    return 0;
}
