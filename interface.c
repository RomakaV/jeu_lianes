#include "interface.h"

///Prints
void print_monkey(T_singeV1 m){
    /**Prints the monkey's coordinates and favourites**/
    printf("Monkey is on leaf %d of vine %d\nFavourites are :",getY(m),getX(m));
    afficheListeV1(get_favorites(m));
}

void print_jungle(T_jungle jungle){
    int i =0;
    while(jungle != NULL){
        printf("--Vine %d\n",i);
        afficheListeV1(jungle->vine);
        i++;
    }
    printf("End of jungle");
}

///Prompts
T_int_list prompt_favorites(){
    T_int_list result = NULL;

    int ans = -1;
    do{
        printf("Enter an integer your character can grab on (0~10)\nEnter -1 to finish\n");
        scanf("%d",&ans);

        if(ans >= 0 && ans <=10 && findInList(result,ans) == (-1)){//Entre 0 et 10, n'est pas deja dans la liste
            ajoutTrie(result,ans);//Ajout trie dans la liste
        }
    }while(ans != -1);

    return result;
}

int prompt_int(char * str){
    int val = -1;
    printf("%s",str);
    scanf("%d",&val);
    printf("\n");
    return val;
}

int prompt_maxPlayers(){
    int ans = -1;
    do{
        ans = prompt_int("Number of players : ");
    }while(ans<0);
    return ans;
}
int prompt_boardSize(){
    int ans = -1;
    do{
        ans = prompt_int("Number of vines in jungle : ");
    }while(ans<=0);
    return ans;
}

char * prompt_name(){
    char * r = malloc(10*sizeof(char));
    printf("Enter name (10 characters max)");
    scanf("%c%c%c%c%c%c%c%c%c%c",r,r+1,r+2,r+3,r+4,r+5,r+6,r+7,r+8,r+9);
    return r;
}
