//
// Created by Koushik on 18/05/2021.
//
#include <stdio.h>
#ifndef TUTORIAL_5_USERINPUT_H
#define TUTORIAL_5_USERINPUT_H
#define Maxcharacters 25
#include <stdlib.h>
struct data {
    char *name, number;
    int penguins;
    int row, column;
    int **amount, **position;
    int collectedfish, total;

}player1, player2, player,fish;
void userinput(){
    fish.total = 0;
    player1.number = 1;
    player2.number = 2;
    player1.name = (char*)malloc(25*sizeof(char));
    player2.name = (char*)malloc(25*sizeof(char));
    printf("Player 1 - Enter you name: ");
    fgets(player1.name,Maxcharacters,stdin);
    printf("Player 2 - Enter your name: ");
    fgets(player2.name,Maxcharacters,stdin);
    printf("Enter number of Rows: ");
    scanf("%d", &player.row);
    printf("Enter number of Columns:");
    scanf("%d", &player.column);
    player.penguins = player.row/2;

}
#endif //TUTORIAL_5_USERINPUT_H
