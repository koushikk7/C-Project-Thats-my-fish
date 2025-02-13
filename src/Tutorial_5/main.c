#include "gamerules.h"
#include "Userinput&data.h"
#include "boardgenerator.h"
#include "placement phase.h"
#include "movement phase.h"
int main(){
gamerules();

userinput();

printboard(player.row,player.column);

placementphase(player.row,player.column);

movementphase(player.row,player.column);
}