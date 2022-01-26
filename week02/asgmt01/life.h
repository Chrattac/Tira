#pragma once

#include "header.h"

class Life {
public:
   void initialize(int**, const int&, const int&);
   void print(const int&, const int&) const;
   void update(const int&, const int&);
private:
   int **grid;
   int neighbor_count(int& row, int& col, const int& maxrow, const int& maxcol);
};