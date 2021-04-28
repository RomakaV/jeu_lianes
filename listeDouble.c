#include "listeDouble.h"
//initListe ne fait pas de malloc, juste une initialisation � NULL du pointeur de liste
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
};

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
    else  // la lste n'etait pas vide, on doit donc faire les branchements
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
    //on modifie l'adresse de la t�te de la liste, soit le contenu point� par l
    *l=nouv;
};

T_liste ajoutEnFin(T_liste l, int mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    while (l.suiv != NULL) // on cherche la derni�re cellule de la liste
    {
        l = l.suiv;
    }

    // on cr�e la nouvelle cellule rattach�e � la derniere cellule de l
    nouv->suiv = NULL;
    nouv->prec = l;
    l->suiv = nouv;

    return nouv;
};

T_liste ajoutEnN(T_liste l, int pos, int mydata)
{
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    //recherche de la ni�me cellule
    T_liste lprec;
    int count = 1;
    for (count to (pos - 1), count++)
    {
        l = suiv;
        lprec = prec;
    }

    // on cr�e la nouvelle cellule rattach�e aux autres
    nouv->suiv = l;
    nouv->prec = lprec;
    lprec->suiv = nouv;
    l->prec = nouv;

    return nouv;
}

T_liste suppEnTete(T_liste l){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));

    nouv = l.suiv

    return nouv;
}
