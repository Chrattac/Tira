#pragma once

#include "header.h"

class Extended_queue: public Queue {
public:
   bool full() const;
   int size() const;
   void clear();
   Error_code serve_and_retrieve(Queue_entry &item);
   Error_code retrieve_and_serve(Queue_entry &item);
};