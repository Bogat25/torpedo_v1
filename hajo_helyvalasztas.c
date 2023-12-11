#ifndef _alma7
#define _alma7
#include "defines.c"
#include "structs.c"

void hajo_helyvalasztas(players *player)
{

    hajok *hajo_1_player_1 = foglalas_hajok();
    hajok *hajo_2_player_1 = foglalas_hajok();
    hajok *hajo_3_player_1 = foglalas_hajok();
    hajok *hajo_4_player_1 = foglalas_hajok();
    hajok *hajo_5_player_1 = foglalas_hajok();

    hajok *hajo_1_player_2 = foglalas_hajok();
    hajok *hajo_2_player_2 = foglalas_hajok();
    hajok *hajo_3_player_2 = foglalas_hajok();
    hajok *hajo_4_player_2 = foglalas_hajok();
    hajok *hajo_5_player_2 = foglalas_hajok();

    hajo_1_player_1->meret_elet = 1;
    hajo_1_player_2->meret_elet = 1;
    hajo_2_player_1->meret_elet = 2;
    hajo_2_player_2->meret_elet = 2;
    hajo_3_player_1->meret_elet = 3;
    hajo_3_player_2->meret_elet = 3;
    hajo_4_player_1->meret_elet = 4;
    hajo_4_player_2->meret_elet = 4;
    hajo_5_player_1->meret_elet = 5;
    hajo_5_player_2->meret_elet = 5;

    int kilepes = 0;
    printf("Kerem %s jatekos hajo kordinatait.\n");
    while (kilepes != 1)
    {
        printf(YELLOW_TEXT "1 egysegnyi hajo.\n");
        printf(RESET_TEXT);
        hajo_1_player_1->kezdopont[0] = 0;
        while (hajo_1_player_1->kezdopont[0] < 1 || hajo_1_player_1->kezdopont[1] > tabla_meret)
        {
            printf("X: ");
            scanf("%d", &hajo_1_player_1->kezdopont[0]);
        }
        hajo_1_player_1->kezdopont[1] = 0;
        while (hajo_1_player_1->kezdopont[1] < 1 || hajo_1_player_1->kezdopont[1] > tabla_meret)
        {
            printf("Y: ");
            scanf("%d", &hajo_1_player_1->kezdopont[1]);
        }
        printf(CYAN_TEXT "\nA halyo beolvasasa sikeres volt.\n");
        printf(RESET_TEXT);

        int kilepes_2 = 0;
        while (kilepes_2 != 1)
        {
            hajo_2_player_1->kezdopont[0] = 0;
            while (hajo_2_player_1->kezdopont[0] < 1 || hajo_2_player_1->kezdopont[0] > tabla_meret)
            {
                printf("X: ");
                scanf("%d", &hajo_2_player_1->kezdopont[0]);
            }
            hajo_2_player_1->kezdopont[1] = 0;
            while (hajo_2_player_1->kezdopont[1] < 1 || hajo_2_player_1->kezdopont[1] > tabla_meret)
            {
                printf("Y: ");
                scanf("%d", &hajo_2_player_1->kezdopont[1]);
            }
            hajo_2_player_1->irany = -1;
            while (hajo_2_player_1->irany < 0 || hajo_2_player_1->irany > 1)
            {
                printf("Irany: ");
                scanf("%d", &hajo_2_player_1->irany);
            } //edig jó a kód
            int utkozes = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int n = 0; i < hajo_2_player_1->meret_elet + 1; i++)
                {
                    if (hajo_2_player_1->irany == 0)
                    {
                        if (player->matrix[hajo_2_player_1->kezdopont[0] + i][hajo_2_player_1->kezdopont[1] + n] == 1)
                        {
                            printf(RED_TEXT "Utkozes tortent!\n");
                            printf(RESET_TEXT);
                            utkozes = 1;
                        }
                    }
                }
            }
            if (utkozes == 0)
            {
                printf(GREEN_TEXT "Nem tortent utkozes.\n");
                kilepes_2 = 1;
            }
        }
    }
}

#endif