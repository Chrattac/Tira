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
    count = 0;
}

void Extended_queue::print() const{
    if(empty()) std::cout << "Queue is empty.";
    else{
        std::cout << "Queue consists of following items:\n";
        for(int i = 0; i<count; i++){
            std::cout << entry[i];
            if(i < count-1) std::cout << ", ";
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