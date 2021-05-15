#ifndef JUNGLE_H_INCLUDED
#define JUNGLE_H_INCLUDED

#include <time.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "vines.h"

typedef struct T_jungle_cell{
    struct T_jungle_cell * prev;
    struct T_jungle_cell * next;
    T_vine               * vine;
} * T_jungle;

///T_jungle
T_jungle * generate_jungle(int taille_jungle);
void free_jungle(T_jungle jungle, int nbVines);

int jungle_getXY(T_jungle jungle, int x, int y);

void jungle_addVine(T_jungle * jungle, T_vine * vine);
T_vine * jungle_getN(T_jungle jungle, int n);
int jungle_getLength(T_jungle jungle);
#endif // JUNGLE_H_INCLUDED
