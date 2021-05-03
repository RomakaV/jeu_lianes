#ifndef LIANES_H
#define LIANES_H

#include <stdlib.h>
#include <time.h>
#include "listeDouble.h"
typedef T_liste T_int_list;

typedef T_int_list T_vine; // representation d'une liane
typedef T_vine * T_jungle;

typedef struct {
    int id;
    char nom[10]; //la première lettre du nom sera affiché sur l'IHM version

    //console pour indiquer la position du singe sur une liane
    int posX; //le numéro de la liane où est le singe
    int posY; //le numéro du point d'accroche sur la liane en question

    T_int_list listeIntPreferes; //liste d'entiers contenant les valeurs des points d'accroches possibles pour ce singe
    // /!\ EST UN POINTEUR
} T_singeV1;

///T_singeV1
int getID(T_singeV1 m);
int getX(T_singeV1 m);
int getY(T_singeV1 m);
T_int_list get_favorites(T_singeV1 m);

void setID(T_singeV1 m, int val);
void setX(T_singeV1 m, int val);
void setY(T_singeV1 m, int val);
void set_favorites(T_singeV1 m, T_int_list val);
///Miscellaneous
int random_int(int min_int, int max_int);
///T_vine
T_vine generate_vine(T_liste liane);
//void free_vine(T_vine v);
///T_jungle
T_jungle generate_jungle(int taille_jungle);
//void free_jungle(T_jungle * j);


#endif
