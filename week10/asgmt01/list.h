#include "header.h"

template <class List_entry>
class List {
public:
//  Specifications for the methods of the list ADT go here.
//  The following methods replace compiler-generated defaults.
   ~List();
   List(const List<List_entry> &copy);
   void operator =(const List<List_entry> &copy);

    Error_code insert(int position, const List_entry &x);
    Error_code retrieve(int position, List_entry &x);
    Error_code remove(int position);
    bool full();
    bool empty();

protected:
//  Data members for the linked list implementation now follow.
   int count;
   Node<List_entry> *head;

//  The following auxiliary function is used to locate list positions
   Node<List_entry> *set_position(int position) const;
};

// Methods:

template <class List_entry>
List<List_entry>::List(){
    count=0;
    head = new Node<List_entry>();
};

template <class List_entry>
List<List_entry>::~List(){
    Node<List_entry> temp;
    while(head->next != nullptr){
        temp = set_position(count)
        delete temp;
    }
    delete head;
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy)
{
    Node<List_entry> *temp = head;
    &copy.head = new Node<List_entry>(temp->entry);
    while(temp->next != nullprt) {
        temp = temp->next;
        copy.insert(temp.entry)
    }
}

template <class List_entry>
bool List<List_entry>::full(){
    Node<List_entry> *new_Node = new Node<List_entry>();
    if(new_Node == NULL) {
        
        return true;
    }
    else{
        delete new_Node;
        return false;
    }
}

template <class List_entry>
bool List<List_entry>::empty(){

    return count==0;

}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x){
    
    if (position < 0 || position > count) return range_error;
    else x = set_position(position)->entry;


    return success;
}

template <class List_entry>
Error_code<List_entry::remove(int position){
    if (position < 0 || position > count) return range_error;
    else{

        Node<List_entry> *previous, *following, *current;
        

        previous = set_position(position-1);
        current = set_position(position);

        previous->next = current->next;
        
        delete current;
        count--;
    }
    
    return success;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
      where n is the number of entries in the List, the function succeeds:
      Any entry formerly at position and all later entries have their position
      numbers increased by 1, and x is inserted at position of the List.
      Else: The function fails with a diagnostic error code.
*/
{
   if (position < 0 || position > count)
      return range_error;
   Node<List_entry> *new_node, *previous, *following;
   if (position > 0) {
      previous = set_position(position - 1);
      following = previous->next;
   }
   else following = head;
   new_node = new Node<List_entry>(x, following);
   if (new_node == NULL)
      return overflow;
   if (position == 0)
      head = new_node;
   else
      previous->next = new_node;
   count++;
   return success;
}

template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List; 0 <= position < count.
Post: Returns a pointer to the Node in position.
*/
{
   Node<List_entry> *q = head;
   for (int i = 0; i < position; i++) q = q->next;
   return q;
}


