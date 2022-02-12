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
Pre:  None.
Post: If the Stack is not full, item is added to the top
      of the Stack.  If the Stack is full,
      an Error_code of overflow is returned and the Stack is left unchanged.
*/
{
   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}

Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}

Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/
{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else
      item = entry[count - 1];
   return outcome;
}

Error_code Stack::pop_top(Stack_entry& y){
    if(size() == 0){
        return underflow;
    }
    else{
        top(y);
        pop();
        return success;
    }
}

bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/
{
   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}

void Stack::clear(){
   count = 0;
}

bool Stack::full() const{
    return count==maxstack;
}

int Stack::size() const{
    return count;
}

void Stack::print() const{
   std::cout << "Stack contains following elements:\n";
   for(int i = 0; i<count; i++){
      std::cout << entry[i];
      if(i<count-1) std::cout << ", ";
   }
   std::cout << "\n";
}