#include <stdio.h>
#include <stdlib.h>
#include "listeDouble.h"#include "listeDouble_addenda.h"
#include "vines.h"#include "jungle.h"#include "monkey.h"#include "game.h"
#include "interface.h"

int main(void){//void pour s'assurer que les scanf fonctionnent parfaitement    srand(time(NULL));
    T_game game = game_alloc(prompt_maxPlayers(),prompt_boardSize());
    for(int i = 0; i < game_getPlayerCount(game); i++){
        game_addPlayer(&game, init_monkey(i,0,0, prompt_favorites()));
        printf("Player registered !\n");
    }
    if(game_getPlayerCount(game) == 0){
        printf("No player, the AI will play!\n");
        game_addPlayer(&game, init_monkey(0,0,0, generateRandomFavorites()));
        printf("Not coded yet !");
    }else{

        ///Placer les singes sur un chiffre appropire de la premiere vigne

        do{
            for(int i = 0; i < game_getPlayerCount(game); i++){

                T_singe player = game_getPlayer(game,i);

                int action = -1;
                do{
                    system("cls");
                    print_jungle(game_getJungle(game));
                    action = prompt_playerAction(player);
                }while(action < 1 && action > 5);

                switch (action){
                    case 1:
                        printf("You went up");
                        setXY(&player, getX(player) +1, getY(player) -1);
                        break;
                    case 2:
                        printf("You went in front");
                        setX(&player, getX(player)+1);
                        break;
                    case 3:
                        printf("You went down one leaf");
                        setXY(&player, getX(player) +1, getY(player) +1);
                        break;
                    case 4:
                        printf("You went down two leaves");
                        setXY(&player, getX(player) +1, getY(player) +2);
                        break;
                    case 5:
                        printf("You summoned Donkey Kong ! He sorted the leaves for you !");
                        vine_sort(jungle_getN(game_getJungle(game), getX(player)+1));
                        break;
                    default:
                        printf("Error : Unintented input !");
                        break;
                }
                scanf("%d",&action);

                if(checkMonkeyState(game_getPlayer(game, i)) == -1){
                    game_deletePlayer(&game, i);
                }
            }

            //check state a mettre ici
        }while(game.gameState == 0); //0 = running / numéro : ID du vainqueur / -1 : personne gagne
    }
    return 0;
};
