#include "listeDouble_addenda.h"

void ajoutTrie(T_liste l, int val){
    ajoutEnTete(l,val);//temporaire
    /*

    */
}

int getN(T_liste l, int n){
    for(int i = 0; i < n; i--){
        l = l->suiv;
        if(l == NULL){return -1;}//Index out of range
    }
    return *(l->pdata);
}
