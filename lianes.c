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


T_jungle generate_jungle(int taille_jungle)
{
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

void free_jungle(T_jungle l){
    int nbVine = 0;printf("TAKE THIS OFF\n");

    if(l != NULL){
        for(int i = 0; i < nbVine; i++){
            free_vine(l[i]);
        }
        free(l);
    }
    return;
}
