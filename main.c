#include <stdio.h>
#include <stdlib.h>

int mainEngine ();
void afficherTable(int taille, char morpion[][taille], int joueur);
int victoire (int taille, char morpion[][taille], int joueur, int i, int j);

int main () 
{
    mainEngine ();
}

/*  afficher -- ok
    choix utilisateur -- ok
        -> doit etre compris taille -1 et 0
        -> doit se faire sur une case vide
    modifie la table -- OK
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

    char morpion[taille][taille];

    /*if (choix < 3)
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
    }*/

    for (int i = 0 ; i < taille ; i++)
    {
        for (int j = 0 ; j < taille ; j++)
        {
            morpion[i][j] = ' ';
        }
    }

    afficherTable(taille, morpion, joueur);

    do // choix du joueur 
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
            scanf("%d", &choix);
        }
        y = choix;
        if (morpion[x][y] != ' ')
            printf("\nErreur : case non vide !\n");
    }while (morpion[x][y] != ' ');

    if (joueur == 0)
        morpion[x][y] = 'X';
    else if (joueur == 1)
        morpion[x][y] = 'O';
    else
        morpion[x][y] = 'J';

    if (victoire(taille, morpion, joueur, x, y))

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

int victoire (int taille, char morpion[][taille], int joueur, int i, int j)
{
    int occurence = 0;
    for (int x = 0 ; i < taille ; i++) //teste sur la ligne
    {
        if (morpion[i][x] != ' ')
        {
            if (joueur == 0 && morpion[i][x] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[i][x] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[i][x] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    occurence = 0;
    for (int x = 0 ; i < taille ; i++) //teste sur la ligne
    {
        if (morpion[i][x] != ' ')
        {
            if (joueur == 0 && morpion[i][x] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[i][x] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[i][x] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    occurence = 0;
    for (int x = 0 ; i < taille ; i++) //teste sur la ligne
    {
        if (morpion[i][x] != ' ')
        {
            if (joueur == 0 && morpion[i][x] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[i][x] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[i][x] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    occurence = 0;
    for (int x = 0 ; i < taille ; i++) //teste sur la ligne
    {
        if (morpion[i][x] != ' ')
        {
            if (joueur == 0 && morpion[i][x] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[i][x] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[i][x] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    return 0;
}