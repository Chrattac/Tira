#include "header.h"

int main(){

    Stack s;
    int number;
    int i = 2;

    std::cout << "Please give an integer: ";
    while(!(std::cin >> number)){
            if(std::cin.fail()){
            std::cout << "Please give valid integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
    }

    while(i<=(number)){
        if(number%i == 0){
            number = (number/i);
            s.push(i);
        }
        else{
            while(i<=(number)){
                std::cout << ""; //en tiedä, miksi, mutta jostain syystä ohjelma toimii oikein, kun tähän väliin couttaa mitä tahansa, mutta muuten jättää vikan laskematta...
                if(isPrime(++i)){
                    break;
                }
            }
        }
    }

    if(s.size()!=1){
        std::cout << "Number you gave consists of following primes: ";
        printStack(s);
    }
    else{
        std::cout << "Number you gave was prime\n";
    }
    


    return 0;

}