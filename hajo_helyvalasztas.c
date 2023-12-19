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
        for (int l = 1; l < 6; l++)
        {
            hajo_meret = l;
            pozicio_x = 0;
            pozicio_y = 0;
            while (pozicio_x < 1 || pozicio_x > 8 || pozicio_y < 1 || pozicio_y > 8 || tabla_meret - pozicio_y < hajo_meret - 1)
            {
                printf("meret: %d", hajo_meret);
                printf("\n");
                printf("x: ");
                scanf("%d", &pozicio_x);
                printf("y: ");
                scanf("%d", &pozicio_y);
                printf("\n");
            }
            pozicio_x++;
            pozicio_y++;
            for (int i = 0; i < hajo_meret + 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (player[0].matrix[pozicio_x - 1 + j][pozicio_y - 1 + i] != 0)
                    {
                        printf(RED_TEXT "X %d", player[0].matrix[pozicio_x - 1 + j][pozicio_y - 1 + i]);
                        printf(RESET_TEXT);
                    }
                    if (player[0].matrix[pozicio_x - 1 + j][pozicio_y - 1 + i] == 0)
                    {
                        printf(GREEN_TEXT "M %d", player[0].matrix[pozicio_x - 1 + j][pozicio_y - 1 + i]);
                        printf(RESET_TEXT);
                    }
                }
            }
        }
    }

    while (player_kovetkezik == 2)
    {
    }
}

#endif