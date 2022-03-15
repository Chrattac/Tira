#include "header.h"

// Excercise 3 was to add "clear" and "retrieve_and_serve" -methods
// Did them on Ex 2.

int main(){
    //Testing that methods work
    Extended_queue q = Extended_queue();
    int temp, tempq;

    if(q.empty()) std::cout << "Queue is empty\n";

    for (int i = 0; i<10; i++) q.append(i); 

    if(!q.full()) std::cout << "Queue is not full\n";

    q.serve_and_retrieve(temp);
    std::cout << "q temp 1: " << temp << std::endl;
    q.serve_and_retrieve(temp);
    std::cout << "q temp 2: " << temp << std::endl;
    q.serve();

    
    Extended_queue p(q);

    p.serve_and_retrieve(temp);
    std::cout << "p temp 1: " << temp << std::endl;
    std::cout << "p address 1: " << &q << std::endl;   
    p.retrieve_and_serve(temp);
    std::cout << "p temp 2: " << temp << std::endl;    
    q.retrieve(temp);
    std::cout << "q address 3:" << &q << std::endl;
    std::cout << "q temp 3: " << temp << std::endl;
    q.serve();

    p.append(100);
    q.append(150);
    p.append(200);

    int j=0;
    while(!p.empty() && !q.empty()){
        j++;
        
        p.retrieve_and_serve(temp);
        q.retrieve_and_serve(tempq);
        
        std::cout << "p int while, temp " << j << ": " << temp << std::endl;
        std::cout << "q int while, temp " << j << ": " << tempq << std::endl;
    }

    for(int i = 0; i<20; i++) p.append(i);

    if(!p.empty()) std::cout << "p aint empty\n";

    p.clear();

    if(p.empty()) std::cout << "p is empty\n";

    return 0;
}