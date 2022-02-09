#pragma once

#include "header.h"

Error_code copy_stack_A(Stack&, Stack&);
Error_code copy_stack_B(Stack&, Stack&);
Error_code copy_stack_C(Stack&, Stack&);

bool full(Stack&);
Error_code pop_top(Stack&, Stack_entry&);
void clear(Stack&);
int size(Stack&);
void delete_all(Stack&, Stack_entry&);

void printStack(Stack&);