#include <stdio.h>
#include <stdlib.h>

int mainEngine ();
void afficherTable(int taille, char morpion[][taille], int joueur);

int main () 
{
    
}

/*  afficher -- ok
    choix utilisateur -- ok
        -> doit compris taille -1 et 0
        -> doit se faire sur une case vide
    modifie la table
    victoire
        -> si oui
            afficher la grille
            afficher nom du vainqueur
        -> si non
            change le joueur qui doit jouer
*/

int mainEngine ()
{
    int choix = 0;
    int x = -1;
    int y = -1;
    int taille = 0;
    int joueur = 0;
    int nbr_joueur = 0;

    int running = 1;

    while (choix < 1 || choix > 3)
    {
        printf("Combien de joeur (entre 1 et 3) ? ");
        scanf("%d", &choix);
    }

    if (choix < 3)
    { 
        taille = 3;
        char morpion[3][3];
        nbr_joueur = choix;
    }
        else
    {
        taille = 5;
        char morpion[5][5];
        nbr_joueur = choix;
    }

    for (int i = 0 ; i < taille ; i++)
    {
        for (int j = 0 ; j < taille ; j++)
        {
                morpion[i][j] = ' ';
        }
    }

    afficherTable(taille, morpion, joueur);

    while (morpion[x][y] != ' ')
    {
        choix = -1;
        while (choix < 0 || choix > taille - 1)
        {
            printf("\nLigne : ");
            scanf("%d", &choix);
        }
        x = choix;

        choix = -1;
        while (choix < 0 || choix > taille - 1)
        {
            printf("\nColonne : ");
            scanf("%d", &choix)
        }
        y = choix;
        if (morpion[x][y] != ' ')
            printf("\nErreur : case non vide !\n")
    }

}

void afficherTable(int taille, char morpion[][taille], int joueur)
{
    printf("Au tour du joueur numero %d :\n\n", joueur);

    for (int i = 0 ; i < taille ; i++)
    {
        for (int j = 0 ; j < taille ; j++)
        {
            if (j == taille - 1) // derniere colonne
            {
                printf("%c", morpion[i][j]);
            }

            else // toutes les colonnes sauf la derniere
            {
                printf("%c |", morpion[i][j]);
            }
        }

        if (i != taille - 1)
        {
            printf("\n --------- \n");
        }

        else
        {
            printf("\n\n===========\n");
        }
    }
}

