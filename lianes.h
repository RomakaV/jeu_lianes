typedef struct {
    int id;
    char nom[10]; //la première lettre du nom sera affiché sur l'IHM version
    //console pour indiquer la position du singe sur une liane
    int posX; //le numéro de la liane où est le singe
    int posy; //le numéro du point d'accroche sur la liane en question
    T_liste_int listeIntPreferes; //liste d'entiers contenant les valeurs des points d'accroches possibles pour ce singe
} T_singeV1;
