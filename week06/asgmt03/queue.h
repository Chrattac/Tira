#pragma once

#include "header.h"

typedef char Queue_entry;
const int maxqueue = 100;

class Queue {
public:
   Queue();
   bool empty() const;
   Error_code serve();
   Error_code append(const Queue_entry &item);
   Error_code retrieve(Queue_entry &item);

protected:
   int count;
   int front, rear;
   Queue_entry entry[maxqueue];
};