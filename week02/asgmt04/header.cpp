#include "header.h"

void instructions()
/*
Pre:  None.
Post: Instructions for using the Life program have been printed.
*/

{
   std::cout << "Welcome to Conway's game of Life." << std::endl;
   std::cout << "This game uses a grid of size "
        << MAXROW << " by " << MAXCOL << " in which" << std::endl;
   std::cout << "each cell can either be occupied by an organism or not." << std::endl;
   std::cout << "The occupied cells change from generation to generation" << std::endl;
   std::cout << "according to the number of neighboring cells which are alive."
        << std::endl;
}


int **allocate_array(int maxrow, int maxcol){

   int **arr = new int *[maxrow];
   for(int i = 0; i<maxrow; i++){
      arr[i]=new int [maxcol];
   }

   return arr;

}

void delete_array(int** x){
delete [] *x;
delete [] x;
}

void erase_cin(int x){
      std::cin.clear();
      std::cin.ignore(x, '\n');
}

void zero_array(int** grid, int maxrow, int maxcol){
   int i = 0, j = 0;
   for (i; i < maxrow; i++)
      for (j = 0; j < maxcol; j++){
         grid[i][j] = 0;
   }
}