#include <stdio.h>
#include <stdlib.h>

/*
int* creerAge()
{
    int age = 33;
    return &age;
}
*/

int* creerAgeDynamic()
{
    int* pt = NULL;
    pt = (int*)malloc(sizeof(int));

    if(pt != NULL)
    {
        *pt= 33;
    }

    return pt;
}


int* libereMemoire(int* pt)
{

    if(pt != NULL)
    {
        free(pt);
    }

    return pt;
}

int main()
{

    int* p_age = NULL;
    p_age = creerAgeDynamic();

    if(p_age == NULL)
    {
            printf("Erreur d'allocation memoire");
    }
    else
    {
        printf("Age = %d\n",*p_age);
        libereMemoire(p_age);
    }

    return 0;
}
