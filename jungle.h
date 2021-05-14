#ifndef JUNGLE_H_INCLUDED
#define JUNGLE_H_INCLUDED

#include <time.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

typedef T_int_list T_vine; // representation d'une liane
typedef T_vine* T_jungle;

///Miscellaneous
int random_int(int min_int, int max_int);

///T_vine
T_vine generate_vine(int length);
void free_vine(T_vine v);
//void sort_vine(T_vine v);

///T_jungle
T_jungle generate_jungle(int taille_jungle, int taille_vigne);
void free_jungle(T_jungle l, int nbVines);
int jungle_getXY(T_jungle jungle, int x, int y);
#endif // JUNGLE_H_INCLUDED
