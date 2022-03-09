#pragma once

#include <cmath>

#include "utility.h"
#include "stack.h"
#include "functions.h"

const int OPERATORS_SIZE = 12;
const char operators[OPERATORS_SIZE] = 
    {
    '-', '+', '*', '/', '=', '%', 
    '^', 'v', 'a', 's', 'q', 'x'
    };