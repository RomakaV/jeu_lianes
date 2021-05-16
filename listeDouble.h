#ifndef LISTEDOUBLE_H_INCLUDED
#define LISTEDOUBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct T_cell{
    struct T_cell *suiv;
    struct T_cell *prec;
    int *pdata;              //attention à faire un malloc sur ce champ avant de s'en servir
} T_cellule;
typedef T_cellule *T_liste;

void initListe(T_liste * l);
bool listeVide( T_liste l);

void afficheListeV1( T_liste l);

//Pour "AfficheListeV1" Vous avez le droit de lire directement dans la structure de données
//Utile pour afficher et debuguer les fonctions ci-dessous

T_liste ajoutEnTete(T_liste l, int mydata); //Bien mettre à NULL les champs suiv et prec non utilisés s'il y en a
void ajoutEnTetePtr2Ptr(T_liste *l, int mydata);

T_liste ajoutEnFin(T_liste l, int mydata);
T_liste ajoutEnN(T_liste l, int pos, int mydata);

T_liste suppEnTete(T_liste l);
T_liste creerListeNElem( int taille );
void tri_selection(int *tableau, int taille);
void tri_selection_liste(T_liste l);

#endif // LISTEDOUBLE_H_INCLUDED

