#pragma once

#include <vector>

#include "../../utility.h"
#include "life.h"

#define MAXROW 100
#define MAXCOL 100

void instructions();
int **allocate_array(int, int);
void zero_array(int* [], int, int);
void delete_array(int**);
void erase_cin(int);