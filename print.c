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
        printf(YELLOW_TEXT "%d ", i + 1);
        printf(RESET_TEXT);
    }
    pr_terkoz();
    printf("  "); // 2. player
    for (int i = 0; i < tabla_meret; i++)
    {
        printf(YELLOW_TEXT "%d ", i + 1);
        printf(RESET_TEXT);
    }

    printf("\n");
    for (int i = 1; i < tabla_meret + 1; i++)
    {
        printf(YELLOW_TEXT "%d ", i);
        printf(RESET_TEXT); // 1. player
        for (int n = 1; n < tabla_meret + 1; n++)
        {
            if (player[0].matrix[i][n] != 0)
            {
                printf(CYAN_TEXT "%d ", player[0].matrix[i][n]);
                printf(RESET_TEXT);
            }
            else
            {
                printf("%d ", player[0].matrix[i][n]);
            }
        }
        pr_terkoz();
        printf(YELLOW_TEXT "%d ", i);
        printf(RESET_TEXT); // 2. player
        for (int n = 1; n < tabla_meret + 1; n++)
        {
            if (player[0].matrix[i][n] != 0)
            {
                printf(CYAN_TEXT "%d ", player[0].matrix[i][n]);
                printf(RESET_TEXT);
            }
            else
            {
                printf("%d ", player[0].matrix[i][n]);
            }
        }
        printf("\n");
    }
}

void pr_lehejezesek(players *player)
{
    printf("%s", player[0].nev);
    int nev_hossz = strlen(player[0].nev); // szoköz a playerek nevei között
    for (int i = 0; i < tabla_meret + 2 * terkoz - nev_hossz + 2; i++)
    {
        printf(" ");
    }

    printf("%s", player[1].nev);
    printf("\n");
    printf("  "); // 1. player
    for (int i = 0; i < tabla_meret + 2; i++)
    {
        printf(CYAN_TEXT "%d ", i);
        printf(RESET_TEXT);
    }
    pr_terkoz();
    printf("  "); // 2. player
    for (int i = 0; i < tabla_meret + 2; i++)
    {
        printf(CYAN_TEXT "%d ", i);
        printf(RESET_TEXT);
    }

    printf("\n");
    for (int i = 0; i < tabla_meret + 2; i++)
    {
        printf(YELLOW_TEXT "%d ", i);
        printf(RESET_TEXT); // 1. player
        for (int n = 0; n < tabla_meret + 2; n++)
        {
            if (player[0].matrix[i][n] != 0)
            {
                printf(CYAN_TEXT "%d ", player[0].matrix[i][n]);
                printf(RESET_TEXT);
            }
            else
            {
                printf("%d ", player[0].matrix[i][n]);
            }
        }
        pr_terkoz();
        printf(YELLOW_TEXT "%d ", i);
        printf(RESET_TEXT); // 2. player
        for (int n = 0; n < tabla_meret + 2; n++)
        {
            if (player[0].matrix[i][n] != 0)
            {
                printf(CYAN_TEXT "%d ", player[0].matrix[i][n]);
                printf(RESET_TEXT);
            }
            else
            {
                printf("%d ", player[0].matrix[i][n]);
            }
        }
        printf("\n");
    }
}
void pr_adott_tabla(players player)
{
    printf(CYAN_TEXT "%s\n", player.nev);
    printf(RESET_TEXT);
    printf("  ");
    for (int i = 0; i < tabla_meret; i++)
    {
        printf(YELLOW_TEXT "%d ", i + 1);
        printf(RESET_TEXT);
    }

    printf("\n");
    for (int i = 1; i < tabla_meret + 1; i++)
    {
        printf(YELLOW_TEXT "%d ", i);
        printf(RESET_TEXT); // 1. player
        for (int n = 1; n < tabla_meret + 1; n++)
        {
            if (player.matrix[i][n] != 0)
            {
                printf(CYAN_TEXT "%d ", player.matrix[i][n]);
                printf(RESET_TEXT);
            }
            else
            {
                printf("%d ", player.matrix[i][n]);
            }
        }
        printf("\n");
    }
}
void pr_ellenfel_allasa(players player)
{
    printf("  ");
    for (int i = 0; i < tabla_meret; i++)
    {
        printf(YELLOW_TEXT "%d ", i + 1);
        printf(RESET_TEXT);
    }

    printf("\n");
    for (int i = 1; i < tabla_meret + 1; i++)
    {
        printf(YELLOW_TEXT "%d ", i);
        printf(RESET_TEXT); // 1. player
        for (int n = 1; n < tabla_meret + 1; n++)
        {
            if (player.matrix[i][n] == 9)
            {
                printf(CYAN_TEXT "X ");
                printf(RESET_TEXT);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
void pr_elkoszones(){
    printf(YELLOW_TEXT"Koszonom hogy a jatekommal jatszott.\n");
    printf(CYAN_TEXT"Keszitette: Csani#3902");printf(RESET_TEXT);
}
void pr_nyertes(players player){
    printf(YELLOW_TEXT"A nyertes: "); printf(CYAN_TEXT"%s\n",player.nev);
    pr_elkoszones();    
}
#endif