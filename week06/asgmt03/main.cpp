#include "header.h"

int main(){
    std::string s;

    std::cout << "Testiohjelma: ";
    getline(std::cin, s, '\n');

    std::cout << "Input\t\t\tOutput\n";
    std::cout << s << "\t\t" << compareInput(s) << '\n';


    return EXIT_SUCCESS;
}