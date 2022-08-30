#pragma once

#include "header.h"



typedef int Node_entry;

struct Node {
//  data members
   Node_entry entry;
   Node *next;
//  constructors
   Node();
   Node(Node_entry item, Node *add_on = NULL);
};

template<class Node_entry>
Node<Node_entry>::Node()
{
    entry = NULL;
    back = nullptr;
    next = nullptr;
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *node)
{
   node
    entry = item;
    next = node;
}