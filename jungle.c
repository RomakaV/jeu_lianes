#include "jungle.h"

T_jungle generate_jungle(int taille_jungle){
    T_jungle jungle = malloc(sizeof(T_vine) * taille_jungle);

    for (int i = 0; i < taille_jungle; i++){
        T_vine vine = generate_vine();
        jungle_addVine(&jungle, &vine);
    }
    return jungle;
}

void free_jungle(T_jungle jungle, int nbVines){
    if(jungle != NULL){
        for(int i = 0; i < nbVines; i++){
            free_vine(getN(jungle, i));
        }
        free(jungle);
    }
    return;
}

int jungle_getXY(T_jungle jungle, int x, int y){return getN(*jungle_getN(jungle, x), y);}

void jungle_addVine(T_jungle * l, T_vine * vine){
    T_jungle n = malloc(sizeof(struct T_jungle_cell));

    n->vine = vine;

    if (l==NULL){
        n->prev = NULL;
        n->next = NULL;
    }else{
        n->next = *l;
        n->prev = NULL;
        (*l)->prev = n;
    }

    *l = n;
}

T_vine * jungle_getN(T_jungle jungle, int n){
    int i = 0;
    while(jungle != NULL && i < n){
        jungle = jungle->next;

    }
    if(jungle == NULL){return NULL;}
    return jungle->vine;
}

int jungle_getLength(T_jungle jungle){
    int i =0;
    while(jungle != NULL){
        jungle = jungle->next;
        i++;
    }
    return i;
}
