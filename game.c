#include "game.h"

/**T_game**/
T_game game_alloc(int max_p, int board_size, int vine_size){
    T_game game;
    T_singeV1 ** playerList = malloc(max_p * sizeof(T_singeV1));

    game.players = playerList;
    for(int i = 0; i < max_p; i++){game.players[i] = NULL;}//init de la liste de joueurs vide
    game.board = generate_jungle(board_size,vine_size);

    game.playerCount = max_p;

    game.boardSize = board_size;
    game.vineSize = vine_size;

    return game;
}

void game_free(T_game game){
    /**Frees ALL memory allocated to the game (includes jungle & players)**/
    return;
}


///Game get
T_singeV1 game_getPlayer(T_game game, int n){return *(game.players[n]);}
T_jungle game_getJungle(T_game game){return game.board;}
int game_getPlayerCount(T_game game){return game.playerCount;}
int game_getJungleSize(T_game game){return game.boardSize;}
//int game_getVineLength(T_game game){return game.vineSize;}


///Game set
void game_addPlayer(T_game * game, T_singeV1 * player){

    for(int i = 0; i < game->playerCount; i++){

        if(game->players[i] == NULL){
            game->players[i] = player;

        }else if(i == (game->playerCount)-1){
            printf("ERROR : ALL PLAYER SLOTS USED (T_game>game_addPlayer)\n");
        }
    }
}
void game_removePlayer(T_game * game, int n){
    /**Removes players from player list**/
    game->players[n] = NULL;
}

void game_deletePlayer(T_game * game, int n){
    /**Frees memory of given player and removes him from the player list**/
    free(game->players[n]);
    game->players[n] = NULL;
}



//void game_setJungle(T_game * game, T_jungle * j){}
void game_setplayerCount(T_game * game, int i){game->playerCount = i;}
void game_setJungleSize(T_game * game, int i){game->boardSize = i;}
void game_setVineSize(T_game * game, int i){game->vineSize = i;}
