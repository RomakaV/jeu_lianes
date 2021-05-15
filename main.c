#include <stdio.h>
#include <stdlib.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "vines.h"
#include "jungle.h"
#include "monkey.h"
#include "game.h"

#include "interface.h"

int main(void){//void pour s'assurer que les scanf fonctionnent parfaitement
    srand(time(NULL));

    T_game game = game_alloc(prompt_maxPlayers(),prompt_boardSize());
    for(int i = 0; i < game_getPlayerCount(game); i++){
        game_addPlayer(&game, init_monkey(i,0,0, prompt_favorites()));
        printf("Player registered !\n");
    }


    if(game_getPlayerCount(game) == 0){
        printf("No player, the AI will play!\n");
        game_addPlayer(&game, init_monkey(0,0,0, generateRandomFavorites()));
    }

    ///Placer les singes sur un chiffre appropire de la premiere vigne

    do{
        print_jungle(game_getJungle(game));
        for(int i = 1; i < game.playerCount; i++){
            prompt_playerAction(getN(game.players, 1);
        }





    }while(game.gameState == 0);

    int blocker = 0;
    scanf("%d", &blocker);

    return 0;
}
