/** @file userinput.c
* @brief The function takes the input from the user.
* @brief It takes the name of both the player, and also takes the number of rows and columnn.
* @author group c.
* @bugs No bugs in the function.
*/

#include "userinput.h"

void userinput() {
    fish.total = 0;
    player1.number = 1;
    player2.number = 2;
    player1.name = (char *) malloc(Maxcharacters * sizeof(char));
    player2.name = (char *) malloc(Maxcharacters * sizeof(char));

    printf("Player 1 - Enter you name: ");
    fgets(player1.name, Maxcharacters+1, stdin);

    if(strlen(player1.name)>=25){
         while ((player1.c = getchar()) != '\n' && player1.c != EOF);
         }
    player1.name[strcspn(player1.name, "\n")] = 0;

    printf("Player 2 - Enter your name: ");
    fgets(player2.name, Maxcharacters+1, stdin);

    if(strlen(player2.name)>=25){
        while ((player2.c = getchar()) != '\n' && player2.c != EOF);
    }

    player2.name[strcspn(player2.name, "\n")] = 0;


   printf("\nEnter number of Rows: ");
   while(scanf("%d",&player.row) == 0 || player.row < 2) {
           getchar();
           printf("Invalid input\n");
           printf("Enter number of Rows: ");

   }

    printf("Enter number of Columns: ");
    while(scanf("%d",&player.column) == 0 || player.column< 2) {
            getchar();
            printf("Invalid input\n");
            printf("Enter number of Columns: ");
    }
    printf("\n");

    /*  int p;
        printf("Enter number of penguins: ");
        while(scanf("%d", &p) == 0 || p<0){
            printf("Invalid input");
            printf("Enter number of penguins: ");
        }
        player.penguins = p / 2;        */

   player.penguins = player.row/2;

}
