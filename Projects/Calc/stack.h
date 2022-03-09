#pragma once

#include "header.h"

typedef double Stack_entry;
const int maxstack = 100;

class Stack {
public:
   Stack();
   Error_code pop();
   Error_code push(const Stack_entry item);
   Error_code top(Stack_entry& item) const;
   Error_code pop_top(Stack_entry&);
   bool empty() const;
   void clear(); //  Reset the stack to be empty.
   bool full() const ; //  If the stack is full, return true; else return false.
   int size() const;   //  Return the number of entries in the stack.
   void print() const; 

private:
   int count;
   Stack_entry entry[maxstack];
};