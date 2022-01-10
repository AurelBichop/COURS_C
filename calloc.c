#include <stdio.h>
#include <stdlib.h>


typedef struct st_personnage
{
    int pv;
    int pm;
}Personnage;


int main()
{
    Personnage* perso = NULL;
    perso = (Personnage*)calloc(1,sizeof(Personnage));

    if(perso == NULL)
    {
        return-1;
    }


    printf("Mon Perso a %d pv et %d pm\n",perso->pv,perso->pm);

    free(perso);
    return 0;
}
