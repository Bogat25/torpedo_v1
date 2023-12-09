#ifndef _alma4
#define _alma4
#include "defines.c"

void pr_start()
{
    printf(YELLOW_TEXT "Udvozollek a torpedoban.\n");
    printf(RESET_TEXT);
}

void pr_terkoz()
{
    for (int i = 0; i < terkoz; i++)
    {
        printf(" ");
    }
}
void pr_tabla(players *player)
{
    printf("%s", player[0].nev);
    int nev_hossz = strlen(player[0].nev); // szoköz a playerek nevei között
    for (int i = 0; i < tabla_meret + 2 * terkoz - nev_hossz; i++)
    {
        printf(" ");
    }

    printf("%s", player[1].nev);
    printf("\n");
    printf("  "); // 1. player
    for (int i = 0; i < tabla_meret; i++)
    {
        printf(CYAN_TEXT "%d ", i + 1);
        printf(RESET_TEXT);
    }
    pr_terkoz();
    printf("  "); // 2. player
    for (int i = 0; i < tabla_meret; i++)
    {
        printf(CYAN_TEXT "%d ", i + 1);
        printf(RESET_TEXT);
    }

    printf("\n");
    for (int i = 0; i < tabla_meret; i++)
    {
        printf(YELLOW_TEXT "%d ", i + 1);
        printf(RESET_TEXT); // 1. player
        for (int n = 0; n < tabla_meret; n++)
        {
            printf("%d ", player[0].matrix[i][n]);
        }
        pr_terkoz();
        printf(YELLOW_TEXT "%d ", i + 1);
        printf(RESET_TEXT); // 2. player
        for (int n = 0; n < tabla_meret; n++)
        {
            printf("%d ", player[1].matrix[i][n]);
        }
        printf("\n");
    }
}

#endif