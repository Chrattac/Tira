#include "header.h"

Error_code copy_stack_A(Stack& x, Stack& y){

    y = x;
    return success;
}

Error_code copy_stack_B(Stack& x, Stack& y){
    Stack temp;
    int d;
    y.clear();

    for(int i = 0; i<x.size(); i++)
        x.top(d);
        temp.push(d);
        x.pop();

    for(int i = 0; i<temp.size(); i++){
        temp.top(d);
        y.push(d);
        x.push(d);
        temp.pop();
    }

    return success;

}

Error_code copy_stack_C(Stack& x, Stack& y){

    if (x.count == 0){
        return underflow;
    }else{
        for(int i = 0; i< x.count; i++){
            y.entry[i] = x.entry[i];
            //y.count++;
        }
    }

    return success;

}

// ASGMT 02:
bool full(Stack& x){

    return x.full();
}

Error_code pop_top(Stack& x, Stack_entry& y){
    if(x.size() == 0){
        return underflow;
    }
    else{
        x.top(y);
        x.pop();
        return success;
    }
}

void clear(Stack& x){
    x.empty();
}

int size(Stack& x){
    return x.size();
}

void delete_all(Stack& x, Stack_entry& y){
    Stack temp;
    Stack_entry d;
    
    for (int i = 0; i<maxstack;i++){
        if(!x.empty()){
            pop_top(x, d);
            if(d != y){
                temp.push(d);
            }
        }else {break;}
    }

    for(int i = 0; i<maxstack;i++){
        if(!temp.empty()){
            pop_top(temp, d);
            x.push(d);
        }else{break;}
    }

}

// Extra
void printStack(Stack& s){
    int tempInt;
    Stack tempStack;

    copy_stack_A(s, tempStack);

    for(int i=0; i<maxstack;i++){
        pop_top(s, tempInt);
        std::cout << tempInt;
        if(!s.empty()){
            std::cout << ", ";
        }else{
            std::cout << "\n";
            break;
        }
    }

    copy_stack_A(tempStack, s);

}

bool isPrime(int& x){
    bool prime;
    if(x == 2){
        prime = true;
    }
    else{
        for (int i = 2; i<(x/2); i++){
            if(x%i==0){
                prime = false;
                break;
            }else{prime == true;}
        }
    }



    return prime;
}