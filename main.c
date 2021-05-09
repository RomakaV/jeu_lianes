#include <stdio.h>
#include <stdlib.h>

#include "listeDouble.h"
#include "listeDouble_addenda.h"

#include "lianes.h"
#include "interface.h"

int main()
{
    printf("Hello world!\n\n");

    T_singeV1 * player1;
    T_int_list favo = prompt_favorites();
    player1 = init_monkey(0,0,0,favo);


    return 0;
}
