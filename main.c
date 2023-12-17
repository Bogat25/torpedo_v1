#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <string.h> //strynghosszt szamol

#include "defines.c"
#include "structs.c"
#include "foglalasok.c"
#include "felszabaditas.c"
#include "print.c"
#include "scan.c"
#include "hajo_helyvalasztas.c"




int main(){
    players* player = foglalas_jatekosok();
    pr_start();
    sc_nevek(player);
    int jatekban = 1;
    while (jatekban == 1){
    //player[1].matrix[2][2] = 1; //teszt
    //player[0].matrix[2][2] = 3;
    hajo_helyvalasztas(player);
    pr_tabla(player);
    break; //a teszt erejéig
    }
    felszabaditas_jatekosok(player);
}

