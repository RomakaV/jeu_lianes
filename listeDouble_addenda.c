#include "listeDouble_addenda.h"

int lengthOfList(T_liste l){
    /**Returns the length of given list**/
    int r = 0;
    while(l != NULL){
        r++;
        l = l->suiv;
    }
    return r;
}

void ajoutTrie(T_liste l, int val){
    //Ordre croissant
    int len = lengthOfList(l);
    for(int i=0; i < len; i++){
        if(val>*(l->pdata)){
            l = l->suiv;
            ajoutEnTete(l,val);
        }
        l = l->suiv;
    }
}

int getN(T_liste l, int n){
    for(int i = 0; i < n; i++){
        l = l->suiv;
        if(l == NULL){return -1;}//Index out of range
    }
    return *(l->pdata);
}

int findInList(T_liste l, int val){
    int length = lengthOfList(l);

    for(int i = 0; i < length; i++){
        l = l->suiv;
        if(*(l->pdata) == val){return i;}
    }

    return -1;//Not found
}
