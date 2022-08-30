#include "header.h"

int initialize() {
    int choice;
    bool cntn;

        std::cout << "\nChoose on of following options:\n"
        << "[1] Sequential search\n"
        << "[2] Binary search \n"
        << "[3] Insertion sort \n"
        << "[4] Selection sort \n"
        << "[5] Merge sort \n"
        << "[6] Tree sort \n"
        << "[7] Performance \n"
        << "[8] Quit program \n"
        << "Your option: ";
    do {
        choice = get_int();
        if (1 <= choice <= 8) cntn = true;
        else {
            cntn = false;
            std::cout << "Option not available, try again: ";
        }
    } while (!cntn);

    return choice;
}

int ask_size() {
    int integer = 0;

    std::cout << "With how many entries would you like to fill the list?: ";

    while (integer < 1) {
        integer = get_int();
        if (integer < 1) std::cout << "Please give positive integer!: ";
    }

    return integer;
}

int get_int() {
    int integer;
    bool obey;

    do {
        std::cin >> integer;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "Sorry, unrecognized input, try again\n"
                << "Give integer:";
            obey = false;
        }
        else obey = true;
    } while (!obey);


    return integer;
}

int random_gen(int min, int max) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased


    return uni(rng);
}


void fill_list_integers_det(List& list) {
    int listSize;
    list.clear();

    listSize = ask_size();

    for (int i = 0; i < listSize; i++) {
        list.insert(i, (2 * i + 1));
    }

}


void fill_list_integers_rand(List& list, bool performance, int round) {

    int listSize;
    int max, min;
    list.clear();


    if(!performance){
        listSize = ask_size();
        std::cout << "To at least have a chance to accomplish the task, give values less "
            << "and greater than they key you want to search for\n";

        do {
            std::cout << "Give min value for random number generator: ";
            min = get_int();
            std::cout << "Give max value for random number generator: ";
            max = get_int();

            if (min > max) std::cout << "It doesn't work that way...\n";

        } while (min > max);
    }
    else{
        listSize = round*1000;
        min = 0;
        max = 1000000;
    }

    //fill list's key values with random integers
    for (int i = 0; i < listSize; i++) {
        list.insert(i, Key(random_gen(min, max)));
    }
}

void performance(List &list){
    int round = 1;
    std::cout << "running 10 rounds of performance on search functions: \n";

    for(round; round<=10; round++){
        std::cout << "\n\nRound#"<< round << ", list size: " << round*1000 << ":\n";
        reset(list, round);
        std::cout << "\nInsertion sort: \n";
        insertion_sort(list);
        reset(list, round);
        std::cout << "\nSelection sort: \n";
        selection_sort(list);
        reset(list, round);
        std::cout << "\nMerge sort: \n";
        merge_sort(list);
        reset(list, round);
        std::cout << "\nTree sort: \n";
        tree_sort(list);
    }
    list.clear();
    std::cout << "\n\nFINISH\n";

}

void reset(List& list, int round){
    list.clear();
    Key::comparisons = 0;
    fill_list_integers_rand(list, true, round);
}


void print_result(const Error_code& error, const int& pos,
                const int& comp, const int64_t time)
{
    if (error == success) {
        std::cout << "Found in position: " << pos << '\n';
        std::cout << "Comparisons: " << comp << '\n';
        std::cout << "Took " << time << " nanoseconds\n";
    }
    else {
        std::cout << "Sorry, no hits" << '\n';
        std::cout << "Comparisons: " << comp << '\n';
        std::cout << "Took " << time << " nanoseconds\n";
    }
}

// Search & Sort functions

// SEARCH 

void sequential_search(List& sList, const Key& key) {
    Error_code check;
    int pos;

    auto clock_start = std::chrono::steady_clock::now();

    check = sList.sequential_search(sList, key, pos);

    auto clock_end = std::chrono::steady_clock::now();
    int64_t time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end - clock_start).count();

    print_result(check, pos, sList.getComparisons(), time_taken);
}

void binary_search(List& sList, const Key& key) {
    Error_code check;
    int pos;

    auto clock_start = std::chrono::steady_clock::now();

    check = sList.binary_search(sList, key, pos);

    auto clock_end = std::chrono::steady_clock::now();
    int64_t time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(clock_end - clock_start).count();

    print_result(check, pos, sList.getComparisons(), time_taken);

}

// SORT
// n^2 

void insertion_sort(List& sList) {

    auto clock_start = std::chrono::steady_clock::now();

    sList.insert_sort(sList);

    auto clock_end = std::chrono::steady_clock::now();
    int64_t time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(clock_end - clock_start).count();

    std::cout << "Sorting took " << time_taken << " milliseconds!\n";
    std::cout << "Comparisons: " << Key::comparisons << '\n';
}

