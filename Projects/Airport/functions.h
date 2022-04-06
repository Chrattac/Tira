#pragma once

#include "header.h"

void initialize(int &end_time, int &queue_limit,double &arrival_rate, double &departure_rate, int &runway_count);
void run_idle(int time, int runway_number);
char get_command(); 
int get_positive_int();

void start_simulation(int &end_time, int &queue_limit,double &arrival_rate, double &departure_rate, int runway_count);