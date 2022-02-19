#include "header.h"

int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
   return count;
}

bool Extended_queue::full() const{
    return size() == maxqueue;
}

void Extended_queue::clear(){
    front = 0;
    count = 0;
    rear = maxqueue-1
}

void Extended_queue::print() const{

    int i = front, imax;
    bool overlap = false;
    if(front < rear) imax = rear;
    else if(rear < front) imax = maxqueue-1, overlap = true;


    if(empty()) std::cout << "Queue is empty.";
    else{
        std::cout << "Queue consists of following items:\n";
        for(i; i<=imax; i++){
            std::cout << entry[i];
            if(i < imax) std::cout << ", ";
            if(overlap && i == imax){
                std::cout << ", ";
                for(int j = 0; j<=rear; j++){
                    std::cout << entry[j];
                    if(j<rear) std::cout << ", ";
                } 
            }
        }
    }
    std::cout << "\n";
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item){
    Error_code error;
    error = serve();
    if(error==success) error = retrieve(item);

    return error;
}

Error_code Extended_queue::retrieve_and_serve(Queue_entry &item){
    Error_code error;
    error = retrieve(item);
    if(error==success) error = serve();

    return error;
}