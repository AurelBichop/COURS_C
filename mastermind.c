#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int NOMBRE_TOURS = 3;
    const int NOMBRE_COULEURS = 5;
    const char COULEUR[] = {'R','V','B','J','O'};
    const int TAILLE_CODE = 4;
    
    
    char code_a_trouver[TAILLE_CODE];
    char saisie_utilisateur[TAILLE_CODE];

    //Génération du code secret
    srand(time(NULL));
    for(int i=0;i<TAILLE_CODE;i++)
    {
        int couleur_id = rand() % NOMBRE_COULEURS;
        code_a_trouver[i] = COULEUR[couleur_id];
        printf("code secret[%d] = %c \n",i, code_a_trouver[i]);
    }    

    for(int tour_num = 1;tour_num<=NOMBRE_TOURS;tour_num++)
    {
        printf("Veuillez saisir 4 couleurs parmis (%c, %c, %c, %c, %c):\n",*(COULEUR),*(COULEUR+1),*(COULEUR+2),*(COULEUR+3),*(COULEUR+4));
        
        fflush(stdin);
        scanf("%c%c%c%c",saisie_utilisateur,(saisie_utilisateur+1),(saisie_utilisateur+2),(saisie_utilisateur+3));
        
        //init des compteurs
        int nb_couleur_place = 0;
        int nb_couleur_presente = 0;
        
        for(int i=0;i<TAILLE_CODE;i++)
        {
            short couleur_presente = 0;
            for(int j=0;j<TAILLE_CODE;j++)
            {
                if(code_a_trouver[i] == saisie_utilisateur[j])//couleur présente
                {
                    couleur_presente = 1;
                    if(i == j)
                    {
                        nb_couleur_place++;
                        break;
                    }
                }
            } 
            nb_couleur_presente += couleur_presente;
        }
    
        if(nb_couleur_place == TAILLE_CODE)
        {
            printf("GAGNE en %d tentatives \n",tour_num);
            break;
        }else if(tour_num >= NOMBRE_TOURS)
        {
            printf("Perdu \n");
            printf("Le bon code %c%c%c%c \n",code_a_trouver[0],code_a_trouver[1],code_a_trouver[2],code_a_trouver[3]);
        
        }else
        {
            printf("nombre de tentative %d / %d \n",tour_num,NOMBRE_TOURS);
            printf("Couleurs bien placées %d \n\n",nb_couleur_place);
            printf("Couleurs mal placées %d \n\n",nb_couleur_presente-nb_couleur_place);
        }
        
    }    
    
    
    return 0;
}
