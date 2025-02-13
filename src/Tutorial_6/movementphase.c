/** @file movementphase.c
* @brief This function is for the movement phase, It moves the selected penguin to the desired position of the player.
* @brief This function also checks the penguins position and doesn't let penguins jump over another penguin or an empty tile or move across the board.
* @bugs No bugs in the function.
* @see main.c
*/

#include "movementphase.h"
#include "possiblemoves.h"

int movementphase(int m, int n){
    for (int z = 0; z < m*n; z++) {

        if(player1.collectedfish + player2.collectedfish == fish.total) {   //if the total number of fish collected by players is equal to total number of fish on the board, it breaks out of for loop and displays the scoreboard.
            break;
        }

        if (z % 2 == 0) {
            playerone:

            if(player1.collectedfish + player2.collectedfish == fish.total) {
                break;
            }

            if(possiblemoves(m, n) == 3){
                printf("All penguins are blocked\n");
                break;
            }

            if(possiblemoves(m, n) == 1){
                printf("All penguins of player 1 are blocked\n\n");
                goto playertwo;
            }

            printf("current player: %d\n", player1.number);
            printf("current player name: %s\n", player1.name);
            goto movement1;

        input1:
            printf("input the correct row and column!\n");
            goto movement1;

        incorrectpenguin1:
            printf("pick the the correct penguin!\n");

            movement1:
            printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): "); //asks the user to select a penguin that he wants to move.
            while(scanf("%d %d", &row.current, &column.current) == 0 || (row.current < 0 || column.current < 0)){
                getchar();
                getchar();
                getchar();
                printf("Invalid input (You shouldn't input negative numbers or characters)\n");
                goto movement1;
            }

            movementcheck:

            if (row.current >= m || column.current >= n) {
                goto input1;
            }
            if (player.position[row.current][column.current] != player1.number) {
                goto incorrectpenguin1;
            }


            int invalidmove1 = 0, invalidmove2 = 0 , invalidmove3 = 0, invalidmove4 = 0;
            int countpositivex = 0, countpositivey = 0, countnegativex = 0, countnegativey = 0;

            if(column.current == n-1){
                invalidmove1 = n+1;
                countpositivex = 0;
            }
            else {

                for (int i = row.current, j = column.current + 1; j < n; j++) {
                    if (player.position[i][j] == 1 || player.position[i][j] == 2 ||
                        (fish.amount[i][j] == 0 && player.position[i][j] == 0)) {
                        invalidmove1 = j;//>
                        break;
                    }
                    countpositivex++;
                }
            }

            if(column.current == 0){
                invalidmove2 = -1;
                countnegativex = 0;
            }
            else {

                for (int k = row.current, l = column.current-1; l >= 0; l--) {

                    if (player.position[k][l] == 1 || player.position[k][l] == 2 || (fish.amount[k][l] == 0 && player.position[k][l] == 0)) {
                        invalidmove2 = l;//<
                        break;
                    }
                    countnegativex++;
                }
            }
            if(row.current == 0){
                invalidmove3 = -1;
                countpositivey = 0;
            }
            else {

                for (int m1 = row.current - 1, n1 = column.current; m1 >= 0; m1--) {
                    if (player.position[m1][n1] == 1 || player.position[m1][n1] == 2 ||
                        (fish.amount[m1][n1] == 0 && player.position[m1][n1] == 0)) {
                        invalidmove3 = m1;//>
                        break;
                    }
                    countpositivey++;
                }
            }

            if(row.current == m-1){
                invalidmove4 = m+1;
                countnegativey = 0;
            }
            else {
                for (int o = row.current+1, p = column.current; o < m; o++) {
                    if (player.position[o][p] == 1 || player.position[o][p] == 2 || (fish.amount[o][p] == 0 && player.position[o][p] == 0)) {
                        invalidmove4 = o;
                        break;
                    }
                    countnegativey++;
                }
            }
            if(countpositivex == 0 && countpositivey == 0 && countnegativex == 0 && countnegativey == 0){
                goto blocked1;
            }
            goto position1;

        movementinput1:

            printf("input the correct row and column!\n");
            goto position1;
        tile1:
            printf("the tile does not exist\n");
            goto position1;
        movementoccupied1:
            printf("the place is occupied!\n");
            goto position1;
        across1:
            printf("You can't move across the tiles!\n");
            goto position1;
        jump1:
            printf("you can't jump over another penguin or an empty tile\n");
            goto position1;

        blocked1:
            printf("your penguin is blocked\n");
            int diffrow, diffcolumn;
            if(possiblemoves(m, n) == 3){
                printf("All penguins are blocked\n");
                break;
            }
            if(possiblemoves(m, n) == 1){
                printf("All penguins of player 1 are blocked\n\n");
                goto playertwo;
            }
            if (player.penguins > 1){
                diffrow = row.current;
                diffcolumn = column.current;
                diff1:
                printf("pick a different penguin this time (Enter row and column): ");
                scanf("%d %d", &row.current, &column.current);
                if(row.current == diffrow && column.current == diffcolumn){
                    goto diff1;
                }
                else{
                    goto movementcheck;
                }
            }

        position1:
            printf("where do you want to move this penguin to? (format: enter row and column): ");

            while(scanf("%d %d", &row.new, &column.new) == 0 || (row.new < 0 || column.new < 0)){
                getchar();
                getchar();
                getchar();
                printf("Invalid input (You shouldn't input negative numbers or characters)\n");
                goto position1;
            }

            if (row.new >= m || column.new >= n) {
                goto movementinput1;
            }
            if (fish.amount[row.new][column.new] == 0 && player.position[row.new][column.new] == 0) {
                goto tile1;
            }
            if (player.position[row.new][column.new] != 0) {
               goto movementoccupied1;
            }

            int r = abs(row.new - row.current);//1
            int c = abs(column.new - column.current);//1
            int rowmove = row.new - row.current;
            int columnmove = column.new - column.current;

            if (rowmove == 0 && columnmove > 0){
                if(countpositivex == n-1 || invalidmove1 == 0){
                    goto check1;
                }
                if (column.new > invalidmove1)
                      goto jump1;
            }
            if(rowmove == 0 && columnmove < 0){
                if(column.new < invalidmove2)
                    goto jump1;
            }
            if(columnmove == 0 && rowmove > 0){
                if(countnegativey == m-1 || invalidmove3 == 0){
                    goto check1;
                }
                if (row.new > invalidmove4)
                    goto jump1;
            }
            if(columnmove == 0 && rowmove < 0){
                if(row.new < invalidmove3)
                    goto jump1;
            }


        check1:
            if(r == 0 || c == 0){
                goto gs1;
            }

            if(player.position[row.new][column.new] == player.position[row.current+r][column.current+c] ||
               player.position[row.new][column.new] == player.position[row.current+r][column.current-c] ||
               player.position[row.new][column.new] == player.position[row.current-r][column.current+c] ||
               player.position[row.new][column.new] == player.position[row.current-r][column.current-c]) {

                goto across1;
            }

        gs1:
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
            playertwo:

            if(player1.collectedfish + player2.collectedfish == fish.total) {
                break;
            }
            if(possiblemoves(m, n) == 3){
                printf("All penguins are blocked\n");
                break;
            }
            if(possiblemoves(m, n) == 2){
                printf("All penguins of player 2 are blocked\n\n");
                goto playerone;
            }

            printf("current player: %d\n", player2.number);
            printf("current player name: %s\n", player2.name);
            goto movement2;

        input2:
            printf("input the correct row and column!\n");
            goto movement2;

        incorrectpenguin2:
            printf("pick the the correct penguin!\n");

        movement2:

            printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");

            while(scanf("%d %d", &row.current, &column.current) == 0 || (row.current < 0 || column.current < 0)){
                getchar();
                getchar();
                getchar();
                printf("Invalid input (You shouldn't input negative numbers or characters)\n");
                goto movement2;
            }

            movementcheck2:
            while (row.current >= m || column.current >= n) {
               goto input2;
            }
            while (player.position[row.current][column.current] != player2.number) {
               goto incorrectpenguin2;
            }

            int invalidmove1 = 0, invalidmove2 = 0 , invalidmove3 = 0, invalidmove4 = 0;
            int countpositivex = 0, countpositivey = 0, countnegativex = 0, countnegativey = 0;

            if(column.current == n-1){
                invalidmove1 = n+1;
                countpositivex = 0;
            }
            else {

                for (int i = row.current, j = column.current + 1; j < n; j++) {
                    if (player.position[i][j] == 1 || player.position[i][j] == 2 ||
                        (fish.amount[i][j] == 0 && player.position[i][j] == 0)) {
                        invalidmove1 = j;//>
                        break;
                    }
                    countpositivex++;
                }
            }

            if(column.current == 0){
                invalidmove2 = -1;
                countnegativex = 0;
            }
            else {

                for (int k = row.current, l = column.current-1; l >= 0; l--) {

                    if (player.position[k][l] == 1 || player.position[k][l] == 2 || (fish.amount[k][l] == 0 && player.position[k][l] == 0)) {
                        invalidmove2 = l;//<
                        break;
                    }
                    countnegativex++;
                }
            }
            if(row.current == 0){
                invalidmove3 = -1;
                countpositivey = 0;
            }
            else {

                for (int m1 = row.current - 1, n1 = column.current; m1 >= 0; m1--) {
                    if (player.position[m1][n1] == 1 || player.position[m1][n1] == 2 ||
                        (fish.amount[m1][n1] == 0 && player.position[m1][n1] == 0)) {
                        invalidmove3 = m1;//>
                        break;
                    }
                    countpositivey++;
                }
            }

            if(row.current == m-1){
                invalidmove4 = m+1;
                countnegativey = 0;
            }
            else {
                for (int o = row.current+1, p = column.current; o < m; o++) {
                    if (player.position[o][p] == 1 || player.position[o][p] == 2 || (fish.amount[o][p] == 0 && player.position[o][p] == 0)) {
                        invalidmove4 = o;
                        break;
                    }
                    countnegativey++;
                }
            }

            if(countpositivex == 0 && countpositivey == 0 && countnegativex == 0 && countnegativey == 0){
                goto blocked2;
            }

        goto position2;

        movementinput2:
            printf("input the correct row and column!\n");
            goto position2;
        tile2:
            printf("the tile does not exist\n");
            goto position2;
        movementoccupied2:
            printf("the place is occupied!\n");
            goto position2;
        across2:
            printf("You can't move across the tiles!\n");
            goto position2;
        jump2:
            printf("you can't jump over another penguin or an empty tile\n");
            goto position2;
        blocked2:
            printf("The penguin you chose is blocked\n");
            int diffrow, diffcolumn;
            if(possiblemoves(m, n) == 3){
                printf("All penguins are blocked\n");
                break;
            }
            if(possiblemoves(m, n) == 2){
                printf("All penguins of player 2 are blocked\n");
                goto playerone;
            }
            if(player.penguins > 1){
                diffrow = row.current;
                diffcolumn = column.current;
                diff2:
                printf("pick a different penguin this time (Enter row and column): ");
                scanf("%d %d", &row.current, &column.current);
                if(row.current == diffrow && column.current == diffcolumn){
                    goto diff2;
                }
                else{
                    goto movementcheck2;
                }
            }

        position2:
            printf("where do you want to move this penguin to? (format: enter row and column): ");
            while(scanf("%d %d", &row.new, &column.new) == 0 || (row.new < 0 || column.new < 0)){
                getchar();
                getchar();
                getchar();
                printf("Invalid input (You shouldn't input negative numbers or characters)\n");
                goto position2;
            }
            while (row.new >= m || column.new >= n) {
              goto movementinput2;
            }
            while (fish.amount[row.new][column.new] == 0 && player.position[row.new][column.new] == 0) {
                goto tile2;
            }
            while (player.position[row.new][column.new] != 0) {
                goto movementoccupied2;
            }


            if (row.new >= m || column.new >= n) {
                goto movementinput1;
            }
            if (fish.amount[row.new][column.new] == 0 && player.position[row.new][column.new] == 0) {
                goto tile1;
            }
            if (player.position[row.new][column.new] != 0) {
                goto movementoccupied1;
            }

            int r = abs(row.new - row.current);
            int c = abs(column.new - column.current);
            int rowmove = row.new - row.current;
            int columnmove = column.new - column.current;

            if (rowmove == 0 && columnmove > 0){
                if(countpositivex == n-1 || invalidmove1 == 0){
                    goto check2;
                }
                if (column.new > invalidmove1)
                    goto jump2;
            }
            if(rowmove == 0 && columnmove < 0){
                if(column.new < invalidmove2)
                    goto jump2;
            }
            if(columnmove == 0 && rowmove > 0){
                if(countnegativey == m-1 || invalidmove4 == 0){
                    goto check2;
                }
                if (row.new > invalidmove4)
                    goto jump2;
            }
            if(columnmove == 0 && rowmove < 0){
                if(row.new < invalidmove3)
                    goto jump2;
            }


            check2:
            if(r == 0 || c == 0 ){
                goto gs2;
            } else
                goto across2;

        gs2:
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
