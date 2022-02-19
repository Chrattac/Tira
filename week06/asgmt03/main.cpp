#include "header.h"

int main(){
    std::string s;

    std::cout << "Test program for excercise 3: ";
    getline(std::cin, s, '\n');

    std::cout << "Input\t\t\tOutput\n";
    std::cout << s << "\t\t" << compareInput(s) << '\n';


    return EXIT_SUCCESS;
}