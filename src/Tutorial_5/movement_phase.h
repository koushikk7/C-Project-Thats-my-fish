//
// Created by Koushik on 19/05/2021.
//
#include <stdio.h>
#include "Userinput&data.h"
#include "boardgenerator.h"
#include "placement phase.h"
#include <stdlib.h>
#ifndef TUTORIAL_5_MOVEMENT_PHASE_H
#define TUTORIAL_5_MOVEMENT_PHASE_H

struct new{
    int current, new;
}row, column;

int movementphase(int m, int n){

    for (int k = 0; k < m*n; k++) {
        row.current, row.new, column.current, column.new;
        if(player1.collectedfish+player2.collectedfish == fish.total)
            break;
        if (k % 2 == 0) {
            printf("current player: %d\n", player1.number);
            printf("current player name: %s\n", player1.name);
            printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
            scanf("%d %d", &row.current, &column.current);
            while (row.current >= m || column.current >= n) {
                printf("input the correct row and column!\n");
                printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                scanf("%d %d", &row.current, &column.current);
            }
            while (player.position[row.current][column.current] != player1.number) {
                printf("pick the the correct penguin!\n");
                printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                scanf("%d %d", &row.current, &column.current);
                while (row.current >= m || column.current >= n) {
                    printf("input the correct row and column!\n");
                    printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                    scanf("%d %d", &row.current, &column.current);
                }
            }
            printf("where do you want to move this penguin to? (format: enter row and column): ");
            scanf("%d %d", &row.new, &column.new);
            while (row.new >= m || column.new >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to move this penguin to? (format: enter row and column): ");
                scanf("%d %d", &row.new, &column.new);
            }
            while (fish.amount[row.new][column.new] == 0 && player.position[row.new][column.new] == 0) {
                printf("the tile does not exist\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &row.new, &column.new);
            }
            while (player.position[row.new][column.new] != 0) {
                printf("the place is occupied!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &row.new, &column.new);
                while (row.new >= m || column.new >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &row.new, &column.new);
                }
            }
            fish.amount[row.current][column.current] = 0;
            player.position[row.current][column.current] = 0;
            player.position[row.new][column.new] = player1.number;
            player1.collectedfish = fish.amount[row.new][column.new] + player1.collectedfish;
            fish.amount[row.new][column.new] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d%d ", fish.amount[i][j], player.position[i][j]);
                }
                printf("\n");
            }
            printf("collected fish by player 1: %d\n\n", player1.collectedfish);
        }

        else {

            printf("current player: %d\n", player2.number);
            printf("current player name: %s\n", player2.name);
            printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
            scanf("%d %d", &row.current, &column.current);
            while (row.current >= m || column.current >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &row.current, &column.current);
            }
            while (player.position[row.current][column.current] != player2.number) {
                printf("pick the the correct penguin!\n");
                printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                scanf("%d %d", &row.current, &column.current);
                while (row.current >= m || column.current >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &row.current, &column.current);
                }
            }
            printf("where do you want to move this penguin to? (format: enter row and column): ");
            scanf("%d %d", &row.new, &column.new);
            while (row.new >= m || column.new >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &row.new, &column.new);
            }
            while (fish.amount[row.new][column.new] == 0 && player.position[row.new][column.new] == 0) {
                printf("the tile does not exist\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &row.new, &column.new);
            }
            while (player.position[row.new][column.new] != 0) {
                printf("the place is occupied!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &row.new, &column.new);
                while (row.new >= m || column.new >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &row.new, &column.new);
                }
            }
            fish.amount[row.current][column.current] = 0;
            player.position[row.current][column.current] = 0;
            player.position[row.new][column.new] = player2.number;
            player2.collectedfish = fish.amount[row.new][column.new] + player2.collectedfish;
            fish.amount[row.new][column.new] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d%d ", fish.amount[i][j], player.position[i][j]);
                }
                printf("\n");
            }
            printf("number of fish collected by player 2: %d\n\n", player2.collectedfish);

        }
    }

    printf("total fish collected by player 1: %d\n", player1.collectedfish);
    printf("total fish collected by player 2: %d\n", player2.collectedfish);
    if (player1.collectedfish > player2.collectedfish) {
        printf("%s has won", player1.name);
    } else if (player1.collectedfish < player2.collectedfish) {
        printf("%s has won", player2.name);
    } else
        printf("it's a draw");
    return 0;
}


#endif //TUTORIAL_5_MOVEMENT_PHASE_H
