/**
*@brief This function is used to display the board.
*@param m Used to input/read the dimension(row) of the board.
*@paramn Used to input/read the dimension(column) of the board.

*/





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
