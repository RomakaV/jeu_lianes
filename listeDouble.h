typedef struct T_cell{
    struct T_cell *suiv;
    struct T_cell *prec;
    int *pdata;
} T_cellule;

typedef T_cellule* T_liste;
//attention à faire un malloc sur le champ data avant de s'en servir data est donc un champ qui contiendra l’adresse de la donnée, pas la donnée elle-même.

