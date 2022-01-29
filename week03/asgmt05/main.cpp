#include "header.h"

int main(){
    Extended_stack es;

    for(int i = 0; i<maxstack; i++) es.push(i);

    std::cout << "Is stack full? " << es.full() << "\n";
    std::cout << "How many items in es? " << es.size() << "\n";
    std::cout << "Let's clear es\n";
    es.clear();
    std::cout << "How many items in es? " << es.size() << "\n";

    for(int i = 0; i<maxstack; i++) es.push(i);
    std::cout << "How many items in es? " << es.size() << "\n"; //Ei kaadu, vaikka varoittelee nullista...

    return 0;
}