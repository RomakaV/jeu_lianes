#ifndef INTERFACE_H
#define ITNERFACE_H

#include <stdio.h>
#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "lianes.h"

T_int_list prompt_favorites();
void print_monkey(T_singeV1 m);
char * prompt_name();

int prompt_int(char* str);

int prompt_maxPlayers();
int prompt_boardSize();
int prompt_vineSize();

void print_jungle(T_jungle jungle);

#endif // INTERFACE_H
