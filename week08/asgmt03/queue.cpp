#include "header.h"

Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
   front = rear = NULL;
}

Queue::Queue(const Queue &original)
{
    front = rear = NULL;

    if(!original.empty()){
        Node* temp = original.front;

        while(temp!=NULL){
            append(temp->entry);
            temp = temp->next;
        }
    }
}

Queue::~Queue()
{
    while(!empty()) serve();
}

bool Queue::empty() const
{
return front==NULL;
}


Error_code Queue::append(const Queue_entry &item)
/*
Post: Add item to the rear of the Queue and return a code of success
      or return a code of overflow if dynamic memory is exhausted.
*/
{
   Node *new_rear = new Node(item);
   if (new_rear == NULL) return overflow;
   if (rear == NULL) front = rear = new_rear;
   else {
      rear->next = new_rear;
      rear = new_rear;
   }
   return success;
}


Error_code Queue::serve()
/*
Post: The front of the Queue is removed.  If the Queue
      is empty, return an Error_code of underflow.
*/
{
   if (front == NULL) return underflow;
   Node *old_front = front;
   front = old_front->next;
   if (front == NULL) rear = NULL;
   delete old_front;
   return success;
}

Error_code Queue::retrieve(Queue_entry& item) const
{
    Error_code error = success;
    if(empty()) error = underflow;
    else item = front->entry;

    return error;
}

void Queue::operator =(const Queue& original)
{
    Queue copy(original);
    std::swap(front, copy.front);
}
