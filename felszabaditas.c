#ifndef _alma1
#define _alma1
#include <stdio.h>
#include "defines.c"
#include "structs.c"

void felszabaditas_jatekosok(player* players){
    free(players);
}


#endif