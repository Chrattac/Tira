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
      bool automate, again=true;
      double delay = 0;
      Life configuration;
      instructions();
      int maxrow = 0, maxcol = 0, millis=1000 , i=0; 
      double seconds = 1;
      uint8_t iterations;
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

      int **arr = allocate_array(maxrow, maxcol);

      std::cout << "Do you want to automate the progress?";
      automate = user_says_yes();
      if(automate){
            std::cout << "Please give update interval in seconds (0.5 - 5)";
            std::cin >> seconds;
            while(std::cin.fail() || !(1 <= seconds <= 5)){
                  std::cout << "Please give valid value (0.5 - 5): ";
                  std::cin >> seconds;
            }
            
            std::cout << "How many iterations do you want to automate? (max. 255): ";
            std::cin >> iterations;
            while(std::cin.fail()){
                  std::cout << "Please give valid amount (0 - 255): ";
                  std::cin >> seconds;
            }

            millis = (int)nearbyint(1000*seconds);
      }
      erase_cin(maxcol);

      configuration.initialize(arr, maxrow, maxcol);

      configuration.print();
      switch(automate){
            case 0:
            std::cout << "Continue viewing new generations? " << std::endl;
            again = user_says_yes();
            break;
            case 1:
            #ifdef _win32
            sleep(millis);
            #endif
            #ifdef linux
            usleep(millis*1000);
            #endif
            i++;
            break;
      }
      while (again || (i<=iterations)) {
      configuration.update();
      configuration.print();
      
            switch(automate){
                  case 0: 
                  std::cout << "Continue viewing new generations? " << std::endl;
                  again = user_says_yes();
                  break;
                  case 1:
                  #ifdef _win32
                  sleep(millis);
                  #endif
                  #ifdef linux
                  usleep(millis*1000);
                  #endif
                  i++;
                  break;
            }
            
            if(i == iterations) automate=false;
      }
      std::cout << "Do you want to save state?\n";
      
      if(user_says_yes()){
            std::string fname;
            std::cout << "please give file name: ";
            std::cin >> fname;
            configuration.save_to_file(fname);
      }
      delete_array(arr);

   
}