#ifndef _alma3
#define _alma3
#include <stdio.h>
#include "defines.c"

typedef struct
{
    char nev[10];
    int el;
    int matrix[tabla_meret + 2][tabla_meret + 2];
} players;

typedef struct
{
    int meret_elet;
    int kezdopont[2]; //x,y kordinata
    int irany; // 0 = visszintes, 1 = fuggoleges
} hajok;

#endif