#ifndef LIANES_H
#define LIANES_H

#include "listeDouble.h"
typedef T_liste T_int_list;

typedef T_int_list T_vine; // representation d'une liane

typedef struct {
    int id;
    char nom[10]; //la première lettre du nom sera affiché sur l'IHM version

    //console pour indiquer la position du singe sur une liane
    int posX; //le numéro de la liane où est le singe
    int posY; //le numéro du point d'accroche sur la liane en question

    T_int_list listeIntPreferes; //liste d'entiers contenant les valeurs des points d'accroches possibles pour ce singe
    // /!\ EST UN POINTEUR
} T_singeV1;

int getID(T_singeV1 m);
int getX(T_singeV1 m);
int getY(T_singeV1 m);
T_int_list get_favorites(T_singeV1 m);

void setID(T_singeV1 m, int val);
void setX(T_singeV1 m, int val);
void setY(T_singeV1 m, int val);
void set_favorites(T_singeV1 m, T_int_list val);

int random_int(int min, int max);
T_liste generate_liane(T_liste liane);
T_liste generate_jungle(T_liste jungle, int taille_jungle);


#endif
