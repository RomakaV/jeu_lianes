typedef struct {
    int id;
    char nom[10]; //la premi�re lettre du nom sera affich� sur l'IHM version
    //console pour indiquer la position du singe sur une liane
    int posX; //le num�ro de la liane o� est le singe
    int posy; //le num�ro du point d'accroche sur la liane en question
    T_liste_int listeIntPreferes; //liste d'entiers contenant les valeurs des points d'accroches possibles pour ce singe
} T_singeV1;
