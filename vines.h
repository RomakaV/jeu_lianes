#ifndef VINES_H_INCLUDED
#define VINES_H_INCLUDED

#include <time.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

typedef T_int_list T_vine; // representation d'une liane

///Miscellaneous
int random_int(int min_int, int max_int);

///T_vine
T_vine generate_vine();
void free_vine(T_vine v);

void vine_addLeaf(T_vine * v, int val);

//void sort_vine(T_vine v);

#endif // VINES_H_INCLUDED
