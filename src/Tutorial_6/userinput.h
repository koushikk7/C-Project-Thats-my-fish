//
// Created by Koushik on 03/06/2021.
//

#ifndef T6_USERINPUT_H
#define T6_USERINPUT_H
#define Maxcharacters 25

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "string.h"

struct data {
    int c;
    char *name, number;
    int penguins;
    int row, column;
    int **amount, **position;
    int collectedfish, total;

}player1, player2, player,fish, possibleplayer;

void userinput();

#endif //T6_USERINPUT_H
