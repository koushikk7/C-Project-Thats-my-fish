/** @file possiblemoves.c
* @brief This function is checks whether all the penguins are blocked or not.
* @brief This function returns 1 if all the penguins of player 1 are blocked, returns 2 if all the penguins of player 2 are blocked and returns 3 if all the penguins are blocked.
* @bugs No bugs in the function.
* @see main.c
*/


#include "movementphase.h"
#include "possiblemoves.h"
int possiblemoves(int m, int n){
    p1.xp = 0;
    p1.xn = 0;
    p1.yp = 0;
    p1.yn = 0;
    p2.xp = 0;
    p2.xn = 0;
    p2.yp = 0;
    p2.yn = 0;


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(player.position[i][j] == 1){
                if (j == n-1){
                    p1.xp++;
                }
                else if(player.position[i][j+1] == 1 || player.position[i][j+1] == 2 || (player.position[i][j+1] == 0 && fish.amount[i][j+1] == 0)){
                    p1.xp++;
                }
                if (j == 0){
                    p1.xn++;
                }
                else if(player.position[i][j-1] == 1 || player.position[i][j-1] == 2 || (player.position[i][j-1] == 0 && fish.amount[i][j-1] == 0)){
                    p1.xn++;
                }
                if (i == 0){
                    p1.yp++;
                }
                else if(player.position[i-1][j] == 1 || player.position[i-1][j] == 2 || (player.position[i-1][j] == 0 && fish.amount[i-1][j] == 0)){
                    p1.yp++;
                }
                if (i == m-1){
                    p1.yn++;
                }
                else if(player.position[i+1][j] == 1 || player.position[i+1][j] == 2 || (player.position[i+1][j] == 0 && fish.amount[i+1][j] == 0)) {
                    p1.yn++;
                }
            }
            if(player.position[i][j] == 2){

                if (j == n-1){
                    p2.xp++;
                }
                else if(player.position[i][j+1] == 1 || player.position[i][j+1] == 2 || (player.position[i][j+1] == 0 && fish.amount[i][j+1] == 0)){
                    p2.xp++;
                }
                if (j == 0){
                    p2.xn++;
                }
                else if(player.position[i][j-1] == 1 || player.position[i][j-1] == 2 || (player.position[i][j-1] == 0 && fish.amount[i][j-1] == 0)){
                    p2.xn++;
                }
                if (i == 0){
                    p2.yp++;
                }
                else if(player.position[i-1][j] == 1 || player.position[i-1][j] == 2 || (player.position[i-1][j] == 0 && fish.amount[i-1][j] == 0)){
                    p2.yp++;
                }
                if (i == m-1){
                    p2.yn++;
                }
                else if(player.position[i+1][j] == 1 || player.position[i+1][j] == 2 || (player.position[i+1][j] == 0 && fish.amount[i+1][j] == 0)) {
                    p2.yn++;
                }
            }

        }
    }

    int p1possiblemoves, p2possiblemoves, x;
    x = (player.penguins*2)*4;
    p1possiblemoves = p1.xn+p1.xp+p1.yp+p1.yn;
    p2possiblemoves = p2.xn+p2.xp+p2.yp+p2.yn;

    if ((p1possiblemoves + p2possiblemoves == x)){
        return 3;
    }
    if(p1possiblemoves == x/2){
        return 1;
    }
    if(p2possiblemoves == x/2){
        return 2;
    }
    else return 4;

}
