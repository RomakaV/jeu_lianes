#include <stdio.h>
#include <stdlib.h>

#include "listeDouble.h"
/*
typedef struct T_cell{
    struct T_cell *suiv;
    struct T_cell *prec;
    int *data;              //attention à faire un malloc sur ce champ avant de s'en servir
} *T_liste;
*/
//initListe ne fait pas de malloc, juste une initialisation à NULL du pointeur de liste
void initListe(T_liste *l){
*l=NULL;
}


bool listeVide( T_liste l){
    return (l==NULL);
};

void afficheListeV1( T_liste l){
    T_liste courant = l;
    while (courant!=NULL){
        printf(" %d ",*(courant->pdata));
        courant=courant->suiv;
    }
    printf("\n");
};
/*---------------------------------------------------------------------------------------*/
T_liste ajoutEnTete(T_liste l, int mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    //struct T_cell * nouv = (struct T_cell *)malloc(sizeof(struct T_cell))  //equivalent
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    if (l==NULL) // on cree en fait la premiere cellule de la liste
    {
        nouv->suiv = NULL;
        nouv->prec = NULL;
    }
    else  // la liste n'etait pas vide, on doit donc faire les branchements
    {
        nouv->suiv = l;
        nouv->prec = NULL;
        l->prec = nouv;
    }
    return nouv;
};

//dans cette version "l" est un pointeur sur le pointeur de la 1ere cellule.
void ajoutEnTetePtr2Ptr(T_liste *l, int mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    //struct T_cell * nouv = (struct T_cell *)malloc(sizeof(struct T_cell))  //equivalent
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    if (*l==NULL) // on cree en fait la premiere cellule de la liste
    {
        nouv->suiv = NULL;
        nouv->prec = NULL;
    }
    else  // la lste n'etait pas vide, on doit donc faire les branchements
    {
        nouv->suiv = *l;
        nouv->prec = NULL;
        (*l)->prec = nouv;
    }
    //on modifie l'adresse de la tête de la liste, soit le contenu pointé par l
    *l=nouv;
};
/*---------------------------------------------------------------------------------------*/
T_liste getptrFirstCell(T_liste l)
{
    T_liste courant = l;

    // bref, passer par courant est plus pédagogique
    if (listeVide(courant)) {
        if (DEBUG) printf("Erreur getptrFirstCell liste vide");
        //DEBUG est défini dans le listeDouble.h
        return courant;
    }
    else {
        while(courant->prec != NULL){
            courant=courant->prec;
        }
        return courant;
    }
};

T_liste getptrLastCell(T_liste l)
{
    T_liste courant = l;

    if (listeVide(courant)) {
        if (DEBUG) printf("Erreur getptrLastCell liste vide");
        return courant;
    }
    else {
        while(courant->suiv != NULL){
            courant=courant->suiv;
        }
        return courant;
    }
};

T_liste getptrNextCell(T_liste l)
{
    T_liste courant = l;

    if (listeVide(courant)) {
        if (DEBUG) printf("Erreur getptrNextCell liste vide");
        return courant;
    }
    else {
        courant=courant->suiv;
        return courant;
    }
};

T_liste getptrPrevCell(T_liste l)
{
    T_liste courant = l;

    if (listeVide(courant)) {
        if (DEBUG) printf("Erreur getptrNextCell liste vide");
        return courant;
    }
    else {
        courant=courant->prec;
        return courant;
    }
};

int* getPtrData(T_liste l)
{
    if (listeVide(l)) {
        if (DEBUG) printf("Erreur getPtrData liste vide");
        return NULL;  //fera planter le main
    }
    else return l->pdata;  // ptr sur notre entier stocké
};

void swapPtrData( T_liste source, T_liste destination )
{
    if (listeVide(source)||listeVide(destination)){
            if (DEBUG) printf("Erreur swapPtrData ptr = NULL");
    }
    else {  //swap
    int* tmp = source->pdata;
    source->pdata = destination->pdata;
    destination->pdata = tmp;
    }
};

T_liste creerListeNElem( int taille )
{
    T_liste l;
    initListe(&l);
    srand(time(NULL));
    for (int i=0; i<taille; i++){
        l=ajoutEnTete(l,rand()%100);
    }
    return l;
}

void tri_selection(int *tableau, int taille)
{
    int en_cours, plus_petit, j, temp;

    for (en_cours = 0; en_cours < taille - 1; en_cours++)
    {
        plus_petit = en_cours;
        for (j = en_cours ; j < taille; j++)
            if (tableau[j] < tableau[plus_petit])
                plus_petit = j;
        temp = tableau[en_cours];
        tableau[en_cours] = tableau[plus_petit];
        tableau[plus_petit] = temp;
    }
}

void tri_selection_liste(T_liste l)
{
    T_liste en_cours, plus_petit, j, fin;  //pointeurs sur cellule donc T_liste

    fin = getptrLastCell (l); //pour ne faire qu'un seul appel de cette fonction en O(n)

    //nous ne faisons ici que des branchements et déplacements de pointeurs
    for (en_cours = l; en_cours != fin; en_cours=getptrNextCell(en_cours)) //avec "en_cours != fin", nous nous arrêtons bien sur l'avant dernière cellule
    {
        plus_petit = en_cours;
        for (j = en_cours ; j != fin; j=getptrNextCell(j))
        {
            if (*getPtrData(j) < *getPtrData(plus_petit) )  //comparaison des contenus pointées (pas des pointeurs directement!)
                plus_petit = j;  //branchement de "plus_petit" sur la cellule ayant une valeur pointée par data plus petite que celle pointée par plus_petit
        }
        //comparaison avec la cellule fin non comparée dans le FOR ci-dessus
        if (*getPtrData(fin) < *getPtrData(plus_petit) ) plus_petit = fin;

        //swap
        swapPtrData(en_cours, plus_petit);
    }
}
/*---------------------------------------------------------------------------------------*/
//A vous la suite
T_liste suppEnTete(T_liste l){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));

    nouv = l->suiv;

    return nouv;
};
