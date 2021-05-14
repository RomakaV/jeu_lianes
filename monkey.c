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
void set_favorites(T_singeV1 m, T_int_list val){m.listeIntPreferes = val;}
