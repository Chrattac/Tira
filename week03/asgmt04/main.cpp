#include "header.h"

int main(){
    int integer;
    std::stack<int> numbers;

    std::cout << "give integers in order, the program turns the order around.\n"
    << "Once you are ready simply type a integer that is smaller than previous one.\n";
    int i = 0;
    while(true){
        std::cin >> integer;
        if(std::cin.fail()){
            std::cout << "That's not an integer!\n";
            std::cin.clear();
        }

        if(numbers.size()==0) numbers.push(integer);
        else if(numbers.top()>integer) break;
        else numbers.push(integer);
    }

    std::cout << "Numbers were: ";
    while(!numbers.empty()){
        std::cout << numbers.top();
        numbers.pop();

        if(numbers.empty()) std::cout << "\n";
        else std::cout << ", ";
    }
}