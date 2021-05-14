#include "jungle.h"

/**Type T_vine**/
int random_int(int min_int, int max_int){
    /**Fonction de randomisation avec bornes piquée d'un de mes vieux projets perso vive les libraries**/
    //srand(time(NULL));
    return min_int + rand() % (max_int + 1 - min_int);
}

T_vine generate_vine(int length){
    T_vine vine = NULL;

    for (int i=0; i < length; i++){
        vine = ajoutEnTete(vine, random_int(0, 9));
    }
    return vine;
}

void free_vine(T_vine l){free_int_list(l);}


/**Type T_jungle**/
T_jungle generate_jungle(int taille_jungle, int taille_vigne){
    T_jungle jungle = malloc(sizeof(T_vine) * taille_jungle);

    for (int i = 0; i < taille_jungle; i++){
        jungle[i] = generate_vine(taille_vigne);
    }
    return jungle;
}

void free_jungle(T_jungle l, int nbVines){
    if(l != NULL){
        for(int i = 0; i < nbVines; i++){
            free_vine(l[i]);
        }
        free(l);
    }
    return;
}

int jungle_getXY(T_jungle jungle, int x, int y){return getN(jungle[x], y);}
