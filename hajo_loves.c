#ifndef _alma8
#define _alma8
#include "defines.c"
#include "structs.c"

int hajo_loves(players *player)
{
    int jatekban = 1;
    int loves_x = -1;
    int loves_y = -1;
    int talalt = -1;
    int hajo_fajta = 0;
    int db_nem_elsujedt_egyseg;
    int hanyadik_jatekos_ellenfel;
    int varakozas = -1;
    while (jatekban == 1)
    {
        for (int hanyadik_jatekos = 0; hanyadik_jatekos < db_jatekos; hanyadik_jatekos++)
        {
            printf(CYAN_TEXT "%s ", player[hanyadik_jatekos].nev);
            printf(RESET_TEXT "szavaz\n");
            printf(RESET_TEXT);
            if (hanyadik_jatekos == 0)
            {
                hanyadik_jatekos_ellenfel = 1;
            }
            if (hanyadik_jatekos == 1)
            {
                hanyadik_jatekos_ellenfel = 0;
            }
            while (loves_x < 1 || loves_x > tabla_meret || loves_y < 1 || loves_y > tabla_meret)
            {
                if (varakozas != -1)
                {
                    printf(YELLOW_TEXT "A kovetkezo kor inditasahoz irjon be egy szamot: ");
                    while (scanf("%d", &varakozas) != 1)
                    {
                        printf(YELLOW_TEXT "A kovetkezo kor inditasahoz irjon be egy szamot: ");
                        while (getchar() != '\n')
                            ;
                    }
                    printf(RESET_TEXT);
                }
                varakozas = 1;
                system("cls");
                printf("Ellenfeled jelenlegi allasa\n\n");
                pr_ellenfel_allasa(player[hanyadik_jatekos_ellenfel]);
                printf("x:");
                while (scanf("%d", &loves_x) != 1 || loves_x < 0 || loves_x > 8)
                {
                    printf("Hibas bemenet! Irany, x: ");
                    while (getchar() != '\n')
                        ;
                }
                printf("y:");
                while (scanf("%d", &loves_y) != 1 || loves_y < 0 || loves_y > 8)
                {
                    printf("Hibas bemenet! Irany, y: ");
                    while (getchar() != '\n')
                        ;
                }
                printf("\n");
            }
            talalt = 0;
            if (player[hanyadik_jatekos_ellenfel].matrix[loves_x][loves_y] != 0 && player[hanyadik_jatekos_ellenfel].matrix[loves_x][loves_y] != 9)
            {
                talalt = 2;
                hajo_fajta = player[hanyadik_jatekos_ellenfel].matrix[loves_x][loves_y];
                player[hanyadik_jatekos_ellenfel].matrix[loves_x][loves_y] = 9; // a 9-ences azt jelenti hogy elsülyedt
                for (int m = 0; m < tabla_meret && talalt == 2; m++)
                {
                    for (int n = 0; n < tabla_meret; n++)
                    {
                        if (player[hanyadik_jatekos_ellenfel].matrix[m][n] == hajo_fajta)
                        {
                            talalt = 1;
                        }
                    }
                }
            }
            if (talalt == 0)
            {
                printf(RED_TEXT "Nem talalt.\n");
                printf(RESET_TEXT);
            }
            if (talalt == 1)
            {
                printf(CYAN_TEXT "Talalt, de nem sullyedt.\n");
                printf(RESET_TEXT);
            }
            if (talalt == 2)
            {
                printf(GREEN_TEXT "Talalt + sullyedt.\n");
                printf(RESET_TEXT);
            }
            db_nem_elsujedt_egyseg = 0;
            for (int m = 0; m < tabla_meret; m++)
            {
                for (int n = 0; n < tabla_meret; n++)
                {
                    if (player[hanyadik_jatekos_ellenfel].matrix[m][n] != 0 && player[hanyadik_jatekos_ellenfel].matrix[m][n] != 9)
                    {
                        db_nem_elsujedt_egyseg++;
                    }
                }
            }
            if (db_nem_elsujedt_egyseg == 0)
            {
                return hanyadik_jatekos;
            }
            printf(MAGENTA_TEXT "Ellenfelenek nem elsujedt blokjai: %d\n", db_nem_elsujedt_egyseg);
            printf(RESET_TEXT);
            loves_x = -1;
            loves_y = -1;
        }
    }
}

#endif