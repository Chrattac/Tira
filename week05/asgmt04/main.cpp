#include "header.h"

#define MAX 50 // just to ease for loops, is half of the maxstack & maxqueue

int main(){

Stack stack_A, stack_B, stack_C;
Extended_queue queue_A, queue_B, queue_C;
char cmd;
Error_code error = success;

for (int i = 0; i<MAX; i++){
      stack_A.push(uni(rng));
      stack_B.push(uni(rng));
      queue_A.append(uni(rng));
      queue_B.append(uni(rng));

}

do{
      std::cout << "Current stacks:\n";
      std::cout << "Stack A:\n";
      stack_A.print();
      std::cout << "Stack B:\n";
      stack_B.print();
      std::cout << "Stack C:\n";
      stack_C.print();
      std::cout << "Current queues:\n";
      std::cout << "Queue A:\n";
      queue_A.print();
      std::cout << "Queue B:\n";
      queue_B.print();
      std::cout << "Queue C:\n";
      queue_C.print();


      std::cout << "Choose subexcercise\n" 
            << "A, B, C, D, E, F, [Quit]: ";
      cmd = get_command();
      switch(cmd){
            case 'a':

            break;

            case 'b':
            break;

            case 'c':
            break;

            case 'd':
            break;

            case 'e':
            break;

            case 'f':
            break;

            case 'h':std::cout << "Choose subexcercise\n" 
            << "A, B, C, D, E, F, [Quit]: ";
            break;

            case 'q':
            std::cout << "Thank you have a nice day!\n";
            break;

            default:
                  std::cout << "Fatal error";
                  error = fatal;
                  break;
      }

}while(cmd!='q' && error==success);

if(error!=success) std::cout << "Program exitting with error (overflow, or underflow)";

return error;

}