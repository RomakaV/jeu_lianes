#include <stdio.h>
#include <stdlib.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "lianes.h"
#include "interface.h"

int main()
{
    printf("Hello world!\n\n");

    /*T_singeV1 * player1;
    T_int_list favo = prompt_favorites();
    player1 = init_monkey(0,0,0,favo);*/

    T_game game = game_alloc(prompt_maxPlayers(),prompt_boardSize(),0/*prompt_vinseSize()*/);
    for(int i = 0; i < game_getPlayerCount(game); i++){
        game_addPlayer(&game, init_monkey(i,0,0, prompt_favorites()));
    }

    print_jungle(game.board, game.boardSize);

    int blocker = 0;
    scanf("%d", &blocker);

    return 0;
}
