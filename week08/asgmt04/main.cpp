#include "header.h"

int main(){

    int x, y, result;
    
    std::cout << "Please give positive integer: ";
    x= getInteger();
    std::cout << "Give another positive integer: ";
    y = getInteger();
    
    
    result = rec_GCD(x, y);
    std::cout << "Common greates divisor for numbers for " << x 
        << " & " << y << " is: " << result << std::endl;


    return 0;
}