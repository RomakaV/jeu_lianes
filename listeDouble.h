typedef struct T_cell{
    struct T_cell *suiv;
    struct T_cell *prec;
    int *pdata;
} T_cellule;

typedef T_cellule* T_liste;
//attention � faire un malloc sur le champ data avant de s'en servir data est donc un champ qui contiendra l�adresse de la donn�e, pas la donn�e elle-m�me.

