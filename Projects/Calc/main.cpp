
#include "header.h"

int main(int argc, char* argv[])
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    char choice = '2';
    Stack stored_numbers;
    std::string input;
    bool cntn = true, simple;



    if(argc < 3 || argv[2] == "-p"){
        introduction();
        start:
        std::cin >> choice; 
        if(choice == '1') {
            simple = true;
            instructions(simple);
            while (do_command(get_command(), stored_numbers));
        }
        else if (choice == '2'){
            simple = false;
            instructions(simple);
            while(cntn){
                std::cin.clear();
                getline(std::cin, input, '\n');
                cntn = calculator(stored_numbers, input);
            }
        }
        else if(choice == '9'){
            std::cout << "Thank you, have a nice day!\n";
        }
        else{
            std::cout << "Wrong choice, try again!: ";
            goto start;
        }
    }
    else{
        std::string args = argv[1];
        for(int i = 2; i<argc; i++) {
            args+=' ';
            args+=argv[i];
        }
        args+= " =";

        calculator(stored_numbers, args);
    }

    return 0;
}       