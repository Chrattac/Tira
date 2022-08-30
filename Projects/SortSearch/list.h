#pragma once
#include "header.h"


class List {
public:
    List();
    List(const List &copy);
    ~List();

    void operator = (const List &copy);

    int size() const;
    bool empty() const;
    bool full() const;

    void clear();

    Error_code insert( int position, const Key &x );
    Error_code replace( int position, const Key &x );
    Error_code retrieve( int position, Key &x );
    Error_code remove( int position, Key &x );
    void print_current(bool one) const;
    void print_prev_next(bool which) const;
    void print_list();

    void traverse( void (*visit)(Key &) );
    void set_position(int position);


    Error_code sequential_search(List &the_list, const Key &target, int &dest);
    Error_code binary_search(List &l, const Key &target, int &dest);
    
    void insert_sort(List &l);
    void select_sort(List &l);
    void merge_sort(List &l);
    void tree_sort(List &l);

    int getComparisons() const;

protected:
//  Data members for the doubly-linked list implementation follow:
   int count;
   mutable int current_position;
   mutable Node<Key> *current;

//  The auxiliary function to locate list positions fozllows:
};

