#include "header.h"

bool Extended_queue::full() const
{
    //Returns true, if heap is full
    bool is_full = false;

    Node* temp = new Node();
    if(temp == NULL) is_full = true;
    delete temp;

    return is_full;
}

int Extended_queue::size() const
/*
Post: Return the number of entries in the Extended_queue.
*/
{
   Node *window = front;
   int count = 0;
   while (window != NULL) {
      window = window->next;
      count++;
   }
   return count;
}

void Extended_queue::clear()
{
    while(!empty()){
        serve();
    }
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item)
{
    Error_code error;
    if((error = serve()) == success) error=retrieve(item);

    return error;
}

Error_code Extended_queue::retrieve_and_serve(Queue_entry &item)
{
    Error_code error;
    if((error = retrieve(item)) == success) error=serve();

    return error;
}