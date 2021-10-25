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
    int nbr_coup = 0;

    int running = 1;
    int game_running = 1;

    while (choix < 1 || choix > 3)
    {
        printf("Combien de joueur (entre 2 et 3) ? ");
        scanf("%d", &choix);
    }

    if (choix < 3)
    { 
        taille = 3;
        nbr_joueur = choix;
    }
        else
    {
        taille = 5;
        nbr_joueur = choix;
    }

    char morpion[taille][taille];

    while(running)
    {
        for (int i = 0 ; i < taille ; i++)
        {
            for (int j = 0 ; j < taille ; j++)
            {
                morpion[i][j] = ' ';
            }
        }
        while (game_running)
        {
            afficherTable(taille, morpion, joueur);

            do // choix du joueur 
            {
                choix = -1;
                while (choix < 0 || choix > taille)
                {
                    printf("\nLigne : ");
                    scanf("%d", &choix);
                }
                x = choix - 1;

                choix = -1;
                while (choix < 0 || choix > taille)
                {
                    printf("\nColonne : ");
                    scanf("%d", &choix);
                }
                y = choix - 1;
                if (morpion[x][y] != ' ')
                    printf("\nErreur : case non vide !\n");
            }while (morpion[x][y] != ' ');

            nbr_coup++;

            if (joueur == 0)
                morpion[x][y] = 'X';
            else if (joueur == 1)
                morpion[x][y] = 'O';
            else
                morpion[x][y] = 'J';

            if (victoire(taille, morpion, joueur, x, y)) // test la victoire du joueur actuel
            {
                printf("Felicitation le joueur %d a gagne !\n", joueur + 1);
                game_running = 0;
            }

            if (nbr_coup == taille * taille)
            {
                printf("Egalite !\n");
                game_running = 0;
            }

            if (joueur != nbr_joueur - 1) // changement de joueur
                joueur++;
            else
                joueur = 0;
        }

        printf("Voulez-vous rejouer ? (1 pour oui, 0 pour non)");
        scanf("%d", &choix);

        if(choix == 0)
            running = 0;
        else
        {
            game_running = 1;
            nbr_coup = 0;
            joueur = 0;
        }
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
                printf("%c | ", morpion[i][j]);
            }
        }

        if (i != taille - 1)
        {
            printf("\n");
            for (int k = 0 ; k < taille * 3 ; k++)
                printf("-");
            printf("\n");
        }

        else
        {
            printf("\n\n");
            for (int k = 0 ; k < taille * 3 ; k++)
                printf("=");
            printf("\n");
        }
    }
}

int victoire (int taille, char morpion[][taille], int joueur, int i, int j)
{
    int occurence = 0;
    for (int x = 0 ; x < taille ; x++) //teste sur la ligne
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
    for (int x = 0 ; x < taille ; x++) //teste sur la colonne
    {
        if (morpion[x][j] != ' ')
        {
            if (joueur == 0 && morpion[x][j] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[x][j] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[x][j] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    occurence = 0;
    for (int x = 0 ; x < taille ; x++) //teste sur la diagonale haut gauche - bas droit
    {
        if (morpion[x][x] != ' ')
        {
            if (joueur == 0 && morpion[x][x] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[x][x] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[x][x] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    occurence = 0;
    for (int x = 0 ; x < taille ; x++) //teste sur la ligne
    {
        if (morpion[taille - x - 1][x] != ' ')
        {
            if (joueur == 0 && morpion[taille - x - 1][x] == 'X')
            {
                occurence++;
            }

            else if (joueur == 1 && morpion[taille - x - 1][x] == 'O')
            {
                occurence++;
            }

            else if (joueur == 2 && morpion[taille - x - 1][x] == 'J')
            {
                occurence++;
            }
        }
    }
    if (occurence == taille)
        {return 1;}

    return 0;
}