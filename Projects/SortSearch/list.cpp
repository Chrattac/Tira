#include "header.h"

List::List()
{
    count = 0;
    current = nullptr;
    current_position = 0;
}


List::List(const List &copy)
{
    count = copy.count;
    current_position = copy.current_position;
    Node<Key> *new_node, *old_node = copy.current;
    if ( old_node == nullptr ) current = nullptr;
    else{
        new_node = current = new Node<Key>(old_node->entry);
        while( old_node->next != nullptr ){
            old_node = old_node->next;
            new_node->next = new Node<Key>(old_node->entry, new_node);
            new_node = new_node->next;
        }
        old_node = copy.current;
        new_node = current;
        while( old_node->back != nullptr ){
            old_node = old_node->back;
            new_node->back = new Node<Key>(old_node->entry, nullptr, new_node);
            new_node = new_node->back;
        }
    }
}


List::~List()
{
    clear();
}

void List::operator = (const List &copy)
{
    List new_copy(copy);
    clear();
    count = new_copy.count;
    current_position = new_copy.current_position;
    current = new_copy.current;
    new_copy.count = 0;
    new_copy.current_position = 0;
    new_copy.current = nullptr;
}

int List::size() const { return count; }

bool List::empty() const { return count==0; }

bool List::full() const { return false; }

void List::clear()
{
    if(count == 0) return;

    while(current->back != nullptr){
        current = current->back;
        delete current->next;
    }
    delete current;
    current = nullptr;
    current_position = 0;
    count = 0;
}

Error_code List::insert( int position, const Key &x )
{
    Node<Key> *following, 
            *preceding; 

    if( position < 0 || position > count ) return utility_range_error;

    if(position > 0){
        set_position(position-1);
        preceding = current;
    }
    else {
        preceding = nullptr;
        set_position(position);
    }

    set_position(position);
    if(current != nullptr) following = current; //ie current according to pos.
    else following = nullptr;

    Node<Key> *new_node = new Node<Key>( x, preceding, following );

    if( new_node == nullptr ) return overflow;

    current = new_node;

    if(preceding != nullptr) preceding->next = current;
    if(following != nullptr) following->back = current;

    current_position = position;
    count++;

    return success;
}

Error_code List::replace( int position, const Key &x )
{
    if ( position < 0 || position >= count ) return utility_range_error;
    set_position(position);
    current->entry = x;
    return success;
}


Error_code List::retrieve( int position, Key &x )
{

    if( position < 0 || position >= count ) return utility_range_error;
    set_position( position );
    x = current->entry;

    return success;

}

Error_code List::remove( int position, Key &x )
{

    Node<Key> *old_node, *prev_node, *next_node;
    if ( count == 0 ) return fail;
    if ( position < 0 || position >= count ) return utility_range_error;
    set_position(position);

    old_node = current;
    prev_node = current->back;
    next_node = current->next;
    
    if( prev_node != nullptr ) prev_node->next = next_node;
    if( next_node != nullptr ) next_node->back = prev_node;

    if( prev_node != nullptr ) {
        current = current->back;
        current_position--;
    }
    else if( next_node != nullptr){
        current = current->next;
    }
    else current = nullptr;

    x = old_node->entry;
    delete old_node;
    count--;
    return success;

}

void List::traverse( void (*visit)(Key &) )
{
    Node<Key> *to_visit = current;

    if( to_visit != nullptr )
        for ( ; to_visit->back; to_visit = to_visit->back);
    
    for( ; to_visit; to_visit = to_visit->next )
        (*visit)(to_visit->entry);

}

    void List::print_current(bool one) const{
      if(one) std::cout << "current key: ";

      std::cout << current->entry.get_key();
  }

    
    void List::print_prev_next(bool which) const{
        if(which) std::cout << current->back->entry.get_key();
        else std::cout << current->next->entry.get_key();
    }

    void List::print_list(){
        int i = 0;
        set_position(0);
        std::cout << "[ ";
        while( current->next!=nullptr ){
            set_position(i++);
            print_current(false);
            if( current->next != nullptr ) std::cout << ", ";
        }
        std::cout << " ]\n";
    }


void List::set_position(int position)
/* Pre: position is a valid position in the List: 0 ≤ position < count.
Post: The current Node pointer references the Node at position. */
{
    
    if ( current_position < position )
        for ( ; current_position != position; current_position++ )
            current = current->next;
    else if ( current_position > position)
        for ( ; current_position != position; current_position-- ){
            current = current->back;
        }
}

// SEARCH&SORT METHODS
int List::getComparisons() const {
    return Key::comparisons;
}

Error_code List::sequential_search(List &the_list, const Key &target, int &dest)
/*
Post: If an entry in the_list has key equal to target, then return
      success and the output parameter position locates such an entry
      within the list.
      Otherwise, return not_present and position becomes invalid.
*/
{   

        int s = the_list.size();
        Key data;
        dest = 0;
        for(dest; dest < s; dest ++){
            retrieve(dest, data);

            if ( operator == (target, data) ) return success;
        }
        return not_present;
}


Error_code List::binary_search(List &l, const Key &target, int &dest)
{
    int start = 0, 
        end = l.size(); 
    Key data;

        while(start < end){
           dest = (start+end)/2; //start from middle position
           l.retrieve(dest, data);

            if( operator == (data, target) ) return success;
            else if ( operator > ( data, target ) ) end = dest;
            else start = dest;

            if (start == end-1 || start == end) return not_present;
        }
        return not_present;
}

void List::insert_sort(List &l)
{
    Key temp,
        current_val;
    int unsorted = 1, 
        position = 0;


    for ( unsorted; unsorted < l.size(); unsorted++ ){
        position=unsorted-1;
        l.retrieve(position, temp);
        l.retrieve(unsorted, current_val);

        if( operator < (current_val, temp) ){
            l.remove(unsorted, current_val);
            
            while(position >= 0 && operator < (current_val, temp ) ) {
                position--;
                l.retrieve(position, temp);
            }
            
            l.insert(position+1, current_val);
        }
    }
}

void List::select_sort(List& l) {

    int position = 0, run_through = 0;
    set_position(position);
    Key min, temp;

    for (position; position < size(); position++) {
        retrieve(position, min);
        temp = min;

        for (run_through = position+1; run_through < size(); run_through++) {
            retrieve(run_through, temp);
            if (operator < (temp, min)) {
                replace(run_through, min);
                min = temp;
            }
        }

        replace(position, min);
    }
}

void List::merge_sort(List &l){

    set_position(0); //start from pos 0 ->
    current = merge_sort_nodes(current);

}


void List::tree_sort(List &l){
    // back = left, front = right
    set_position(0);
    current = tree_sort_nodes(current);

}