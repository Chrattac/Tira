#pragma once

#include "header.h"

const int maxstack = 100;

typedef int Stack_entry;

class Stack {
public:
   Stack();
   Error_code pop();
   Error_code push(const Stack_entry &item);
   Error_code top(Stack_entry &item) const;
   bool empty() const;
   void clear(); //  Reset the stack to be empty.
   bool full() const ; //  If the stack is full, return true; else return false.
   int size() const;   //  Return the number of entries in the stack.

   friend Error_code copy_stack_C(Stack&, Stack&);

private:
   int count;
   Stack_entry entry[maxstack];
};