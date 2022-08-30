#include "header.h"

int main(){

    List<int> list;
    int temp;

    for (int i = 0; i<max_list; i++) list.insert(0, i);

    list.print();

    if(list.full()) std::cout << "List is full!\n";

    list.remove(5, temp);

    list.print();

    list.retrieve(7, temp);
    std::cout << "temp: " << temp << '\n';

    list.replace(4,100);
    list.print();

    list.clear();
    if(list.empty()) std::cout << "list is empty!\n";

    return 0;
}
