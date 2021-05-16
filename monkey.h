#ifndef MONKEY_H_INCLUDED
#define MONKEY_H_INCLUDED

#include <stdlib.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "jungle.h"

typedef struct {
    int id;
    char nom[10]; //la première lettre du nom sera affiché sur l'IHM version

    //console pour indiquer la position du singe sur une liane
    int posX; //le numéro de la liane où est le singe
    int posY; //le numéro du point d'accroche sur la liane en question

    T_int_list listeIntPreferes; //liste d'entiers contenant les valeurs des points d'accroches possibles pour ce singe
    // /!\ EST UN POINTEUR
} T_singeV1;

typedef T_singeV1 T_singe;

///T_singeV1
T_singeV1 * init_monkey(int id, int x, int y, T_int_list favo);

int getID(T_singeV1 m);
//char[] getName(T_singeV1 m);
int getX(T_singeV1 m);
int getY(T_singeV1 m);
void setXY(T_singeV1 * m, int x, int y);
T_int_list get_favorites(T_singeV1 m);

void setID(T_singeV1 * m, int val);
//void setName(T_singeV1 m, char v);
void setX(T_singeV1 * m, int val);
void setY(T_singeV1 * m, int val);
void set_favorites(T_singeV1  * m, T_int_list val);
T_liste findValidLeaf(T_jungle jungle, T_singeV1 singe);
T_int_list generateRandomFavorites();
int checkMonkeyState(T_game game, T_singeV1 singe);
#endif
