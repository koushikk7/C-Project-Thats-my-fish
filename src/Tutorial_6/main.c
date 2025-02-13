/** @file main.c
* @brief The application code.
* @author Group c.
* @bugs No bugs in the function.
*/
#include "gamerules.h"
#include "userinput.h"
#include "boardgenerator.h"
#include "placementphase.h"
#include "movementphase.h"

int main(){
    gamerules();

    userinput();

    printboard(player.row,player.column);

    placementphase(player.row,player.column);

    movementphase(player.row,player.column);

}
