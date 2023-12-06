#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>

#include "defines.c"
#include "structs.c"
#include "foglalasok.c"
#include "felszabaditas.c"


int main(){
    player* players = foglalas_jatekosok();
    



    felszabaditas_jatekosok(players);
}