#pragma once

#include "header.h"

template<typename List_entry, class List>
Error_code insert_first(const List_entry&, List&);

template<typename List_entry, class List>
Error_code remove_first(List_entry&, List&);

template<typename List_entry, class List>
Error_code remove_last(List_entry&, List&);

template<typename List_entry, class List>
Error_code median_list(List_entry&, List&);

template<class List>
Error_code interchange(int, int, List&);

template<typename List_entry, class List>
Error_code reverse_traverse_list(List&, void (*visit)(List_entry));

template<class List>
Error_code copy(List&, List&);

template<class List>
Error_code join(List&, List&);

template<typename List_entry, class List>
void reverse(List&);

template<typename List_entry, class List>
Error_code split(List&, List&, List&);

void Error_print(Error_code);

template<typename List_entry>
void multiply_entry(List_entry x);

//Functions:

#include "header.h"

template<typename List_entry, class List>
Error_code insert_first(const List_entry& x, List& l)
{
    return l.insert(0, x);
}

template<typename List_entry, class List>
Error_code remove_first(List_entry& x, List& l)
{
    return l.remove(0, x);
}

template<typename List_entry, class List>
Error_code remove_last(List_entry& x, List& l)
{
    return l.remove(l.size()-1, x);
}

template<typename List_entry, class List>
Error_code median_list(List_entry& x, List& l)
{
    Error_code error = success;
    if(l.size()%2 == 0) error = l.retrieve((l.size()/2)-1, x);
    else error = l.retrieve(l.size()/2, x);

    return error;
}

template<class List>
Error_code interchange(int x, int y, List& l)
{
    Error_code error = success;
    decltype(l.peek(0)) x_val, y_val;

    error = l.retrieve(x, x_val);
    if(error != success){
        std::cout << "With position 1";
        Error_print(error);
        return error;
    }
    error = l.retrieve(y, y_val);
    if(error != success){
        std::cout << "With position 2";
        Error_print(error);
        return error;
    }

    if(error == success) error = l.replace(x, y_val);

    if (error == success) error = l.replace(y, x_val);

    if(error!=success) Error_print(error);

    return error;

}

template<typename List_entry, class List>
Error_code reverse_traverse_list(List& l, void (*visit)(List_entry))
{   
    decltype(l.peek(0)) temp, check;
    Error_code error = success;

    for(int i = l.size(); i>=0; i--) {
        error = l.retrieve(i, temp);
        visit(temp);

        if(temp != l.peek(i)) error=l.replace(i, temp);

        if(error != success){
            std::cout << "In position " << i << " ";
            Error_print(error);
            break;
        }
    }

    return error;
}

template<class List>
Error_code copy(List& dest, List& src)
{
    Error_code error = success;
    decltype(src.peek(0)) temp;

    if(!dest.empty()) dest.clear();

    for(int i=0; i<src.size(); i++){
        error = src.retrieve(i, temp);
        if(error == success) error = dest.insert(i, temp);

        if(error != success) {
            std::cout << "In position " << i << " ";
            Error_print(error);
            break;
        }
    }

    return error;
}

template<class List>
Error_code join(List& a, List& b)
{
    Error_code error = success;
    decltype(a.peek(0)) temp;

    for(int i = 0; i<a.size(); i++){
        error = a.retrieve(i, temp);
        if(error!=success){
            std::cout << "1st list in position " << i << " ";
            Error_print(error);
            break;
        }

        error = b.insert(b.size(), temp);

        if(error!=success){
            std::cout << "2nd list in position " << (b.size()+i) << " ";
            Error_print(error);
            break;
        }
    }


    return error;
}

template<typename List_entry, class List>
void reverse(List& l)
{
    List_entry head, tail;
    
    for(int i = 0; i<((l.size())/2); i++){
        l.retrieve(i, head);
        l.retrieve(l.size()-i-1, tail);
        l.replace(i, tail);
        l.replace(l.size()-i-1, head);
    }
}

template<typename List_entry, class List>
Error_code split(List& l, List& even, List& odd)
{
    Error_code error = success;
    List_entry temp;

    if(!odd.empty()) odd.clear();
    if(!even.empty()) even.clear();
    
    for(int i = 0; i<l.size()-1; i++){
        l.retrieve(i, temp);

        if(i%2==0) error = even.insert(i/2, temp);
        else error = odd.insert(i/2, temp);
        
        if(error!=success){
            std::cout << "In position " << i << " ";
            Error_print(error);
            break;
        }
    }
    return error;
}


//Extra
void Error_print(Error_code e){
    std::cout << "Error: ";
    switch(e){
        case fail:
            std::cout << "fail!";
            break;
        case utility_range_error:
            std::cout << "error with range!";
            break;
        case underflow:
            std::cout << "underflow!";
            break;
        case overflow:
            std::cout << "overflow";
            break;
        case fatal:
            std::cout << "fatal!";
            break;
        case not_present: 
            std::cout << "not preset!";
            break;
        case duplicate_error: 
            std::cout << "duplicate error!";
            break;
        case internal_error:
            std::cout << "internal error!";
            break;
        default:
            std::cout << "unforeseen (fatal)!";
            break;
    }
    std::cout << std::endl;
}

template<typename List_entry, class List>
void multiply_entry(List_entry x){
    x*=x;
}