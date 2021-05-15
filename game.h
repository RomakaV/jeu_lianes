#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "vines.h"
#include "jungle.h"
#include "monkey.h"

typedef struct{
    T_singeV1 ** players;//Tableau de pointeurs de joueurs
    T_jungle * board;

    int playerCount;

    int gameState; //0 : running / 1 : plouf / 2 : ggwp
} T_game;

///T_game
T_game game_alloc(int max_p, int board_size);
//void game_free(T_game g);

T_singeV1 game_getPlayer(T_game game, int n);
T_jungle game_getJungle(T_game game);
int game_getPlayerCount(T_game game);

void game_addPlayer(T_game * game, T_singeV1 * player);
void game_removePlayer(T_game * game, int n);
void game_deletePlayer(T_game * game, int n);

//void game_setJungle(T_game * game, T_jungle * j);
void game_setplayerCount(T_game * game, int i);
#endif // GAME_H_INCLUDED
