#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int de(int nbFace)
{
    int result = (rand() % nbFace)+1;
    return result;
}

int des(int nbDes, int nbFaces)
{
    int sommeResult = 0;

    for(int i =1;i<=nbDes;i++)
    {
        sommeResult += de(nbFaces);
    }

    return sommeResult;
}


int main()
{
    int const NB_DES = 3;
    int const NB_FACES = 6;

    srand(time(NULL));

    printf("%d pour la fonction un De \n",de(6));

    printf("\tLance %d des de %d: %d", NB_DES,NB_FACES,des(NB_DES,NB_FACES));



    return 0;
}
