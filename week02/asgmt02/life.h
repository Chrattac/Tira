#pragma once

#include "header.h"

class Life {
public:
   void initialize(int**, const int&, const int&);
   void print() const;
   void update();
   int **read_from_file(const std::string&);
private:
   int **grid, maxrow, maxcol;
   int neighbor_count(int& row, int& col);
};