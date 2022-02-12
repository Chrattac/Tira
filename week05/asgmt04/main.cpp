#include "header.h"

#define MAX 5 // just to ease for loops, is half of the maxstack & maxqueue

int main(){

std::random_device rd;     // only used once to initialise (seed) engine
std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
std::uniform_int_distribution<int> uni(0,255); // guaranteed unbiased

Stack stack_A, stack_B, stack_C, stack_1, stack_2;
Extended_queue queue_A, queue_B, queue_C, queue_1, queue_2;
char cmd, choice;
Error_code error = success;

for (int i = 0; i<MAX; i++){
      stack_A.push(uni(rng));
      stack_B.push(uni(rng));
      queue_A.append(uni(rng));
      queue_B.append(uni(rng));

}

do{
      std::cout << "\n\nCurrent stacks:\n";
      std::cout << "\nStack A:\n";
      stack_A.print();
      std::cout << "\nStack B:\n";
      stack_B.print();
      std::cout << "\nStack C:\n";
      stack_C.print();
      std::cout << "\nCurrent queues:\n";
      std::cout << "\nQueue A:\n";
      queue_A.print();
      std::cout << "\nQueue B:\n";
      queue_B.print();
      std::cout << "\nQueue C:\n";
      queue_C.print();

      std::cout << "\n\n";

      std::cout << "Notice that the program is just a show case for the excercise and may end\n"
            << "abruptly due to over or underflow if ran in certain order or several times in a row.\n"
            << "You should be able to run the program in order of A-B without problems.\n"
            << "Choose subexcercise\n"
            << "A, B, C, D, E, F, [Quit]: ";
      cmd = get_command();

      std::cout << "===========================\n";
      switch(cmd){
            case 'a':
            std::cout << "Moving Stack A into Queue C: ";
            error = stack_to_queue(stack_A, queue_C); 
            break;

            case 'b':
            std::cout << "Moving Queue B into Stack C: ";
            error = queue_to_stack(queue_B, stack_C);
            break;

            case 'c':
            std::cout << "Emptying stack C on top of stack A";
            error = pile_stack(stack_A, stack_C);
            break;

            case 'd':
            std::cout << "Piling Stack A on top of stack B in reverse order";
            error = pile_stack_rev(stack_A, stack_B);
            break;

            case 'e':
            std::cout << "Reversing queue C";
            error = rev_queue(queue_C);
            break;

            case 'f':
            std::cout << "Reversing stack B";
            error = rev_stack(stack_B);
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

      if(error != success){
            if (error == overflow) std::cout << "\n######################\n## overflow happened ##\n######################\n";
            else if (error == underflow) std::cout << "\n########################\n## underflow happened ##\n########################\n";
            else std::cout << "\n######################\n## unexpected error ##\n######################\n";
      }

}while(cmd!='q' && error!=fatal);

if(error!=success) std::cout << "\nProgram exitting with fatal error";

return error;

}