/** @file boardgenerator.c
* @brief The function generators the board by taking input from the user.
* @bugs No bugs in the function.
* @see main.c
*/

#include "boardgenerator.h"

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
    int onefishtile;
board:
    onefishtile = 0;   // tile with one fish
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            player.position[i][j] = 0;
            fish.amount[i][j] = rand() % 3 + 1;
            if(fish.amount[i][j] == 1){
                onefishtile++;
            }
            fish.total = fish.total + fish.amount[i][j];
        }
    }
    if(onefishtile <= (player.penguins*2)){
        goto board;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) {
            printf("%d%d ", fish.amount[i][j], player.position[i][j]);
        }
        printf("\n");
    }

}
