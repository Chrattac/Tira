#include "header.h"

int main(){

    Error_code error;

    List<int> list_a, list_b, list_c;
    int temp;

    for (int i = 0; i<26; i++) insert_first(i, list_a);

    for (int i = 100; i>80; i--) insert_first(i, list_b);
    
    list_a.print();

    error = remove_first(temp, list_a);
    std::cout << "temp: " << temp << '\n';
    list_a.print();
    std::cout << std::endl;

    error = remove_last(temp, list_a);
    std::cout << "temp: " << temp << '\n';
    list_a.print();
    std::cout << std::endl;

    list_a.insert(5, 100);
    error = median_list(temp, list_a);
    std::cout << "temp: " << temp << '\n';
    list_a.print();
    std::cout << std::endl;

    error = interchange(7, 17, list_a);
    list_a.print();
    std::cout << std::endl;

    // reverse_traverse_list(list_a, &multiply_entry); 
    // Can't figure out why I can't get call back to work

    error = copy(list_c, list_a);
    std::cout << std::endl;
    std::cout << "list a:\n";
    list_a.print();
    std::cout << "list c:\n";
    list_c.print();
    
    std::cout << std::endl;

    std::cout << "list b:\n";
    list_b.print();

    join(list_a, list_b);

    std::cout << "list b after joining with list a";
    list_b.print();

    std::cout << std::endl << "Reversing b" << std::endl;
    reverse<int>(list_b);
    list_b.print();

    std::cout << std::endl << "splitting b positionally to a (odd) & c (even)" << std::endl;
    error= split<int>(list_b, list_c, list_a);
    std::cout << "Odd (a): \n";
    list_a.print();
    std::cout << "Even (c): \n";
    list_c.print();

    if(error != success) Error_print(error);

    return 0;
}