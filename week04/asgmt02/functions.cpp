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