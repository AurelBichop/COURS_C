#include <stdio.h>
#include <stdlib.h>


int* creerAgeDynamic()
{
    int* pt = NULL;
    pt = (int*)malloc(sizeof(int));

    if(pt != NULL)
    {
        scanf("%d",pt);
    }

    return pt;
}

int main()
{
    int* p_age;

    printf("Quel est votre Age ? ");
    p_age = creerAgeDynamic();
    printf("\tVous avez %d ans",*p_age);

    free(p_age);

    return 0;
}
