#include "header.h"

void introduction(){
    std::cout << "Welcome to queue program!";
    help();
}

void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/

{
std::cout << "Which part do you want to check?\n"
      << "A, B, C, D, E, F or [Q]uit?: ";
}


bool do_command(char c, Extended_queue &test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
      Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
*/

{
    bool continue_input = true;
    Queue_entry x;

    switch (c) {
    case 'a':
        std::cin >> x;
        test_queue.append(x);
        break;
    case 's':
        test_queue.serve();
        break;
    case 'c':
        test_queue.clear();
        break;
    case 'p':
        test_queue.print();
        break;
    case 'h':
        help();
        break;
    case '#':
        std::cout << "Queue consists of " << test_queue.size() << " items\n";
        break;
    case 'r':
        if (test_queue.retrieve(x) == underflow)
            std::cout << "Queue is empty." << std::endl;
        else
            std::cout << std::endl
                << "The first entry is: " << x
                << std::endl;
        break;

    case 'q':
       std::cout << "Extended queue demonstration finished." << std::endl;
       continue_input = false;
       break;
     //  Additional cases will cover other commands.
    }
    return continue_input;
}

char get_command()
{
    char command;
    bool waiting = true;

    while (waiting) {
       std::cin >> command;
       command = tolower(command);
       if (command == 'a' || command == 's' || command == 'r' ||
           command == '#' || command == 'c' || command == 'p' ||
           command == 'h' || command == 'q' ) waiting = false;


       else {
          std::cout << "Please enter a valid command:"   << std::endl
               << "[H] to show help\t[Q] to quit" << std::endl;
       }
    }
    return command;
}

// ASGMT04 functions:

Error_code stack_to_queue(Stack& s, Extended_queue& q){
// Moving stack to queue

    Error_code error = success;
    Stack_entry temp;

    if(s.empty()) error = underflow;
    else{
        while(!s.empty() && error==success){
            s.pop_top(temp);
            error = q.append(temp);
        }
    }

    return error;
}

Error_code queue_to_stack(Extended_queue& q, Stack& s){
// moving queue to stack
    Error_code error = success;
    
    Queue_entry temp;
    
    if(q.empty()) error = underflow;
    else{
        while(!q.empty() && error==success){
            q.retrieve_and_serve(temp);
            error = s.push(temp);
        }
    }
    
    return error;
}

Error_code pile_stack(Stack& x, Stack& y){
// x is the first stack, y is the second. Piling stack x on top of y.
    Error_code error = success;
    Stack temp_S;
    Stack_entry temp;

    if (x.full()) error = overflow;
    else if(y.empty()) error = underflow;
    else{
        while(!y.empty() && error == success){
            error = y.pop_top(temp);
            error = temp_S.push(temp);
        }
        while(!temp_S.empty() && error == success){
            error = temp_S.pop_top(temp);
            error = x.push(temp);
        }
    }

return error;
}

Error_code pile_stack_rev(Stack& x, Stack& y){
// x is the first stack, y is the second. Piling stack x on top of y.
    Error_code error = success;
    Stack_entry temp;

    if (y.full()) error = overflow;
    else if(x.empty()) error = underflow;
    else{
        while(!x.empty() && error == success){
            error = x.pop_top(temp);
            error = y.push(temp);
        }
    }


return error;
}

Error_code rev_queue(Extended_queue& q){
    Error_code error = success;
    Queue_entry temp;
    Stack temp_S;

    if(q.empty()) error = underflow;
    else{
        while(!q.empty()){
            q.retrieve_and_serve(temp);
            temp_S.push(temp);
        }
        while(!temp_S.empty()){
            temp_S.pop_top(temp);
            q.append(temp);
        }
    }


return error;
}

Error_code rev_stack(Stack& s){
    Error_code error = success;
    Stack_entry temp;
    Extended_queue temp_Q;

    if(s.empty()) error = overflow;
    else{
        while(!s.empty()){
            s.pop_top(temp);
            temp_Q.append(temp);
        }
        while(!temp_Q.empty()){
            temp_Q.retrieve_and_serve(temp);
            s.push(temp);
        }
    }


    return error;
}
