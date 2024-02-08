#ifndef _alma6
#define _alma6
#include "defines.c"
#include "structs.c"

void sc_nevek(players *player)
{
    printf(YELLOW_TEXT "Kerem a jatekosneveiteket.\n");
    printf(CYAN_TEXT);
    for (int i = 0; i < db_jatekos; i++)
    {
        scanf("%s", player[i].nev);
    }
    printf(RESET_TEXT);
}
int sc_input()
{
    int input = -1;
    while (input < 0 || input > 2)
    {
        printf(YELLOW_TEXT "Kerlek valassz a lehetosegek kozul.\n");
        printf(RED_TEXT "Kilepes: 0 ");
        printf(CYAN_TEXT "Tablak kiirasa: 1 ");
        printf(GREEN_TEXT "Jatek elkezdese: 2\n");
        printf(RESET_TEXT);
        while (scanf("%d", &input) != 1)
        {
            printf(RED_TEXT "Hibas bemenet.\n");
            printf(RESET_TEXT);
            while (getchar() != '\n')
                ;
        }
    }

    return input;
}
#endif