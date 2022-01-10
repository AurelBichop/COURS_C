#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arme.h"
#include "personnage.h"
#include "point.h"

int main()
{
    Classe perso = CLASSE_PALADIN;
    printf("Mon personnage Paladin est de classe %d\n",perso);

    Arme baton = {"baton de verite",20.0};
    Arme epee  = {"excalibur", 10.5};

    Personnage mage = {"Merlin",10,125,CLASSE_MAGE,baton};

    Personnage guerrier;
    guerrier.pv = 50;
    guerrier.pm = 0;
    guerrier.classe = CLASSE_GUERRIER;
    strcpy(guerrier.nom,"Conan");

    equipeArme(&guerrier,epee);



    //struct st_personnage joueur = guerrier;

    afficherPersonnage(mage);
    afficherPersonnage(guerrier);



    Point pointA = {1.0,0.0};
    Point pointB = {12.2,3.0};

    printf("====Exercices des Points=====\n");

    printf("Point A: (%.2f, %.2f)\n",pointA.x,pointA.y);
    printf("Point A: (%.2f, %.2f)\n",pointB.x,pointB.y);


    printf("Distance AB: %.2f",calculateDistancePoint(pointA,pointB));


    return 0;
}
