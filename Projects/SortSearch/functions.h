#pragma once

#include "header.h"

int initialize();
int ask_size();
int get_int();
int random_gen(int, int);
void fill_list_integers_det(List& List);
void fill_list_integers_rand(List& list, bool performance, int round);
void print_result(const Error_code& error, const int& pos, const int& comp, const int64_t time);
void performance(List& list);
void reset(List& list, int round);

// --- Search & Sort ---
void sequential_search(List& sList, const Key& key);
void binary_search(List& sList, const Key& key);

// n^2
void insertion_sort(List& sList);
void selection_sort(List& sList);

// n log n
void merge_sort(List& sList);
void tree_sort(List& sList);

// Merge_sort helpers:
Node<Key>* merge_sort_nodes(Node<Key>* headNode);
Node<Key>* split(Node<Key>* source);
Node<Key>* merge_sorted_nodes(Node<Key>* first, Node<Key>* second);

// Tree_sort helpers:
Node<Key>* tree_sort_nodes(Node<Key>* head);
Node<Key>* build_tree(Node<Key>* root, Node<Key>* branch);
Node<Key>* order_tree(Node<Key>* root);