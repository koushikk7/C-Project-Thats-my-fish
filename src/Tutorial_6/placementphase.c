/** @file placementphase.c
* @brief The main task of this function is to place the penguins on the tile inputed by the user.
* @brief The function also checks for error like one penguin on each tile.
* @brief The function also adds the number of fish collected by the player to the player's account.
* @bugs No bugs in the function.
* @see main.c
*/

#include "placementphase.h"

void placementphase(int m, int n){
    player1.collectedfish = 0;
    player2.collectedfish = 0;
    for (int k = 0; k < (player.penguins * 2); k++) {
        if (k % 2 == 0) {
            printf("current player: %d\n", player1.number);
            printf("current player name: %s\n", player1.name);

            goto placement1;

            input1:
            printf("input the correct row and column!\n");
            goto placement1;

            fish1:
            printf("You can only place a penguin on an unoccupied tile which has one fish on it.\n");
            goto placement1;

            occupied1:
            printf("this place has been occupied!\n");

            placement1:
            printf("where do you want to place the penguin? (enter row and column): ");
            while(scanf("%d %d",&temp.trow, &temp.tcol) == 0 || (temp.trow < 0 || temp.tcol < 0)){
                getchar();
                printf("Invalid input (You shouldn't input negative numbers or characters)\n");
                goto placement1;
            }

            if (temp.trow >= m || temp.tcol >= n) {
                goto input1;
            }
            if (player.position[temp.trow][temp.tcol] == player1.number ||
                   player.position[temp.trow][temp.tcol] == player2.number) {

                goto occupied1;
            }
            if(fish.amount[temp.trow][temp.tcol] != 1){
                goto fish1;
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
            goto placement2;

            input2:
            printf("input the correct row and column!\n");
            goto placement2;

            fish2:
            printf("You can only place a penguin on an unoccupied tile which has one fish on it.\n");
            goto placement2;


        occupied2:
            printf("this place has been occupied!\n");

            placement2:
            printf("where do you want to place the penguin? (enter row and column): ");
            while(scanf("%d %d",&temp.trow, &temp.tcol) == 0 || (temp.trow < 0 || temp.tcol < 0)){
                getchar();
                getchar();
                getchar();
                printf("Invalid input (You shouldn't input negative numbers or characters)\n");
                goto placement2;
            }

            while (temp.trow >= m || temp.tcol >= n) {
                goto input2;
            }
            while (player.position[temp.trow][temp.tcol] == player1.number || player.position[temp.trow][temp.tcol] == player2.number) {

                goto occupied2;
            }
            if(fish.amount[temp.trow][temp.tcol] != 1){
                goto fish2;
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
            printf("fish collected by player 2: %d\n\n", player2.collectedfish);

        }
    }

    printf("\nboard after placement phase:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%d ", fish.amount[i][j], player.position[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
