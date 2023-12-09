#ifndef _alma6
#define _alma6
#include "defines.c"
#include "structs.c"

void sc_nevek(players *player){
    printf(YELLOW_TEXT"Kerem a jatekosneveiteket.\n"); printf(CYAN_TEXT);
    for (int i = 0; i < db_jatekos; i++)
    {
    scanf("%s", player[i].nev);
    }
    printf(RESET_TEXT);
}

#endif