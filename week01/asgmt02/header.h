#pragma once

#include "../../utility.h"
#include "life.h"

#define MAXROW 100
#define MAXCOL 100

void instructions();
int **allocate_array(int, int);
void delete_array(int**);