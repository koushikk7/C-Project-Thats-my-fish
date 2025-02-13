#include <stdio.h>
#include <stdlib.h>


int m = 5, n = 5;
int total_fish = 0;
int number_of_penguins = 5;
int player_0 = 0;


int fun1board(int* number_of_fish_on_the_ice_floe[m][n],int* player_number_on_the_ice_floe[m][n])
{

struct GameState
{
    int m,n;
    int num_players;

}gs;

    gs.m= 5;
    gs.n= 5;
    gs.num_players= 2;

    int **board;

    board =  malloc ( gs.m * sizeof(int*));

    
    for ( int i = 0; i < gs.m; i++)      
    {
    board[i] =  malloc ( gs.n * sizeof(int));

    int number_of_fish_on_the_ice_floe[m][n];
    int player_number_on_the_ice_floe[m][n];
    for (int i = 0; i <m; i++) {
        for (int j = 0; j < n; j++) {
            player_number_on_the_ice_floe[i][j] = player_0;
            number_of_fish_on_the_ice_floe[i][j] = rand() % 3 + 1;
            total_fish = total_fish + number_of_fish_on_the_ice_floe[i][j];
            printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], player_number_on_the_ice_floe[i][j]);
        }
        printf("\n");
        
     //return number_of_fish_on_the_ice_floe[m][n];
     //return player_number_on_the_ice_floe[m][n];

    }
    }
}
    