void selection_sort(List& sList){
    auto clock_start = std::chrono::steady_clock::now();

    sList.select_sort(sList);

    auto clock_end = std::chrono::steady_clock::now();
    int64_t time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(clock_end - clock_start).count();

    std::cout << "Sorting took " << time_taken << " milliseconds!\n";
    std::cout << "Comparisons: " << Key::comparisons << '\n';
}

// n log n

void merge_sort(List& sList) {

    auto clock_start = std::chrono::steady_clock::now();

    sList.merge_sort(sList);

    auto clock_end = std::chrono::steady_clock::now();
    int64_t time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(clock_end - clock_start).count();

    std::cout << "Sorting took " << time_taken << " milliseconds!\n";
    std::cout << "Comparisons: " << Key::comparisons << '\n';
}

void tree_sort(List& sList) {

    auto clock_start = std::chrono::steady_clock::now();


    sList.tree_sort(sList);

    auto clock_end = std::chrono::steady_clock::now();
    int64_t time_taken = std::chrono::duration_cast<std::chrono::milliseconds>(clock_end - clock_start).count();

    std::cout << "Sorting took " << time_taken << "milliseconds!\n";
    std::cout << "Comparisons: " << Key::comparisons << '\n';

}

// merge_sort helpers

Node<Key>* merge_sort_nodes(Node<Key>* first) {
    //stop doing recursive once there is nullptr in the node
    if (first == nullptr || first->next == nullptr) return first;


    Node<Key>* second = split(first);

    //recursive, continue until both halves are sorted
    first = merge_sort_nodes(first);
    second = merge_sort_nodes(second);

    //merge double linked nodes, finally returns node with lowest key value
    return merge_sorted_nodes(first, second);
}

Node<Key>* split(Node<Key>* source) {
    //Turtle-rabbit method to find middle point. Due to recursive splitting.

    Node<Key> *rabbit = source,
            *turtle = source,
            *temp;

    while (rabbit->next != nullptr && rabbit->next->next != nullptr) {
        rabbit = rabbit->next->next;
        turtle = turtle->next;
    }

    temp = turtle->next;
    turtle->next = nullptr;

    return temp;

}

Node<Key>* merge_sorted_nodes(Node<Key>* first, Node<Key>* second) {
    //recursive merging, continue til either input is nullptr
    if (first == nullptr) return second;
    if (second == nullptr) return first;

    if (operator < (first->entry, second->entry)) {
        first->next = merge_sorted_nodes(first->next, second);
        first->next->back = first; //recursion, link backnode
        first->back = nullptr;
        return first;
    }
    else {
        second->next = merge_sorted_nodes(first, second->next);
        second->next->back = second;
        second->back = nullptr;
        return second;
    }
}


//tree_sort helpers:
Node<Key>* tree_sort_nodes(Node<Key>* headNode) {
    Node<Key>* root = new Node<Key>;
    root->entry = headNode->entry;

    //Run through whole list and build a tree based on entries
    //Tree is completely new list, where lowest node is returned
    while (headNode->next != nullptr) {
        headNode = headNode->next;

        Node<Key>* branch = new Node<Key>;
        branch->entry = headNode->entry;


        root = build_tree(root, branch);

        //delete old node since we are building completely new tree
        delete headNode->back;
    }

    delete headNode; //delete last node once tree is built;

    order_tree(root); //order built tree

    while (root->back != nullptr)
        root = root->back; //Run back to first node to return it as a new head.

    return root;
}

Node<Key>* build_tree(Node<Key>* root, Node<Key>* branch) {
    //back is left, next is right
    //recursive

    if (root == nullptr) {
        root = branch;
        return root;
    }
    else if (operator > (root->entry, branch->entry)) {
        root->back = build_tree(root->back, branch);
    }
    else {
        root->next = build_tree(root->next, branch);
    }

    return root;
}

Node<Key>* order_tree(Node<Key>* root) {

    if (root == nullptr) {
        return root;
    }
    else{

        root->back = order_tree(root->back);
        root->next = order_tree(root->next);

        Node<Key> *link_branch = new Node<Key>;
        if (root->back != nullptr) {
            link_branch = root->back;

            //Run to the biggest node to the left (lower than root)
            while (link_branch->next != nullptr) link_branch = link_branch->next;

            //link greatest of the lower than nodes as a next of the root
            link_branch->next = root;
            root->back = link_branch;
        }
        if (root->next != nullptr) {
            link_branch = root->next;

            //Run to the lowest node to the right (greater than root)
            while (link_branch->back != nullptr) link_branch = link_branch->back;

            //link lowest of the greater than nodes as a next of the root
            link_branch->back = root;
            root->next = link_branch;
        }
    }


    return root;
}

