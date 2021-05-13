#include "interface.h"

T_int_list prompt_favorites(){
    T_int_list result = NULL;

    int ans = -1;
    do{
        printf("Enter an integer your character can grab on (0~10)\nEnter -1 to finish\n");
        scanf("%d",&ans);

        if(ans >= 0 && ans <=10){
            ajoutTrie(result,ans);//Ajout trie dans la liste
        }
    }while(ans != -1);

    return result;
}

void print_monkey(T_singeV1 m){
    /**Prints the monkey's coordinates and favourites**/
    printf("Mokey is on leaf %d of vine %d\n"/*Favourites are :") */,getY(m),getX(m));
    /*afficheListeV1(get_favorites(m));*/
}

char * prompt_name(){
    char * r = malloc(10*sizeof(char));
    printf("Enter name (10 characters max)");
    scanf("%c%c%c%c%c%c%c%c%c%c",r,r+1,r+2,r+3,r+4,r+5,r+6,r+7,r+8,r+9);
    return r;
}



int prompt_int(char * str){
    int val = -1;
    printf("%s",str);
    scanf("%d",&val);
    printf("\n");
    return val;
}

int prompt_maxPlayers(){return prompt_int("Number of players : ");}
int prompt_boardSize(){return prompt_int("Number of vines in jungle : ");}
int prompt_vineSize(){return prompt_int("Number of leafs in vines : ");}
