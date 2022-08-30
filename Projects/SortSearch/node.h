#pragma once

#include "header.h"

template <typename Node_entry>
struct Node {
//  data members
    Node_entry entry;
    Node<Node_entry> *back;
    Node<Node_entry> *next;
//  constructors
   Node();
   Node(Node_entry, Node<Node_entry> *link_back = NULL,
                    Node<Node_entry> *link_next = NULL);
};


template<class Node_entry>
Node<Node_entry>::Node()
{
    entry = NULL;
    next = nullptr;
    back = nullptr;
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *link_back, Node<Node_entry> *link_next)
{
    entry = item;
    next = link_next;
    back = link_back;
}