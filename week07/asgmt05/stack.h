#pragma once

#include "header.h"

typedef int Stack_entry;

class Stack {
public:
   Stack();
   bool empty() const;
   Error_code push(const Stack_entry &item);
   Error_code pop();
   Error_code top(Stack_entry &item) const;
   int getSize();
protected:
   Node *top_node;
   int count;
};