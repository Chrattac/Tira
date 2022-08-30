#pragma once

#include "header.h"

const int max_list = 100;

template <class List_entry>
class List {
public:
//  methods of the List ADT
   List();
   int size() const;
   bool full() const;
   bool empty() const;
   void clear();
   void traverse(void (*visit)(List_entry &));
   Error_code retrieve(int position, List_entry &x) const;
   Error_code replace(int position, const List_entry &x);
   Error_code remove(int position, List_entry &x);
   Error_code insert(int position, const List_entry &x);
   List_entry peek(int position);
   void print() const;

protected:
//  data members for a contiguous list implementation
   int count;
   List_entry entry[max_list];
};

template <class List_entry>
List<List_entry>::List(){
    count = 0;
}

template <class List_entry>
int List<List_entry>::size() const
/*
Post: The function returns the number of entries in the List.
*/
{
   return count;
}

template<class List_entry>
bool List<List_entry>::full() const
{
    return count == max_list;
}

template<class List_entry>
bool List<List_entry>::empty() const
{
    return count == 0;
}

template<class List_entry> 
void List<List_entry>::clear()
{
    for(int i = 0; i<count; i++) entry[i]=0;
    count = 0;
}

template <class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
/*
Post: The action specified by function (*visit) has been performed on every
      entry of the List, beginning at position 0 and doing each in turn.
*/
{
   for (int i = 0; i < count; i++)
      (*visit)(entry[i]);
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
    if (position < 0 || position > count) return utility_range_error;
    if (empty()) return underflow;

    x=entry[position];

    return success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{

    if (position < 0 || position > count) return utility_range_error;
    if (empty()) return underflow;
    
    entry[position]=x;

    return success;
}   

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
    if (position < 0 || position > count) return utility_range_error;
    if (empty()) return underflow;

    x = entry[position];

    for (int i = position; i <= count; i++)
    entry[i] = entry[i+1];

    count--;

    return success;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
      where n is the number of entries in the List, the function succeeds:
      Any entry formerly at position and all later entries have their
      position numbers increased by 1 and x is inserted at position of the List.
      Else: The function fails with a diagnostic error code.
*/
{
   if (full())
      return overflow;

   if (position < 0 || position > count)
      return utility_range_error;

   for (int i = count - 1; i >= position; i--)
      entry[i + 1] = entry[i];

   entry[position] = x;
   count++;
   return success;
}

// Extra
template <class List_entry>
List_entry List<List_entry>::peek(int position){
    if (position < 0 || position > count){
        std::cout << "Position out of range";
        return 0;
    }
    else if(empty()){
    std::cout << "List is empty!";
    return 0;
    }

    return entry[position];
}


template <class List_entry>
void List<List_entry>::print() const
{
    std::cout << "List consists of items: \n";
    for(int i = 0; i<count; i++){
        std::cout << entry[i];
        if (i<(count-1)) std::cout << ", ";
        else std::cout << '\n';
    }
}