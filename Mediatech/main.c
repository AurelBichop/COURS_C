#include <stdio.h>
#include <stdlib.h>

#include "client.h"
#include "media.h"

#define NB_MEDIAS 3
#define NB_CLIENTS 2


int main()
{
    printf("TP12: Types personnalises\n");

    //liste de medias de ma mediatheque
    Media mediatheque[NB_MEDIAS] ={
        {
            "Programmer pour les Nuls grand format",
            "Olivier ENGLER et Wallace WANG",
            TYPE_BOOK,
            5
        },
        {
            "Apex legends",
            "Respawn Entertainment",
            TYPE_GAMES,
            3
        },
        {
            "MATRIX",
            "Wachowski",
            TYPE_MOVIE,
            2
        }
    };

    // liste de clients de ma mediatheque
    Client clients[NB_CLIENTS] ={
        { "Arnaud", 33, NULL },
        { "Marc", 23, NULL }
    };


    afficherMedias(mediatheque, NB_MEDIAS);


    afficherClients(clients, NB_CLIENTS);
    emprunter(clients+1, mediatheque+2);
    afficherClients(clients, NB_CLIENTS);

    return 0;
}
