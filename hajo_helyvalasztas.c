#ifndef _alma7
#define _alma7
#include "defines.c"
#include "structs.c"

void hajo_helyvalasztas(players *player)
{
    for (int i = 0; i < db_jatekos; i++)
    {
        for (int hajo_meret = 5; hajo_meret > 0; hajo_meret--)
        {
            int hajo_lerakhato = 0;
            while (hajo_lerakhato != 1)
            {
                printf("A(z) %d egyseg hosszu hajo helyzete/iranya:\n", hajo_meret);
                int x = 0;
                int y = 0;
                int irany = -1;
                printf("X: ");
                scanf("%d", &x);
                printf("Y: ");
                scanf("%d", &y);
                while (irany < 0 || irany > 1)
                {
                    printf("Irany (0 = visszintes, 1 = fuggoleges): ");
                    scanf("%d", &irany);
                }

                if (x > tabla_meret || x < 0 || y > tabla_meret || y < 0)
                {
                    printf(RED_TEXT "Rossz helyre lett megadva a kezdopont.\n");
                    printf(RESET_TEXT);
                    hajo_meret++;
                    break;
                }
                if (irany == 0 && y + hajo_meret > tabla_meret || irany == 1 && x + hajo_meret > tabla_meret)
                {
                    printf(RED_TEXT "A hajo kilog a palyarol.\n");
                    printf(RESET_TEXT);
                    hajo_meret++;
                    break;
                }
                if (x > 1 && irany == 0)
                {
                    for (int i = y - 1; i < y + hajo_meret + 1; i++)
                    {
                        if (player[i].matrix[x][i] == 1)
                        {
                            printf(RED_TEXT "Ide nem rakhatod mivel utkozne egy másik hajoval\n");
                            printf(RESET_TEXT);
                        }
                        hajo_meret++;
                        break;
                    }
                }
                if (x < tabla_meret - 1 && irany == 0)
                {
                    for (int i = y - 1; i < y + hajo_meret + 1; i++)
                    {
                        if (player[i].matrix[x + 1][i] == 1)
                        {
                            printf(RED_TEXT "Ide nem rakhatod mivel utkozne egy másik hajoval\n");
                            printf(RESET_TEXT);
                        }
                        hajo_meret++;
                        break;
                    }
                }
                if (irany == 0 && y > 1)
                {
                    if (player[i].matrix[x - 1][y] == 1 || player[i].matrix[x - 1][y + hajo_meret + 1] == 1 )
                    {
                            printf(RED_TEXT "Ide nem rakhatod mivel utkozne egy másik hajoval\n");
                    }
                    hajo_meret++;
                    break;
                }
                

                break;
            }
        }
    }
}

#endif