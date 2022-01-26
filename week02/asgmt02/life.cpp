#include "header.h"
#include "life.h"



void Life::initialize(int** arr, const int& x, const int& y)
/*
Pre:  None.
Post: The Life object contains a configuration specified by the user.
*/
{   
   grid = arr;
   maxrow = x;
   maxcol = y;

   bool cntn = true;
   std::string line;
   int row, col, colMax=0;

   zero_array(grid, maxrow, maxcol);

   row = 0;
   col = 0;
   std::cout << "Write the rows below and press enter after each line" << std::endl;
   std::cout << "x for living cell, space for dead cell\n";
   std::cout << "Terminate the inputting with typing $\n" << std::endl;
   std::cout << "If you want to read configuration from file, just type r and press enter\n";
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
         if (line[col] == 'x'|| line[col] =='X'){
            grid[row][col] = 1;
         }
         else if(line[col]=='$'){
            cntn=false;
         }
         else if(line[col]=='r'||line[col]=='R'){
            delete_array(arr);
            std::string fname = "N/A";
            std::cout << "Give the name of the file: ";
            std::cin >> fname;
            grid = read_from_file(fname);

            cntn=false;
            break;
         }
      }

      row++;
      
      if (row == maxrow)
         cntn=false;
   }
}

void Life::print() const
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


void Life::update(){
    int row, col;
    int **new_grid = allocate_array(maxrow, maxcol);

    for (row = 0; row < maxrow; row++)
        for (col = 0; col < maxcol; col++)
            switch (neighbor_count(row, col)) {
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

int Life::neighbor_count(int& row, int& col)
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

int **Life::read_from_file(const std::string& x)
{  
   int **read_arr, i, j, rowmaxlength;

   std::fstream f;
   std::string line;
   std::vector<std::string> lines;
   f.open(x, std::ios::in);
   if(!f.is_open()){
      std::cout << "Failure at reading file, exitting program";
      EXIT_FAILURE;
   }

   
   while(getline(f, line, '\n')){
      lines.push_back(line);
      if(i == 0)
         rowmaxlength = lines[i].length();
      else
         rowmaxlength = rowmaxlength < lines[i].length() ? lines[i].length() : rowmaxlength;
      i++;
   }
   f.close();

   maxrow = lines.size()-1;
   maxcol = rowmaxlength;

   read_arr = allocate_array(maxrow, maxcol);
   zero_array(read_arr, maxrow, maxcol);
   
   
   std::cout << "Using grid " << lines[0];
   for (i=1; i<lines.size(); i++){
      for (j=0; j<lines[i].length();j++){
         switch (lines[i][j]){
            case 'x':
            read_arr[i-1][j]=1;
            break;
            default:
            read_arr[i-1][j]=0;
            break;
         }

      }
   }

   return read_arr;
}