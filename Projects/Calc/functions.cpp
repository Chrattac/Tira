
#include "header.h"

char get_command()
{
   char command;
   bool waiting = true;

   while (waiting) {
      std::cin >> command;
      command = tolower(command);
      if (isOperator(command) || command == '?') waiting = false;
      else {
         std::cout << "\nPlease enter a valid command\n"   << std::endl;
         instructions(true);
      }
   }
   return command;
}


bool do_command(char command, Stack& numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    Stack temp;
   double p, q;
   int i;
   switch (command) {
   case '?':
      std::cout << "Enter a real number: " << std::flush;
      std::cin >> p;
      if (numbers.push(p) == overflow)
         std::cout << "Warning: Stack full, lost number" << std::endl;
      break;

   case '=':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else
         std::cout << p << std::endl;
      break;

   case '+':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }
      break;
    case '-':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q - p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }

    break;

    case '*':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q * p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }

    break;

    case '/':
        if (numbers.top(p) == underflow)
           std::cout << "Stack empty" << std::endl;
        else if(p == 0) std::cout << "Can't divide by zero!\n";
        else {
           numbers.pop();
           if (numbers.top(q) == underflow) {
              std::cout << "Stack has just one entry" << std::endl;
              numbers.push(p);
           }

           else {
              numbers.pop();
              if (numbers.push(q / p) == overflow)
                 std::cout << "Warning: Stack full, lost result" << std::endl;
           }
        }

    break;

    case '%':

      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(std::fmod(p, q)) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }

    break;

    case '^':

      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(pow(p,q)) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }

    break;

    case 'v':

      if (numbers.top(p) == underflow) std::cout << "Stack empty" << std::endl;
      else if(p < 0) std::cout << "Can't take square root from negative number";
      else {
        numbers.pop();
        numbers.push(std::sqrt(p));
      }

    break;

    case 'x':

    if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            numbers.push(p);
            numbers.push(q);

         }
      }

    break;

    case 's':
        q=0;
        if(numbers.empty()) std::cout << "You didn't give any numbers!\n";
        else{
            while(!numbers.empty()){
                numbers.pop_top(p);
                q+=p;
            }
            numbers.push(q);
        }

    break;

    case 'a':
        i = 0;
        q = 0;
        if(numbers.empty()) std::cout << "You didn't give any numbers!\n";
        else{
            while (!numbers.empty()){
                numbers.pop_top(p);
                q+=p;
                i++;
            }
            numbers.push(q/i);
        }
        break;
    case 'q':
        std::cout << "Calculation finished.\n";
        return false;
    }
   return true;
}

bool isOperator(char c){
    bool oper = false;
    for(int i = 0; i<OPERATORS_SIZE; i++){
        if(operators[i]==c) {
            oper = true;
            break;
        }
    }
    
    return oper;
}

bool calculator(Stack& stored_numbers, std::string& input){
    //prompt
    
    std::string temp = "$";
    double num;
    char c;
    bool cntn = true;

    for(int i = 0; i<input.length(); i++){
              
        if(isdigit(input[i]) || input[i] == '.' || (input[i] == '-' && isdigit(input[i+1]))){
            if (temp[0] == '$') temp[0] = input[i];
            else temp+=input[i];
        }
        else if(isspace(input[i])){
            if(std::istringstream(temp) >> num) {
                stored_numbers.push(num);
                temp="$";
            }
        }
        else if(isOperator(input[i])) cntn = do_command(input[i], stored_numbers);
    }

    if(std::istringstream(temp) >> num) {
        stored_numbers.push(num); //if only numbers were given, check
        temp = "$";
    }

    return cntn;

}

void introduction(){
    std::cout << "Welcome to postfix calculator!\n\n";
    std::cout << "To check 5 points worth of program just run program\n";
    std::cout << "With arguments being commands in a single row for 4 points excercise.\n";
    std::cout << "ie [ ./{PROGRAM_NAME} 2.5 1.7 + 8.19 v / ] returns 2.86182. \n\n";
    std::cout << "Give choice [1] for 1 point, [2] for 2-4 points, [9] to quit: ";
}

void instructions(bool simple){
    std::cout << "Commands are:\n"
        << "Operators:\n"
        << "[-], [+], [*], [/], [^], [%]\n"
        << "[v] for square root, [a] for average\n"
        << "[s] for sum, [x] for exchange\n";
        if(simple) std::cout << "[?]push to stack\n";
        std::cout << "[=] to print top\n"
        << "[q] to quit";

        if (simple) std::cout << "\nSelect command and press <Enter>: ";
        else {
            std::cout << "\n\nYou can give all the numbers in a single row with\n"
                <<  "operators, all individual numbers and operators should be\n"
                << "separated with <SPACE> or type them one after one with enter\n" 
                << "after each. Numbers should be real.\n\n";
            std::cout << "Give input and press <ENTER>: ";
        }
}

