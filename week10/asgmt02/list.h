#include "header.h"

template <class List_entry>
class List {
public:
Error_code remove(int position);
//  Add specifications for the methods of the list ADT.
//  Add methods to replace the compiler-generated defaults.

protected:
//  Data members for the linked-list implementation with
//  current position follow:
   int count;
   mutable int current_position;
   Node<List_entry> *head;
   mutable Node<List_entry> *current;

//  Auxiliary function to locate list positions follows:
   void set_position(int position) const;
};

template<class List_entry>
Error_code List<List_entry>::remove(int position){
    if (position < 0 || position > count) return range_error;
    
    Node<List_entry> *previous,
    
    set_position(position-1);
    previous = current;
    current = current->next;
    previous->next = current->next; //join the nodes around current


    delete current;
    count--

    //reset current position
    current_position = count; 
    set_position(position); 

    }
    return success;
} 


template <class List_entry>
void List<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List: 0 <= position < count.
Post: The current Node pointer references the Node at position.
*/
{
   if (position < current_position) {  //  must start over at head of list
      current_position = 0;
      current = head;
   }
   for ( ; current_position != position; current_position++)
      current = current->next;
}