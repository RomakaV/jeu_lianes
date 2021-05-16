#ifndef LISTEDOUBLE_ADDENDA_H
#define LISTEDOUBLE_ADDENDA_H

  /***************************************/
 /** Ici vont les ajouts a listeDouble **/
/***************************************/

#include <stdlib.h>

#include "listeDouble.h"

typedef T_liste T_int_list;
void free_int_list(T_int_list);

int lengthOfList(T_liste l);
void ajoutTrie(T_liste l, int val);
int getN(T_liste l, int n);
int findInList(T_liste l, int val);
#endif // LISTEDOUBLE_ADDENDA
