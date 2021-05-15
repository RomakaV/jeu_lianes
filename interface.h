#ifndef INTERFACE_H
#define ITNERFACE_H

#include <stdio.h>
#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "jungle.h"
#include "monkey.h"


void print_monkey(T_singeV1 m);
void print_jungle(T_jungle jungle);

T_int_list prompt_favorites();

int prompt_int(char* str);

int prompt_maxPlayers();
int prompt_boardSize();
int prompt_vineSize();

char * prompt_name();
void prompt_playerAction(T_singeV1 singe);
#endif // INTERFACE_H
