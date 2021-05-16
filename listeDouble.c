#include "listeDouble.h"
//initListe ne fait pas de malloc, juste une initialisation à NULL du pointeur de liste
void initListe(T_liste *l){
*l=NULL;
};


bool listeVide( T_liste l){
    return (l==NULL);
};

void afficheListeV1( T_liste l){
    int index = 0;
    while (l != NULL){
        printf("[%d] : %d\n",index,*(l->pdata));
        l = l->suiv;
        index++;
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
    //on modifie l'adresse de la tête de la liste, soit le contenu pointé par l
    *l=nouv;
};

T_liste ajoutEnFin(T_liste l, int mydata){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));
    *(nouv->pdata)=mydata;

    while (l->suiv != NULL) // on cherche la dernière cellule de la liste
    {
        l = l->suiv;
    }

    // on crée la nouvelle cellule rattachée à la derniere cellule de l
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

    //recherche de la nième cellule
    T_liste lprec;

    for(int count = 1; count <= pos; count++)
    {
        l = l->suiv;
        lprec = l->prec;
    }

    // on crée la nouvelle cellule rattachée aux autres
    nouv->suiv = l;
    nouv->prec = lprec;
    lprec->suiv = nouv;
    l->prec = nouv;

    return nouv;
};

T_liste suppEnTete(T_liste l){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));

    nouv = l->suiv;

    return nouv;
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

T_liste suppEnTete(T_liste l){
    T_liste nouv = (T_liste)malloc(sizeof(struct T_cell));
    nouv->pdata = (int*)malloc(sizeof(int));

    nouv = l->suiv;

    return nouv;
};
