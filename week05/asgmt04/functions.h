#pragma once

#include "header.h"

void introduction();
void help();
bool do_command(char, Extended_queue&);
char get_command();

// ASGMT4 functions:

Error_code stack_to_queue(Stack&, Extended_queue&);
Error_code queue_to_stack(Extended_queue&, Stack&);
Error_code pile_stack(Stack&, Stack&);
Error_code pile_stack_rev(Stack&, Stack&);
Error_code rev_queue(Extended_queue&);
Error_code rev_stack(Stack&);