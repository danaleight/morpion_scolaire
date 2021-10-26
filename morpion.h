#ifndef _MORPION_H_
#define _MORPION_H_

int mainEngine ();
void afficherTable(int taille, char morpion[][taille], int joueur);
int victoire (int taille, char morpion[][taille], int joueur, int i, int j);

#endif