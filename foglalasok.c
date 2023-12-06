#ifndef _alma2
#define _alma2
#include <stdio.h>
#include <stdlib.h>
#include "defines.c"
#include "structs.c"

player* foglalas_jatekosok(){
    return (player*)calloc(db_jatekos , sizeof(player));
}

#endif