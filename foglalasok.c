#ifndef _alma2
#define _alma2
#include <stdio.h>
#include <stdlib.h>
#include "defines.c"
#include "structs.c"

players* foglalas_jatekosok(){
    return (players*)calloc(db_jatekos , sizeof(players));
}

hajok* foglalas_hajok(){
    return (hajok*)calloc(1,sizeof(hajok));
}

#endif