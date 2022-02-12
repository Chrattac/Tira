#pragma once

#include <random>

#include "../../utility.h"
#include "stack.h"
#include "queue.h"
#include "ex_queue.h"
#include "functions.h"

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(0,255); // guaranteed unbiased