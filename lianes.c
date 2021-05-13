#include "lianes.h"


/**Type T_int_list**/


void free_int_list(T_int_list l){
    while(l != NULL){
        l = suppEnTete(l);
    }

    free(l);
}

/**Type T_singeV1**/

T_singeV1 * init_monkey(int id, int x, int y, T_int_list favo){
    T_singeV1 * m = malloc(sizeof(T_singeV1));
    setID(*m,id);
    setX(*m,x);
    setY(*m,y);
    set_favorites(*m,favo);
    return m;
}

int getID(T_singeV1 m){return m.id;}
int getX(T_singeV1 m){return m.posX;}
int getY(T_singeV1 m){return m.posY;}
T_int_list get_favorites(T_singeV1 m){return m.listeIntPreferes;}

void setID(T_singeV1 m, int val){m.id = val;}
void setX(T_singeV1 m, int val){m.posX = val;}
void setY(T_singeV1 m, int val){m.posY = val;}
void set_favorites(T_singeV1 m, T_int_list val){m.listeIntPreferes = val;}


/**Type T_vine**/


int random_int(int min_int, int max_int){
    /**Fonction de randomisation avec bornes piquée d'un de mes vieux projets perso vive les libraries**/
    srand(time(NULL));
    return min_int + rand() % (max_int + 1 - min_int);
};

T_vine generate_vine(T_vine liane){
    int taille_liane = random_int(4, 10);
    int mydata1 = random_int(0, 9);
    ajoutEnTete(liane, mydata1);

    for (int i=2; i < taille_liane; i++)
    {
        int mydata2 = random_int(0, 9);
        ajoutEnFin(liane, mydata2);
    }
    return liane;
}

void free_vine(T_vine l){free_int_list(l);}


/**Type T_jungle**/


T_jungle generate_jungle(int taille_jungle){
    T_jungle jungle = malloc(sizeof(T_vine) * taille_jungle);


    for (int i = 0; i < taille_jungle; i++)
    {
        T_vine liane;
        initListe(&liane);
        jungle[i] = generate_vine(liane);

        int mydata = random_int(0, 9);
        ajoutEnFin(liane, mydata);
    }
    return jungle;
}

void free_jungle(T_jungle l, int nbVines){
    if(l != NULL){
        for(int i = 0; i < nbVines; i++){
            free_vine(l[i]);
        }
        free(l);
    }
    return;
}


/**T_game**/


T_game game_alloc(int max_p, int board_size, int vine_size){
    T_game game;
    T_singeV1 ** playerList = malloc(max_p * sizeof(T_singeV1));

    game.players = playerList;
    for(int i = 0; i < max_p; i++){game.players[i] = NULL;}//init de la liste de joueurs vide
    game.board = generate_jungle(board_size);

    game.playerCount = max_p;

    game.boardSize = board_size;
    //game.vineSize = vine_size;

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
