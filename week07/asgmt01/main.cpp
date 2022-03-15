#include "header.h"

enum Values{Jan = 10, Apr = 30, Jun = 20, Sep = 50, Nov = 30};

int main()
{

int revenue_B = 0, temp;
const int amount = 100;
Stack stock_B;

// January:
temp = amount*Jan;
stock_B.push(temp);

// April:
temp = amount*Apr;
stock_B.push(temp);

// June:
temp = amount*Jun;
stock_B.top(temp);
stock_B.pop();
revenue_B = temp-revenue_B;

// September: 
temp = amount*Sep;
stock_B.push(temp);

// November
stock_B.top(temp);
stock_B.pop();
temp=(amount*Nov)-temp;
revenue_B+=temp;

std::cout << "Total revenue is:"
      << "\nFor LIFO: " << revenue_B
      << "\n\n";

return 0;

}