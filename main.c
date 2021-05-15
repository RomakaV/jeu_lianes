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
        //jeu auto
    }

    print_jungle(game.board);

    int blocker = 0;
    scanf("%d", &blocker);

    return 0;
}
