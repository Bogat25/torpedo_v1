#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // ez számolja meg a char hosszát
#include <wchar.h>

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

  wchar_t c;

  c = getwchar();

  printf("%lc\n", c);

    pr_start();
    sc_nevek(player);
    hajo_helyvalasztas(player);
    int jatekban = 1;
    int input;
    int nyertes = -1;
    while (jatekban == 1)
    {
        input = sc_input();
        if (input == 0)
        {
            pr_elkoszones();
            return 0;
        }
        if (input == 1)
        {
            pr_tabla(player);
        }
        if (input == 2)
        {
            nyertes = hajo_loves(player);
            pr_nyertes(player[nyertes]);
            return 0;
        }
    }
    felszabaditas_jatekosok(player);
}
