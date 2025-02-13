//
// Created by Koushik on 19/05/2021.
//
#include "boardgenerator.h"
#include "Userinput&data.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef TUTORIAL_5_PLACEMENT_PHASE_H
#define TUTORIAL_5_PLACEMENT_PHASE_H
struct temporary{
    int trow, tcol;
}temp;
void placementphase(int m, int n){
    player1.collectedfish = 0;
    player2.collectedfish = 0;
    for (int k = 0; k < (player.penguins * 2); k++) {
        if (k % 2 == 0) {
            printf("current player: %d\n", player1.number);
            printf("current player name: %s\n", player1.name);
            printf("where do you want to place the penguin?\n");
            printf("Enter the row:");
            scanf("%d", &temp.trow);
            printf("Enter the Column:");
            scanf("%d", &temp.tcol);

            while (temp.trow >= m || temp.tcol >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &temp.trow, &temp.tcol);
            }
            while (player.position[temp.trow][temp.tcol] == player1.number ||
                   player.position[temp.trow][temp.tcol] == player2.number) {
                printf("this place has been occupied!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &temp.trow, &temp.tcol);
                while (temp.trow >= m || temp.tcol >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &temp.trow, &temp.tcol);
                }
            }
            player.position[temp.trow][temp.tcol] = player1.number;
            player1.collectedfish = fish.amount[temp.trow][temp.tcol] + player1.collectedfish;
            fish.amount[temp.trow][temp.tcol] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d%d ", fish.amount[i][j], player.position[i][j]);
                }
                printf("\n");
            }
            printf("fish collected by player 1: %d\n\n", player1.collectedfish);
        }
        else {
            printf("current player: %d\n", player2.number);
            printf("current player name: %s\n", player2.name);
            printf("where do you want to place the penguin?\n");
            printf("Enter the row:");
            scanf("%d", &temp.trow);
            printf("Enter the Column:");
            scanf("%d", &temp.tcol);
            while (temp.trow >= m || temp.tcol >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &temp.trow, &temp.tcol);
            }
            while (player.position[temp.trow][temp.tcol] == player1.number || player.position[temp.trow][temp.tcol] == player2.number) {
                printf("this place has been occupied!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &temp.trow, &temp.tcol);
                while (temp.trow >= m || temp.tcol >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &temp.trow, &temp.tcol);
                }
            }
            player.position[temp.trow][temp.tcol] = player2.number;
            player2.collectedfish = fish.amount[temp.trow][temp.tcol] + player2.collectedfish;
            fish.amount[temp.trow][temp.tcol] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d%d ", fish.amount[i][j], player.position[i][j]);
                }
                printf("\n");
            }

        }
    }

    printf("board after placement phase:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%d ", fish.amount[i][j], player.position[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif //TUTORIAL_5_PLACEMENT_PHASE_H
