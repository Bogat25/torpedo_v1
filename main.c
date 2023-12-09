#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>

#include "defines.c"
#include "structs.c"
#include "foglalasok.c"
#include "felszabaditas.c"
#include "print.c"



int main(){
    players* player = foglalas_jatekosok();
    pr_start();
    player[1].matrix[2][2] = 1; //teszt
    player[0].matrix[2][2] = 3; 
    pr_tabla(player);

    felszabaditas_jatekosok(player);
}

