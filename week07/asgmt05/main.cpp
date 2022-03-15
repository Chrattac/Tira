#include "header.h"

enum Values{Jan = 10, Apr = 30, Jun = 20, Sep = 50, Nov = 30};

int main()
{

Stack s;
int size;

for(int i = 0; i<=10; i++){
      s.push(i);
}

size = s.getSize();
std::cout << "Size of the stack was: " << size << '\n';

return 0;
}