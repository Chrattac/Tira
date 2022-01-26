#include "header.h"

int main()  //  Program to play Conway's game of Life.
/*
Pre:  The user supplies an initial configuration of living cells.
Post: The program prints a sequence of pictures showing the changes in
      the configuration of living cells according to the rules for
      the game of Life.
Uses: The class Life and its methods initialize(), print(), and update().
      The functions  instructions(),  user_says_yes().
*/

{


      Life configuration;
      instructions();
      int maxrow = 0, maxcol = 0;
      do{
            std::cout << "Give dimension of the grid wanted: \nRows:";
            std::cin >> maxrow;
            std::cout << "Columns: ";
            std::cin >> maxcol;
            if(!(0<=maxcol<MAXCOL) || !(0<=maxcol<MAXCOL) || std::cin.fail()){

                  std::cout << "\n\n****************************************\n";
                  std::cout << "Rows should be in between 0 and " << MAXROW;
                  std::cout << "\nColumns should be in between 0 and " << MAXCOL;
                  std::cout << "\nPlease give valid dimensions\n";
                  std::cout << "****************************************\n\n";
                  erase_cin(MAXROW);
            }
      }while((maxcol > MAXCOL || maxcol <= 0) || (0 > maxrow > MAXROW || maxrow <= 0));

      erase_cin(maxcol);
      int **arr = allocate_array(maxrow, maxcol);

      configuration.initialize(arr, maxrow, maxcol);

      configuration.print();
      std::cout << "Continue viewing new generations? " << std::endl;
      while (user_says_yes()) {
      configuration.update();
      configuration.print();
      std::cout << "Continue viewing new generations? " << std::endl;
   }
      delete_array(arr);
   
}