#include "header.h"

int main(){

    cntn;
    Stack s;
    Stack_entry a = 2;

    
    std::cout << "Please give a integer: ";
    do{
        std::cin >> number;
        if(std::cin.fail()){
            std::cout << "Please give valid integer: ";
            cntn=false;
        }else{cntn=true;}
        
    }while(!cntn);

}