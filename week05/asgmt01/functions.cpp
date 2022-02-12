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
    std::cout << std::endl
         << "This program allows the user to enter one command" << std::endl
         << "(but only one) on each input line." << std::endl
         << "For example, if the command S is entered, then" << std::endl
         << "the program will serve the front of the queue." << std::endl
         << std::endl

         << " The valid commands are:" << std::endl
         << "A - Append the next input character to the extended queue" << std::endl
         << "S - Serve the front of the extended queue" << std::endl
         << "R - Retrieve and print the front entry." << std::endl
         << "# - The current size of the extended queue" << std::endl
         << "C - Clear the extended queue (same as delete)" << std::endl
         << "P - Print the extended queue" << std::endl
         << "H - This help screen" << std::endl
         << "Q - Quit" << std::endl

         << "Press <Enter> to continue." << std::flush;

    char c;
    do {
       std::cin.get(c);
    } while (c != '\n');
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