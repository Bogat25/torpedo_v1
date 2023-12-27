#ifndef _alma7
#define _alma7
#include "defines.c"
#include "structs.c"

void hajo_helyvalasztas(players *player)
{
    int player_kovetkezik = 1;
    int pozicio_x = 0; // bal fentről számmolom
    int pozicio_y = 0;
    int irany = 0; // 0 => visszintes, 1 => föggőleges
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
                    irany = -1;
                    while (irany == 0 && (pozicio_x < 1 || pozicio_x > 8 || pozicio_y < 1 || pozicio_y > 8 || tabla_meret - pozicio_y < hajo_meret - 1) ||
                           irany == 1 && (pozicio_x < 1 || pozicio_x > 8 || pozicio_y < 1 || pozicio_y > 8 || tabla_meret - pozicio_x < hajo_meret - 1) || irany < 0 || irany > 1)
                    {
                        printf("Meret: %d", hajo_meret);
                        printf("\n");
                        printf("Irany, (1 = fuggoleges, 0 = visszintes): ");
                        scanf("%d", &irany);
                        printf("x: ");
                        scanf("%d", &pozicio_x);
                        printf("y: ");
                        scanf("%d", &pozicio_y);
                        printf("\n");
                    }
                    pozicio_x++;
                    pozicio_y++;
                    megfelel = 1;
                    if (irany == 0)
                    {
                        for (int i = 0; i < hajo_meret + 2 && megfelel == 1; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (player[hanyadik_jatekos].matrix[pozicio_x + j - 2][pozicio_y + i - 2] != 0)
                                {
                                    printf(RESET_TEXT);
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
                    if (irany == 1)
                    {
                        for (int i = 0; i < hajo_meret + 2 && megfelel == 1; i++)
                        {
                            for (int j = 0; j < 3; j++)
                            {
                                if (player[hanyadik_jatekos].matrix[pozicio_x + i - 2][pozicio_y + j - 2] != 0)
                                {
                                    printf(RESET_TEXT);
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
                                player[hanyadik_jatekos].matrix[pozicio_x + q - 1][pozicio_y- 1] = hajo_meret;
                            }
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