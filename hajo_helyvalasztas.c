#ifndef _alma7
#define _alma7
#include "defines.c"
#include "structs.c"

void hajo_helyvalasztas(players *player)
{
    int player_kovetkezik = 1;
    int pozicio_x = 0; // bal fentről számmolom
    int pozicio_y = 0;
    int hajo_meret = 5;
    int megfelel = 0;
    while (megfelel == 0)
    {
        for (int hanyadik_jatekos = 0; hanyadik_jatekos < db_jatekos; hanyadik_jatekos++)
        {
            for (int l = 1; l < 6; l++)
            {
                hajo_meret = l;
                while (megfelel != 1)
                {
                    pozicio_x = 0;
                    pozicio_y = 0;
                    while (pozicio_x < 1 || pozicio_x > 8 || pozicio_y < 1 || pozicio_y > 8 || tabla_meret - pozicio_y < hajo_meret - 1)
                    {
                        printf("Meret: %d", hajo_meret);
                        printf("\n");
                        printf("x: ");
                        scanf("%d", &pozicio_x);
                        printf("y: ");
                        scanf("%d", &pozicio_y);
                        printf("\n");
                    }
                    pozicio_x++;
                    pozicio_y++;
                    megfelel = 1;
                    for (int i = 0; i < hajo_meret + 2 && megfelel == 1; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            printf(CYAN_TEXT"x: %d y: %d\n",pozicio_x + j - 1, pozicio_y + i - 1); printf(RESET_TEXT);
                            if (player[hanyadik_jatekos].matrix[pozicio_x + j - 1][pozicio_y + i - 1] != 0)
                            {
                                megfelel = 0;
                                break;
                            }
                        }
                    }
                    if (megfelel == 0)
                    {
                        printf(RED_TEXT "Utkozes tortent\n");
                        printf(RESET_TEXT);
                    }
                    else if (megfelel == 1)
                    {
                        for (int q = 0; q < hajo_meret; q++)
                        {
                            player[hanyadik_jatekos].matrix[pozicio_x - 1][pozicio_y + q - 1] = hajo_meret;
                        }
                    }
                }
                megfelel = 0;
                pr_tabla(player);
            }
        }
    }
}

#endif