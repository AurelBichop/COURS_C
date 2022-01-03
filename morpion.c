#include <stdio.h>
#include <stdlib.h>

void dessinnerGrille(char grille[][3]);
int saisieValide(char grille[][3], int coord_x,int coord_y);
void saisieUtilisateur(char grille[][3],char joueur, int* p_coord_x,int* p_coord_y);

int victoire(char grille[][3],char joueur);
int grillePleine(char grille[][3]);

int main()
{
    printf("Jeux de morpions\n");
    char grille[3][3] =
    {
        {'.','.','.'},
        {'.','.','.'},
        {'.','.','.'}
    };

    int fin_de_partie = 0;
    char joueur = 'X';
    int coord_x,coord_y;

    do
    {
        dessinnerGrille(grille);
        saisieUtilisateur(grille,joueur, &coord_x,&coord_y);

        if(victoire(grille,joueur))
        {
            printf("Le joueur %c a gagne !!!\n",joueur);
            dessinnerGrille(grille);
            fin_de_partie = 1;
        }
        else if(grillePleine(grille))
        {
            printf("Match NULL :-( \n");
            dessinnerGrille(grille);
            fin_de_partie = 1;
        }
        else
        {
            if(joueur == 'X') joueur= 'O';
            else joueur = 'X';
        }


    }while(fin_de_partie != 1);

    return 0;
}


void dessinnerGrille(char grille[][3])
{
    for(int x=0; x <3;x++)
    {
        printf("|%c|%c|%c|\n",grille[x][0],grille[x][1],grille[x][2]);
    }

}

void saisieUtilisateur(char grille[][3],char joueur, int* p_coord_x,int* p_coord_y)
{
    do
    {
        printf("Joueur %c ou Voulez vous jouer (x,y) ? :",joueur);

        fflush(stdin);
        scanf("%d %d",p_coord_x,p_coord_y);
    }while(saisieValide(grille,(int)*p_coord_x,(int)*p_coord_y) == 0);
    grille[*p_coord_x][*p_coord_y] = joueur;
}

int saisieValide(char grille[][3], int coord_x,int coord_y)
{
    if(coord_x < 0 || coord_x >=3 || coord_y < 0 || coord_y >=3 )
    {
        printf("Coordonnes Invalide\n");
        return 0;
    }

    if(grille[coord_x][coord_y] != '.')
    {
        printf("Case deja prise!\n");
        return 0;
    }

    return 1;
}

int victoire(char grille[][3],char joueur)
{
    // Test  des lignes
    for(int x=0; x<3; x++)
    {
        if(grille[x][0] == joueur && grille[x][1] == joueur && grille[x][2] == joueur)
            return 1;
    }

    // Test  des colonnes
    for(int y=0; y<3; y++)
    {
        if(grille[0][y] == joueur && grille[1][y] == joueur && grille[2][y] == joueur)
            return 1;
    }

    //Test des diagonales
    if(grille[0][0] == joueur && grille[1][1] == joueur && grille[2][2] == joueur)
        return 1;
    if(grille[2][0] == joueur && grille[1][1] == joueur && grille[0][2] == joueur)
        return 1;


    return 0;
}

int grillePleine(char grille[][3])
{
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            if(grille[x][y] == '.') return 0;
        }
    }

    return 1;
}
