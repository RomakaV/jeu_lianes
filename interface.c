#include "interface.h"

T_int_list prompt_favorites(){
    T_int_list result = NULL;

    int ans = -1;
    do{
        printf("Enter an integer your character can grab on (0~10)\nEnter -1 to finish\n");
        scanf("%d",&ans);

        if(ans >= 0 && ans <=10){
            ajoutTrie(result,ans);///Ajout trié dans la liste
        }
    }while(ans != -1);

    return result;
}

void print_monkey(T_singeV1 m){
    /**Prints the monkey's coordinates and favourites**/
    printf("Mokey is on leaf %d of vine %d\n"/*Favourites are :") */,getY(m),getX(m));
    /*afficheListeV1(get_favorites(m));*/
}
