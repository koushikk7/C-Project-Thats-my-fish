/**
*@brief This funtion controls the placement of penguin on the board.
*@param R Takes the input for row.
*@param C Takes the input for column.

*/




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
