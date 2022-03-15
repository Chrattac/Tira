#include "header.h"

int main(){
    //Testing that methods work
    Queue q = Queue();
    int temp, tempq;

    if(q.empty()) std::cout << "Queue is empty\n"; 

    for (int i = 0; i<10; i++) q.append(i);

    q.retrieve(temp);
    std::cout << "q temp 1: " << temp << std::endl;
    q.serve();    
    q.retrieve(temp);
    std::cout << "q temp 2: " << temp << std::endl;
    q.serve();

    
    Queue p(q);

    p.retrieve(temp);
    std::cout << "p temp 1: " << temp << std::endl;
    std::cout << "p address 1: " << &q << std::endl;
    p.serve();    
    p.retrieve(temp);
    p.serve();
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
        
        p.retrieve(temp);
        p.serve();
        q.retrieve(tempq);
        q.serve();
        
        std::cout << "p int while, temp " << j << ": " << temp << std::endl;
        std::cout << "q int while, temp " << j << ": " << tempq << std::endl;
    }


    return 0;
}