#ifndef TUTORIAL_5_BOARDGENERATOR_H
#define TUTORIAL_5_BOARDGENERATOR_H
#include "Userinput&data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printboard(int m, int n) {
//dynamically allocating the memory to the board
    fish.amount = (int **) malloc(player.row * sizeof(int *));
    for (int i = 0; i < player.row; i++){
        fish.amount[i] = malloc(player.column * sizeof(int));
    }
    player.position = (int **) malloc(player.row * sizeof(int *));
    for (int i = 0; i < player.row; i++){
        player.position[i] = malloc(player.column * sizeof(int));
    }
    srand (time(NULL));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                player.position[i][j] = 0;
                fish.amount[i][j] = rand() % 3 + 1;
                fish.total = fish.total + fish.amount[i][j];
                printf("%d%d ", fish.amount[i][j], player.position[i][j]);
            }
            printf("\n");
        }


}
#endif //TUTORIAL_5_BOARDGENERATOR_H
