#include "lianes.h"

int getID(T_singeV1 m){return m.id;}
int getX(T_singeV1 m){return m.posX;}
int getY(T_singeV1 m){return m.posY;}
T_int_list get_favorites(T_singeV1 m){return m.listeIntPreferes;}

void setID(T_singeV1 m, int val){m.id = val;}
void setX(T_singeV1 m, int val){m.posX = val;}
void setY(T_singeV1 m, int val){m.posY = val;}
void set_favorites(T_singeV1 m, T_int_list val){m.listeIntPreferes = val;}

// Fonction de randomisation avec bornes piquée d'un de mes vieux projets perso vive les libraries
int random_int(int min, int max)
{
    srand(time(NULL));
    return min + rand() % (max + 1 - min);
};

T_liste generate_liane(T_liste liane)
{
    int taille_liane = random_int(4, 10);
    int mydata1 = random_int(0, 9);
    ajoutEnTete(liane, mydata1);

    int i = 2;

    for (i to taille_liane, i++)
    {
        int mydata2 = random_int(0, 9);
        ajoutEnFin(liane, mydata2);
    }
    return liane;
}

T_liste generate_jungle(T_liste jungle, int taille_jungle)
{
    for (int i = 1 to taille_liane, i++)
    {
        T_liste liane;
        initListe(liane);
        jungle->pdata = generate_liane(liane);
        int mydata = random_int(0, 9);
        ajoutEnFin(liane, mydata);
    }
    return liane;
}
