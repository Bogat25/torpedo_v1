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
    for (int hanyadik_jatekos = 0; hanyadik_jatekos < db_jatekos; hanyadik_jatekos++)
    {
        system("cls");
        printf(YELLOW_TEXT "%s Jatekos valaszt: ", player[hanyadik_jatekos].nev);
        printf(RESET_TEXT "\n");
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
                    while (scanf("%d", &irany) != 1 || irany < 0 || irany > 1)
                    {
                        printf("Hibas bemenet! Irany, (1 = fuggoleges, 0 = visszintes): ");
                        while (getchar() != '\n')
                            ;
                    }
                    printf("x: ");
                    while (scanf("%d", &pozicio_x) != 1 || pozicio_x < 1 || pozicio_x > 8)
                    {
                        printf("Hibas bemenet! x: ");
                        while (getchar() != '\n')
                            ;
                    }
                    printf("y: ");
                    while (scanf("%d", &pozicio_y) != 1 || pozicio_y < 1 || pozicio_y > 8)
                    {
                        printf("Hibas bemenet! y: ");
                        while (getchar() != '\n')
                            ;
                    }
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
                            player[hanyadik_jatekos].matrix[pozicio_x + q - 1][pozicio_y - 1] = hajo_meret;
                        }
                    }
                }
            }
            megfelel = 0;
            pr_adott_tabla(player[hanyadik_jatekos]);
        }
    }
}

#endif