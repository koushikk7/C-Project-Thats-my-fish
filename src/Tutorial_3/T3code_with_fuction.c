#include <stdio.h>
#include <stdlib.h>

int m, n;
int number_of_fish_on_the_ice_floe;
int number_of_players_on_the_ice_floe;
int number_of_fish_on_the_ice_floe;
int number_of_players_on_the_ice_floe;

void readingthename(char *player1, char *player2)
{
    printf("please enter your name: \n");
    scanf("%s", player1);
    printf("please enter your name: \n");
    scanf("%s", player2);
}

int readingboardrow(int m)
{

    printf("please enter number of rows : \n");
    scanf("%d", &m);
    return m;
}

int readingboardcolunm(int n)
{
    printf("please enter number of column : \n");
    scanf("%d", &n);
    return n;
}

void displayingboard(int m, int n)
{
    int number_of_fish_on_the_ice_floe[m][n];
    int number_of_players_on_the_ice_floe[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            number_of_players_on_the_ice_floe[i][j] = 0;
            number_of_fish_on_the_ice_floe[i][j] = rand() % 3 + 1;
            printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], number_of_players_on_the_ice_floe[i][j]);
        }
        printf("\n");
    }
}

void changeplayer()
{
}

void placement(int R, int C)
{
    int *tempRow, *tempColumn;
    for (int k = 0; k < (m * n); k++)
    {
        printf("where do you want to place the penguin (format: enter row and column): ");
        scanf("%d %d", &tempRow, &tempColumn);
        number_of_players_on_the_ice_floe[tempRow][tempColumn] = 1;
        for (int *i = 0; i < m; i++)
        {
            for (int *j = 0; j < n; j++)
            {
                printf("%d%d ", number_of_fish_on_the_ice_floe[i][j], number_of_players_on_the_ice_floe[i][j]);
            }
            printf("\n");
        }
    }
}

void illegalmoves()
{
}

void collectfish()
{
}

void addpointstoplayer()
{
}

void removeiceflow()
{
}

void declarewinner()
{
}
int main()
{

    int f, g, R, C, k, t;
    char player1_name[20];
    char player2_name[20];
    int player_number = 1;
    int collected_fish = 0;
    readingthename(player1_name, player2_name);
    k = readingboardrow(f);
    t = readingboardcolunm(g);
    displayingboard(k, t);

    printf("\t\tThe placement phase begins\t\n");
    placement(R, C);
}
