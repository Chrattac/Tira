#include "header.h"

int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
      the class Extended_queue.
Uses: The class Extended_queue and the functions introduction,
      get_command, and do_command.
*/

{
   Extended_queue test_queue;
   introduction();
   while (do_command(get_command(), test_queue));

   return 0;
}