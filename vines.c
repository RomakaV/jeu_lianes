#include "vines.h"

int random_int(int min_int, int max_int){
    /**Fonction de randomisation avec bornes piquée d'un de mes vieux projets perso vive les libraries**/
    return min_int + rand() % (max_int + 1 - min_int);
}

T_vine * generate_vine(){
    T_vine * vine = malloc(sizeof(struct T_cell));
    *vine = NULL;
    int length = random_int(5,10);

    for (int i=0; i < length; i++){
        vine_addLeaf(vine, random_int(0, 9));
    }
    return vine;
}

void free_vine(T_vine l){free_int_list(l);}

void vine_addLeaf(T_vine * v, int val){
    *v = ajoutEnTete(*v,val);
}

void vine_sort(T_vine * vine){
    T_vine nouv = malloc(sizeof(struct T_cell));

    do{
        ajoutTrie(nouv, *(*vine)->pdata);
        *vine = (*vine)->suiv;
    }while((*vine)->suiv != NULL);

    free_vine(*vine);

    *vine = nouv;
};
