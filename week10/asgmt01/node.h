#pragma once
#include "header.h"

template<class Node_entry>
struct Node {
    Node_entry entry;
    Node<Node_entry> *next;

    Node();
    Node(Node_entry, Node<Node_entry> *next = nullptr);
};

template<class Node_entry>
Node<Node_entry>::Node()
{
    entry = NULL;
    next = nullptr;
}

template<class Node_entry>
Node<Node_entry>::Node(Node_entry item, Node<Node_entry> *node)
{
    entry = item;
    next = node;
}