//
// Created by Koushik on 19/05/2021.
//
#include <stdio.h>
#ifndef TUTORIAL_5_GAMERULES_H
#define TUTORIAL_5_GAMERULES_H
void gamerules(){
    printf("GAME RULES\n");
    printf("1. the players have 2 penguins each\n2. during the placement phase, two penguins can't be placed on the same tile\n"
           "3. during the movement phase, once you move your penguin and the fish present on the tile are collected, the previous tile you moved your penguin from is removed and you cannot place your penguin on empty tile,\n"
           "4. you cannot move another player's penguin\n5. The game ends when all the fish are collected\n");

}
#endif //TUTORIAL_5_GAMERULES_H
