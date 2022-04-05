#pragma once

#include "plane.h"

//Whole class is both Queue and Extended Queue concatenated
//Using templates to define both array size (prev. maxqueue) and type of Queue_entry
//using uint 8 for guaranteeing always positive value and max 255 array size

template<typename Queue_entry, uint8_t Size>
class Queue {
public:
   Queue();
   bool empty() const;
   bool full() const;

   int size() const;

   void clear();
   void print() const;

   Error_code serve();
   Error_code append(const Queue_entry &item);
   Error_code retrieve(Queue_entry &item);
   Error_code serve_and_retrieve(Queue_entry &item);
   Error_code retrieve_and_serve(Queue_entry &item);

private:
   int count;
   int front, rear;

   Queue_entry entry[Size];
};

template<typename Queue_entry, uint8_t Size>
Queue<Queue_entry, Size>::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
   count = 0;
   rear = Size - 1;
   front = 0;
}

template<typename Queue_entry, uint8_t Size>
bool Queue<Queue_entry, Size>::empty() const
/*
Post: Return true if the Queue is empty, otherwise return false.
*/
{
   return count == 0;
}

template<typename Queue_entry, uint8_t Size>
bool Queue<Queue_entry, Size>::full() const{
    return size() == Size;
}

template<typename Queue_entry, uint8_t Size>
int Queue<Queue_entry, Size>::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
   return count;
}

template<typename Queue_entry, uint8_t Size>
Error_code Queue<Queue_entry, Size>::append(const Queue_entry &item)
/*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
*/

{
   if (count >= Size) return overflow;
   count++;
   rear = ((rear + 1) == Size) ? 0 : (rear + 1);
   entry[rear] = item;
   return success;
}

template<typename Queue_entry, uint8_t Size>
Error_code Queue<Queue_entry, Size>::serve()
/*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
*/

{
   if (count <= 0) return underflow;
   count--;
   front = ((front + 1) == Size) ? 0 : (front + 1);
   return success;
}

template<typename Queue_entry, uint8_t Size>
Error_code Queue<Queue_entry, Size>::retrieve(Queue_entry &item)
/*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/

{
   if (count <= 0) return underflow;
   item = entry[front];
   return success;
}


template<typename Queue_entry, uint8_t Size>
void Queue<Queue_entry, Size>::clear(){
    front = 0;
    count = 0;
    rear = Size-1;
}

template<typename Queue_entry, uint8_t Size>
void Queue<Queue_entry, Size>::print() const{

    int i = front, imax;
    bool overlap = false;
    if(front < rear) imax = rear;
    else if(rear < front) imax = Size-1, overlap = true;


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

template<typename Queue_entry, uint8_t Size>
Error_code Queue<Queue_entry, Size>::serve_and_retrieve(Queue_entry &item){
    Error_code error;
    error = serve();
    if(error==success) error = retrieve(item);

    return error;
}

template<typename Queue_entry, uint8_t Size>
Error_code Queue<Queue_entry, Size>::retrieve_and_serve(Queue_entry &item){
    Error_code error;
    error = retrieve(item);
    if(error==success) error = serve();

    return error;
}