#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> //strynghosszt szamol

#include "defines.c"
#include "structs.c"
#include "foglalasok.c"
#include "felszabaditas.c"
#include "print.c"
#include "scan.c"
#include "hajo_helyvalasztas.c"
#include "hajo_loves.c"

int main()
{
    players *player = foglalas_jatekosok();
    pr_start();
    sc_nevek(player);
    hajo_helyvalasztas(player);
    int jatekban = 1;
    int input;
    while (jatekban == 1)
    {
        input = sc_input();
        if (input == 0)
        {
            pr_elkoszones();
            return 0;
        }
    }
    felszabaditas_jatekosok(player);
}
