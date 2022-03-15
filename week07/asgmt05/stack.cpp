#include "header.h"

Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
   count = 0;
}

Error_code Stack::push(const Stack_entry &item)
/*
Post: Stack_entry item is added to the top of
      the Stack; returns success or returns a code
      of overflow if dynamic memory is exhausted.
*/
{
   Node *new_top = new Node(item, top_node);
   if (new_top == NULL) return overflow;
   top_node = new_top;
   count++;
   return success;
}


Error_code Stack::pop()
/*
Post: The top of the Stack is removed.  If the Stack
      is empty the method returns underflow; otherwise it returns success.
*/
{
   Node *old_top = top_node;
   if (top_node == NULL) return underflow;
   count--;
   top_node = old_top->next;
   delete old_top;
   return success;
}

Error_code Stack::top(Stack_entry &item) const {
   if (count == 0) return underflow;
   item = top_node->entry;
   return success;
}

bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/
{
   return count == 0;
}

int Stack::getSize(){
   Node temp = *top_node;
   int size = 1;


   //temp = top_node;

   while(temp.next != nullptr){
      temp = *temp.next;
      size++;
   }

   return size;
}