#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_LISTE 5
#define TAILLE_NOM 10

#define RETURN_OK 0
#define RETURN_KO -1

typedef struct HIGHT_SCORE
{
    char nom[TAILLE_NOM];
    long score;
}hightScore;


int loadHightScore(FILE*, hightScore*);
void afficherHightScore(hightScore*);

int addHightScore(hightScore*,hightScore);
int saveHightScore(FILE*, hightScore*);

int main()
{
    char* path = "datas/HightScore.sav";
    hightScore scores[TAILLE_LISTE];

    // Ouverture du fichier
    FILE* pt_fichier = fopen(path,"r+");

    if(pt_fichier == NULL)
    {
        printf("Impossible de lire le fichier %s\n",path);
        return RETURN_KO;
    }

    // Chargement du resultat
    int resultat = loadHightScore(pt_fichier,scores);
    if(resultat == RETURN_KO)
    {
        printf("Impossible de charger les scores");
        return RETURN_KO;
    }
    //affichage du tableau
    afficherHightScore(scores);

    //ajout d'un nouveau score
    hightScore nouveau = {"TEST", 90000};
    resultat = addHightScore(scores,nouveau);
    afficherHightScore(scores);

    if(resultat == RETURN_OK)
        saveHightScore(pt_fichier, scores);

    // Fermeture de fichier
    if(fclose(pt_fichier) != 0)
    {
        printf("Impossible de fermer le fichier %s\n",path);
        return RETURN_KO;
    }

    return 0;
}


int loadHightScore(FILE* pt_fichier, hightScore* score)
{
    if(pt_fichier == NULL || score == NULL)
    {
        return RETURN_KO;
    }

    for(int i=0; i<TAILLE_LISTE;i++)
    {
        int resultat = fscanf(pt_fichier,"%s %ld", score[i].nom, &(score[i].score));

        if(resultat != 2)
        {
            strcpy(score[i].nom, "---");
            score[i].score = 0;
        }
    }

    return RETURN_OK;
}

void afficherHightScore(hightScore* score)
{
    printf("\t HIGHT SCORE \n\n");
    printf("CLASSEMENT\tNOM\tSCORE\n");
    printf("-----------------------------------\n");

    if(score == NULL)
        return;

    for(int i = 0 ; i<TAILLE_LISTE; i++)
    {
        printf("%d\t%s\t%ld\n",i+1,score[i].nom,score[i].score);
    }
}

int addHightScore(hightScore* scores,hightScore nouveau)
{
    if(scores == NULL)
        return RETURN_KO;

    printf("Votre Score Joueur %s est de %ld\n",nouveau.nom,nouveau.score);

    if(nouveau.score < scores[TAILLE_LISTE -1].score)
        return RETURN_KO;

    printf("NOUVEAU HIGHT SCORE !!! \n");

    for(int i=TAILLE_LISTE -1; i>=1; i--)
    {
        if(nouveau.score < scores[i-1].score)
        {
            strcpy(scores[i].nom,nouveau.nom);
            scores[i].score = nouveau.score;
            return RETURN_OK;
        }
        else
        {
            strcpy(scores[i].nom, scores[i-1].nom);
            scores[i].score = scores[i-1].score;
        }
    }

    //Cas de la premiere Place
    strcpy(scores[0].nom,nouveau.nom);
    scores[0].score = nouveau.score;
    return RETURN_OK;
}

int saveHightScore(FILE* pt_fichier, hightScore* scores)
{
     if(pt_fichier == NULL || scores == NULL)
    {
        return RETURN_KO;
    }

    rewind(pt_fichier);
    for(int i=0; i<TAILLE_LISTE;i++)
    {
        fprintf(pt_fichier,"%s %ld\n",scores[i].nom,scores[i].score);
    }

    return RETURN_OK;
}
