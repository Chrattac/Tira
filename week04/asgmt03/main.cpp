#include "header.h"

int main(){

    Stack s;
    Stack_entry a = 2;
    int i = 0;

    for(i=0; i<maxstack; i++){
        s.push(i%3);
    }

    if(full(s)){
        std::cout << "Stack on täynnä\n";

    }else{
        std::cout << "Stack ei ole täynnä\n";
    }

    printStack(s);

    std::cout << "Poistetaan luku 2\n";

    delete_all(s, a);

    printStack(s);
    return 0;

}