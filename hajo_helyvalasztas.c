#ifndef _alma7
#define _alma7
#include "defines.c"
#include "structs.c"

void hajo_helyvalasztas(players *player)
{
    int player_kovetkezik = 1;
    while (player_kovetkezik == 1)
    {
        int pozicio_x = 0; // bal fentről számmolom
        int pozicio_y = 0;
        int hajo_meret = 5;
        int megfelel = 0;
        while (megfelel == 0)
        {
            printf("meret: %d", hajo_meret);
            printf("\n");
            printf("x: ");
            scanf("%d", &pozicio_x);
            printf("y: ");
            scanf("%d", &pozicio_y);

            for (int i = 0; i < hajo_meret + 2; i++)
            {
                for (int j = 0; j < 3; i++)
                {
                    if (player[0].matrix[pozicio_x - 1 + j][pozicio_y - 1 + i] != 0)
                    {
                        printf("Utkozes!!!!");
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