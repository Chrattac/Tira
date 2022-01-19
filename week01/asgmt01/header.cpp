#include "header.h"

void instructions()
/*
Pre:  None.
Post: Instructions for using the Life program have been printed.
*/

{
   std::cout << "Welcome to Conway's game of Life." << std::endl;
   std::cout << "This game uses a grid of size "
        << maxrow << " by " << maxcol << " in which" << std::endl;
   std::cout << "each cell can either be occupied by an organism or not." << std::endl;
   std::cout << "The occupied cells change from generation to generation" << std::endl;
   std::cout << "according to the number of neighboring cells which are alive."
        << std::endl;
}