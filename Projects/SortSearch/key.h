#pragma once

#include "header.h"

class Key {
private:
   int key;
public:
   static int comparisons;
   Key();
   Key(int x);
   int get_key() const;
   void set_key(int x);
};

