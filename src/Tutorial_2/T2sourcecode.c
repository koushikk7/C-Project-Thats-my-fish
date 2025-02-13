#include <stdio.h>
#include <stdlib.h>
int main() {
    int m, n;
    char player_name[20];
    int player_number = 1;
    int collected_fish = 0;
    printf("please enter your name: ");
    scanf("%s", player_name);
    printf("please enter number of rows and columns to be shown on the board (format: enter row and column): ");
    scanf("%d %d", &m, &n);
    printf("Number of rows = %d, Number of columns = %d\n", m,n);
    int number_of_fish_on_the_ice_floe[m][n];
    int number_of_players_on_the_ice_floe[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            number_of_players_on_the_ice_floe[i][j] = 0;
            number_of_fish_on_the_ice_floe[i][j] = rand() % 3 + 1;
            printf("%d%d ",number_of_fish_on_the_ice_floe[i][j], number_of_players_on_the_ice_floe[i][j]);
        }
        printf("\n");
    }
    printf("player ID = %s\n", player_name);
    printf("player number = %d\n", player_number);
    printf("Number of fish collected = %d\n", collected_fish);


    // placement phase

    int tempRow, tempColumn;
    for(int k = 0; k < (m*n); k++) {
        printf("where do you want to place the penguin (format: enter row and column): ");
        scanf("%d %d", &tempRow, &tempColumn);
        number_of_players_on_the_ice_floe[tempRow][tempColumn] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d%d ",number_of_fish_on_the_ice_floe[i][j], number_of_players_on_the_ice_floe[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
