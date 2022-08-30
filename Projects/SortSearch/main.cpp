#include "header.h"



int main(){
    Key::comparisons = 0;
    bool cntn = true;
    List list;
    Key key;
    
    std::cout << "Welcome to use searching and sorting - app!\n";
    do{
        
        switch(initialize()){
            case 1:

                fill_list_integers_det(list);
                std::cout << "Generated list: \n";
                list.print_list();
                std::cout << "Give key you want to search for (integer): ";
                key.set_key( get_int() );

                sequential_search(list, key);

                break;
            case 2:                

                fill_list_integers_det(list);
                std::cout << "Generated list: \n";
                list.print_list();

                std::cout << "Give key you want to search for (integer): ";
                key.set_key( get_int() );

                binary_search(list, key);

                break;
            case 3:
                fill_list_integers_rand(list, false, 0);
                std::cout << "Generated list: \n";
                list.print_list();

                insertion_sort(list);

                std::cout << "List after sorting: \n";
                list.print_list();

                break;
            case 4:
                fill_list_integers_rand(list, false, 0);           
                std::cout << "Generated list: \n";
                list.print_list();
                
                selection_sort(list);

                std::cout << "List after sorting: \n";
                list.print_list();

                break;
            case 5:
                fill_list_integers_rand(list, false, 0);
                std::cout << "Generated list: \n";
                list.print_list();
                
                merge_sort(list);

                std::cout << "List after sorting: \n";
                list.print_list();
                break;
            case 6:
                fill_list_integers_rand(list, false, 0);
                std::cout << "Generated list: \n";
                list.print_list();
                
                tree_sort(list);

                std::cout << "List after sorting: \n";
                list.print_list();
                break;
            case 7:
                performance(list);
                break;
            case 8: 
                cntn = false;
                break;
        }

        Key::comparisons = 0; // 0 comparisons for the next run;

    }while(cntn);

    return 0;
}