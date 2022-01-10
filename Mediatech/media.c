#include <stdio.h>
#include "media.h"

void afficherMedia(Media media)
{
    printf("   Titre: %s\n", media.titre);
    printf("   Auteur: %s\n", media.auteur);
    printf("   Type: %s\n", typeToString(media.type_media));
    printf("   Dispo: %d\n", media.nb_dispo);
}

void afficherMedias(Media* medias, int nb_media)
{
    printf("\n-------------- MEDIAS -------------------\n");
    for(int i=0; i<nb_media; i++)
    {
        printf("--- media %d\n", i+1);
        afficherMedia(*(medias+i));
    }
}

int prendreMedia(Media* media)
{
    if(media->nb_dispo <=0 )
    {
        printf("-> Desole, ce media n'est plus disponnible\n");
        return -1;
    }

    media->nb_dispo --;
    return 0;
}

void poserMedia(Media* media)
{
    media->nb_dispo ++;
}


char* typeToString(Type type)
{
    switch(type)
    {
    case TYPE_BOOK:
        return "Livre";
    case TYPE_MUSIC:
        return "Musique";
    case TYPE_MOVIE:
        return "Film";
    case TYPE_GAMES:
        return "Jeu";
    default:
        return "Inconnu";
    }
}
