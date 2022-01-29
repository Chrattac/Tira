#include   "header.h"

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
    // Kolmonen on täsmälleen sama kuin ykkönen, koska kikkailin ykkösen jo aikaisemmin käsittelemään lauseen 
    // lauseen tehtävän tarkoittamalla tavalla, lisäksi ei ota huomioon välimerkkejä eikä välilyöntejä
    // ihmetellessään palindromia. 

    bool palindrome = true;
    std::string item;
    std::stack<char> c;  //  declares and initializes a stack of numbers

    std::cout << " Type in an sentence." << std::endl
        << " The sentence will be printed in reverse order." << std::endl;
    getline(std::cin, item, '\n');

    for (int i = 0; i < item.length(); i++) {
      c.push(item[i]);
    }

    std::cout << "\n\n";
    int i = 0;
    while (!c.empty()) {
        std::cout << c.top();
        if(item.at(i) == ' ' || ispunct(item.at(i))){i++;}

        if(c.top() != item[i] && !(c.top() == ' ' || ispunct(c.top()))){
            palindrome=false;
        }

        if(!(c.top() == ' ' || ispunct(c.top()))){i++;}

        c.pop();
    }

    if(palindrome) std::cout << "\n\nYour sentence was a palindrome!\n";
    else std::cout << "\n\nYour sentence wasn't a palindrome!\n";

    std::cout << std::endl;
}