int main() 
{

    int number_of_fish_on_the_ice_floe[m][n];
    int player_number_on_the_ice_floe[m][n];
    
    char player_1_name[20];
    char player_2_name[20];
    int  player_1 = 1, player_2 = 2;
    int collected_fish_1 = 0;
    int collected_fish_2 = 0;
    printf("player 1 - please enter your name: ");
    scanf("%s", player_1_name);
    printf("player 2 - please enter your name: ");
    scanf("%s", player_2_name);
    printf("\n");

    
    fun1board(number_of_fish_on_the_ice_floe[m][n], player_number_on_the_ice_floe[m][n]);
    
    
    printf("\n");


    // placement phase

    int tempRow, tempColumn;
    for (int k = 0; k < (number_of_penguins * 2); k++) {
        if (k % 2 == 0) {
            printf("current player: %d\n", player_1);
            printf("current player name: %s\n", player_1_name);
            printf("where do you want to place the penguin (format: enter row and column): ");
            scanf("%d %d", &tempRow, &tempColumn);
            while (tempRow >= m || tempColumn >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &tempRow, &tempColumn);
            }
            while (player_number_on_the_ice_floe[tempRow][tempColumn] == player_1 ||
                   player_number_on_the_ice_floe[tempRow][tempColumn] == player_2) {
                printf("this place has been occupied!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &tempRow, &tempColumn);
                while (tempRow >= m || tempColumn >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &tempRow, &tempColumn);
                }
            }
            player_number_on_the_ice_floe[tempRow][tempColumn] = player_1;
            collected_fish_1 = number_of_fish_on_the_ice_floe[tempRow][tempColumn] + collected_fish_1;
            number_of_fish_on_the_ice_floe[tempRow][tempColumn] = player_0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], player_number_on_the_ice_floe[i][j]);
                }
                printf("\n");
            }
            printf("fish collected by player 1: %d\n\n", collected_fish_1);
        }
        else {
            printf("current player: %d\n", player_2);
            printf("current player name: %s\n", player_2_name);
            printf("where do you want to place the penguin (format: enter row and column): ");
            scanf("%d %d", &tempRow, &tempColumn);
            while (tempRow >= m || tempColumn >= n) {
                printf("input the correct row and column!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &tempRow, &tempColumn);
            }
            while (player_number_on_the_ice_floe[tempRow][tempColumn] == player_1 || player_number_on_the_ice_floe[tempRow][tempColumn] == player_2) {
                printf("this place has been occupied!\n");
                printf("where do you want to place the penguin (format: enter row and column): ");
                scanf("%d %d", &tempRow, &tempColumn);
                while (tempRow >= m || tempColumn >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &tempRow, &tempColumn);
                }
            }
            player_number_on_the_ice_floe[tempRow][tempColumn] = player_2;
            collected_fish_2 = number_of_fish_on_the_ice_floe[tempRow][tempColumn] + collected_fish_2;
            number_of_fish_on_the_ice_floe[tempRow][tempColumn] = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], player_number_on_the_ice_floe[i][j]);
                }
                printf("\n");
            }
            printf("fish collected by player 2: %d\n\n", collected_fish_2);
        }
    }
    printf("total fish collected by player 1 during placement phase: %d\n", collected_fish_1);
    printf("total fish collected by player 2 during placement phase: %d\n\n", collected_fish_2);
    printf("board after placement phase:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], player_number_on_the_ice_floe[i][j]);
        }
        printf("\n");
    }
    printf("\n");

        //movement phase

    for (int k = 0; k < m*n; k++) {
            int current_Row, new_Row, current_Column, new_Column;
            if(collected_fish_1+collected_fish_2 == total_fish)
                break;
            if (k % 2 == 0) {
                printf("current player: %d\n", player_1);
                printf("current player name: %s\n", player_1_name);
                printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                scanf("%d %d", &current_Row, &current_Column);
                while (current_Row >= m || current_Column >= n) {
                    printf("input the correct row and column!\n");
                    printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                    scanf("%d %d", &current_Row, &current_Column);
                }
                while (player_number_on_the_ice_floe[current_Row][current_Column] != player_1) {
                    printf("pick the the correct penguin!\n");
                    printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                    scanf("%d %d", &current_Row, &current_Column);
                    while (current_Row >= m || current_Column >= n) {
                        printf("input the correct row and column!\n");
                        printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                        scanf("%d %d", &current_Row, &current_Column);
                    }
                }
                printf("where do you want to move this penguin to? (format: enter row and column): ");
                scanf("%d %d", &new_Row, &new_Column);
                while (new_Row >= m || new_Column >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to move this penguin to? (format: enter row and column): ");
                    scanf("%d %d", &new_Row, &new_Column);
                }
                while (player_number_on_the_ice_floe[new_Row][new_Column] == player_0 && number_of_fish_on_the_ice_floe[new_Row][new_Column] == player_0) {
                    printf("the tile does not exist\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &new_Row, &new_Column);
                }
                while (player_number_on_the_ice_floe[new_Row][new_Column] != player_0) {
                        printf("the place is occupied!\n");
                        printf("where do you want to place the penguin (format: enter row and column): ");
                        scanf("%d %d", &new_Row, &new_Column);
                        while (new_Row >= m || new_Column >= n) {
                            printf("input the correct row and column!\n");
                            printf("where do you want to place the penguin (format: enter row and column): ");
                            scanf("%d %d", &new_Row, &new_Column);
                        }
                    }
                    player_number_on_the_ice_floe[current_Row][current_Column] = player_0;
                    player_number_on_the_ice_floe[new_Row][new_Column] = player_1;
                    collected_fish_1 = number_of_fish_on_the_ice_floe[new_Row][new_Column] + collected_fish_1;
                    number_of_fish_on_the_ice_floe[new_Row][new_Column] = player_0;
                    for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                            printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], player_number_on_the_ice_floe[i][j]);
                        }
                        printf("\n");
                    }
                    printf("collected fish by player 1: %d\n\n", collected_fish_1);
                }

            else {

                printf("current player: %d\n", player_2);
                printf("current player name: %s\n", player_2_name);
                printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                scanf("%d %d", &current_Row, &current_Column);
                while (current_Row >= m || current_Column >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &current_Row, &current_Column);
                }
                while (player_number_on_the_ice_floe[current_Row][current_Column] != player_2) {
                    printf("pick the the correct penguin!\n");
                    printf("which penguin do you want to move? (format: enter the row and column where the penguin that you want to move exists): ");
                    scanf("%d %d", &current_Row, &current_Column);
                    while (current_Row >= m || current_Column >= n) {
                        printf("input the correct row and column!\n");
                        printf("where do you want to place the penguin (format: enter row and column): ");
                        scanf("%d %d", &current_Row, &current_Column);
                    }
                }
                printf("where do you want to move this penguin to? (format: enter row and column): ");
                scanf("%d %d", &new_Row, &new_Column);
                while (new_Row >= m || new_Column >= n) {
                    printf("input the correct row and column!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &new_Row, &new_Column);
                }
                while (player_number_on_the_ice_floe[new_Row][new_Column] == player_0 && number_of_fish_on_the_ice_floe[new_Row][new_Column] == player_0) {
                    printf("the tile does not exist\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &new_Row, &new_Column);
                }
                while (player_number_on_the_ice_floe[new_Row][new_Column] != player_0) {
                    printf("the place is occupied!\n");
                    printf("where do you want to place the penguin (format: enter row and column): ");
                    scanf("%d %d", &new_Row, &new_Column);
                    while (new_Row >= m || new_Column >= n) {
                        printf("input the correct row and column!\n");
                        printf("where do you want to place the penguin (format: enter row and column): ");
                        scanf("%d %d", &new_Row, &new_Column);
                    }
                }
                player_number_on_the_ice_floe[current_Row][current_Column] = player_0;
                player_number_on_the_ice_floe[new_Row][new_Column] = player_2;
                collected_fish_2 = number_of_fish_on_the_ice_floe[new_Row][new_Column] + collected_fish_2;
                number_of_fish_on_the_ice_floe[new_Row][new_Column] = player_0;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], player_number_on_the_ice_floe[i][j]);
                    }
                    printf("\n");
                }
                printf("number of fish collected by player 2: %d\n\n", collected_fish_2);

            }
        }

        printf("total fish collected by player 1: %d\n", collected_fish_1);
        printf("total fish collected by player 2: %d\n", collected_fish_2);
        if (collected_fish_1 > collected_fish_2) {
            printf("%s has won", player_1_name);
        } else if (collected_fish_1 < collected_fish_2) {
            printf("%s has won", player_2_name);
        } else
            printf("it's a draw");
        return 0;
    
    
}

