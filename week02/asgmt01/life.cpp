#include "header.h"
#include "life.h"



void Life::initialize(int** arr, const int& maxrow, const int& maxcol)
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/
{   
   grid = arr;

   bool cntn = true;
   std::string line;
   int row, col, colMax=0;
   for (row = 0; row < maxrow; row++)
      for (col = 0; col < maxcol; col++){
         grid[row][col] = 0;
   }

   row = 0;
   col = 0;
   std::cout << "Write the rows below and press enter after each line" << std::endl;
   std::cout << "x for living cell, space for dead cell\n";
   std::cout << "Terminate the inputting with typing $" << std::endl;
   std::cout << "Type row:\n";

   while(cntn){
      std::cout << "row#:" << row+1;
      getline(std::cin, line, '\n');

      colMax = line.length();

      if(line.length() >= maxrow){
         std::cout << "Given line was longer than expected,\nusing only first " << maxcol << " characters\n";
         colMax = maxcol;
      }

      for(col = 0; col<colMax; col++){
         if (line[col] == 'x'){
            grid[row][col] = 1;
         }
         else if(line[col]=='$'){
            cntn=false;
         }
      }

      row++;

      if (row == maxrow)
         cntn=false;
   }
}

void Life::print(const int& maxrow, const int& maxcol) const
/*
Pre:  The Life object contains a configuration.
Post: The configuration is written for the user.
*/

{
   int row, col;
   std::cout << "\nThe current Life configuration is:" <<std::endl;
   for (row = 0; row < maxrow; row++) {
      for (col = 0; col < maxcol; col++)
         if (grid[row][col] == 1) std::cout << '@';
         else std::cout << ' ';
      std::cout << std::endl;
   }
   std::cout << std::endl;
}


void Life::update(const int& maxrow, const int& maxcol){
    int row, col;
    int **new_grid = allocate_array(maxrow, maxcol);

    for (row = 0; row < maxrow; row++)
        for (col = 0; col < maxcol; col++)
            switch (neighbor_count(row, col, maxrow, maxcol)) {
                case 2:
                    new_grid[row][col] = grid[row][col];  //  Status stays the same.
                    break;
                case 3:
                    new_grid[row][col] = 1;                //  Cell is now alive.
                    break;
                default:
                    new_grid[row][col] = 0;                //  Cell is now dead.
            }

    for (row = 0; row < maxrow; row++)
        for (col = 0; col < maxcol; col++)
            grid[row][col] = new_grid[row][col];
   delete_array(new_grid);
}

int Life::neighbor_count(int& row, int& col, const int& maxrow, const int& maxcol)
/*
Pre:  The Life object contains a configuration, and the coordinates
      row and col define a cell inside its hedge.
Post: The number of living neighbors of the specified cell is returned.
*/

{
   int i, j, imax, jmax;

   if (row == 0){
      i = row;
      imax = row+1;
   }
   else if(row == maxrow-1){
      i = row-1;
      imax = row;
   }
   else{
      i = row-1;
      imax = row+1;
   }

   int count = 0;

   for (i; i<=imax; i++){
      if(col == 0){
      j=col;
      jmax=col+1;
      }
      else if(col == maxcol-1){
      j = col-1;
      jmax = col;
      } 
      else{
      j = col-1;
      jmax = col+1;
      }

      for (j; j <= jmax; j++){
         count += grid[i][j];  //  Increase the count if neighbor is alive.
      }
   }
   count -= grid[row][col]; //  Reduce count, since cell is not its own neighbor.
   return count;
}