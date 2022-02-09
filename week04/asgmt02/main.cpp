#include "header.h"

int main(){

    Stack s1_A, s1_B, s1_C;
    Stack s2_A, s2_B, s2_C;
    Stack_entry x;
    int i;

    for(i = 1; i<maxstack; i++){
        s1_A.push(i);
        s1_B.push(i);
        s1_C.push(i);
    }
    auto start = std::chrono::high_resolution_clock::now();
    copy_stack_A(s1_A, s2_A);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    
    std::cout << "A took " << duration.count() << " microseconds \n";
    
    std::cout << "Contents of stacks top to bottom: \n";
    std::cout << "1:\t2:\n";

    for(i = 0; i<maxstack; i++){
        s1_A.top(x);
        s1_A.pop();
        std::cout << x << "\t";
        s2_A.top(x);
        s2_A.pop();
        std::cout << x << "\n";
    }

    start = std::chrono::high_resolution_clock::now();
    copy_stack_B(s1_B, s2_B);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "B took " << duration.count() << " microseconds \n";
    
    std::cout << "Contents of stacks top to bottom: \n";

    std::cout << "1:\t2:\n";
    for(i = 0; i<maxstack; i++){
        s1_B.top(x);
        s1_B.pop();
        std::cout << x << "\t";
        s2_B.top(x);
        s2_B.pop();
        std::cout << x << "\n";
    }

    start = std::chrono::high_resolution_clock::now();
    copy_stack_C(s1_C, s2_C);
    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "C took " << duration.count() << " microseconds \n";
    
    std::cout << "Contents of stacks top to bottom: \n";

    std::cout << "1:\t2:\n";

    for(i = 0; i<maxstack; i++){
        s1_C.top(x);
        s1_C.pop();
        std::cout << x << "\t";
        s2_C.top(x);
        s2_C.pop();
        std::cout << x << "\n";
    }
    

    return 0;
}