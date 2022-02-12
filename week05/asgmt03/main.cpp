#include "header.h"

enum Values{Jan = 10, Apr = 30, Jun = 20, Sep = 50, Nov = 30};

int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
      the class Extended_queue.
Uses: The class Extended_queue and the functions introduction,
      get_command, and do_command.
*/

{

int revenue_A = 0, revenue_B = 0, temp;
const int amount = 100;
Extended_queue stock_A;
Stack stock_B;

// January:
temp = amount*Jan;
stock_A.append(temp);
stock_B.push(temp);

// April:
temp = amount*Apr;
stock_A.append(temp);
stock_B.push(temp);

// June:
temp = amount*Jun;
stock_A.retrieve_and_serve(revenue_A);
stock_B.pop_top(revenue_B);
revenue_A = temp-revenue_A;
revenue_B = temp-revenue_B;

// September: 
temp = amount*Sep;
stock_A.append(temp);
stock_B.push(temp);

// November
stock_A.retrieve_and_serve(temp);
temp = (amount*Nov)-temp;
revenue_A += temp;

stock_B.pop_top(temp);
temp=(amount*Nov)-temp;
revenue_B+=temp;

std::cout << "Total revenue is:"
      << "\nFor FIFO: " << revenue_A
      << "\nFor LIFO: " << revenue_B
      << "\n\n";

return 0;

}