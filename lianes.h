#ifndef LIANES_H
#define LIANES_H

#include <stdlib.h>
#include <time.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

typedef T_liste T_int_list;

typedef T_int_list T_vine; // representation d'une liane
typedef T_vine* T_jungle;

typedef struct {
    int id;
    char nom[10]; //la première lettre du nom sera affiché sur l'IHM version

    //console pour indiquer la position du singe sur une liane
    int posX; //le numéro de la liane où est le singe
    int posY; //le numéro du point d'accroche sur la liane en question

    T_int_list listeIntPreferes; //liste d'entiers contenant les valeurs des points d'accroches possibles pour ce singe
    // /!\ EST UN POINTEUR
} T_singeV1;

typedef struct{
    T_singeV1 ** players;//Tableau de pointeurs de joueurs
    T_jungle board;

    int playerCount;

    int boardSize;
    int vineSize;
} T_game;

///T_singeV1
T_singeV1 * init_monkey(int id, int x, int y, T_int_list favo);

int getID(T_singeV1 m);
//char[] getName(T_singeV1 m);
int getX(T_singeV1 m);
int getY(T_singeV1 m);
T_int_list get_favorites(T_singeV1 m);

void setID(T_singeV1 m, int val);
//void setName(T_singeV1 m, char v);
void setX(T_singeV1 m, int val);
void setY(T_singeV1 m, int val);
void set_favorites(T_singeV1 m, T_int_list val);

///Miscellaneous
int random_int(int min_int, int max_int);

///T_vine
T_vine generate_vine(T_liste liane);
void free_vine(T_vine v);
//void sort_vine(T_vine v);

///T_jungle
T_jungle generate_jungle(int taille_jungle);
void free_jungle(T_jungle l, int nbVines);
int jungle_getXY(T_jungle jungle, int x, int y);

///T_game
T_game game_alloc(int max_p, int board_size, int vine_size);
//void game_free(T_game g);

T_singeV1 game_getPlayer(T_game game, int n);
T_jungle game_getJungle(T_game game);
int game_getPlayerCount(T_game game);
int game_getJungleSize(T_game game);
//int game_getVineLength(T_game game);

void game_addPlayer(T_game * game, T_singeV1 * player);
void game_removePlayer(T_game * game, int n);
void game_deletePlayer(T_game * game, int n);

//void game_setJungle(T_game * game, T_jungle * j);
void game_setplayerCount(T_game * game, int i);
void game_setJungleSize(T_game * game, int i);
void game_setVineSize(T_game * game, int i);

#endif
