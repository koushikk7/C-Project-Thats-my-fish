//
// Created by Koushik on 03/06/2021.
//

#ifndef T6_MOVEMENTPHASE_H
#define T6_MOVEMENTPHASE_H

#include <stdio.h>
#include "userinput.h"
#include "boardgenerator.h"
#include "placementphase.h"

struct new{
    int current, new;
}row, column;

int movementphase(int m, int n);

#endif //T6_MOVEMENTPHASE_H
