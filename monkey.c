#include "monkey.h"

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
void setXY(T_singeV1 m, int x, int y){m.posX = x; m.posY = y;}
void set_favorites(T_singeV1 m, T_int_list val){m.listeIntPreferes = val;}

T_liste findValidLeaf(T_jungle jungle, T_singeV1 singe){
    T_liste validLeafList = (T_liste)malloc(sizeof(struct T_cell));
    T_vine targetVine = *jungle_getN(jungle, singe.posX + 1);
    int minRange = singe.posY - 1;
    int maxRange = singe.posY + 2;

    for (int i = minRange; i <= maxRange; i++){
        int nodeValue = getN(targetVine, i);
        if (findInList(singe.listeIntPreferes, nodeValue) != -1){
            ajoutEnTete(validLeafList, i);
        }

    }
    return validLeafList;

}

T_int_list generateRandomFavorites(){
    T_int_list result = NULL;
    int ans = -1;
    for(int i = 0; i < 5; i++){
        ans = random_int(0, 9);
        if(findInList(result,ans) == (-1)){//n'est pas deja dans la liste
            ajoutTrie(result,ans);//Ajout trie dans la liste
        }
    }

    return result;
}
