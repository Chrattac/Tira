#pragma once

#include "header.h"

class Life {
public:
   void initialize(int**, const int&, const int&);
   void print() const;
   void update();
   int **read_from_file(const std::string&);
   void save_to_file(const std::string&) const;
private:
   int **grid, maxrow, maxcol;
   int neighbor_count(int& row, int& col);
};