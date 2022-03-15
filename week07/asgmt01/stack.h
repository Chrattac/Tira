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
protected:
   Node *top_node;
   int count;
};