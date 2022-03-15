#include "header.h"

int GCD(int x, int y){
    //Let's check first if there is need to even start doing anything
    if(x == y) return x;
    if(x==1 || y==1 || (isPrime(x) && isPrime(y))) return 1;
    
    int i = 2, gcd = 1;
    
    while(i<=x && i<=y){
        std::cout << ""; //Weird bug, while loop doesn't run through w/o this std::cout!?
        if(x%i == 0 && y%i == 0) {
            x=x/i;
            y=y/i;
            gcd*=i;

        }
        else if ( i>=x/2 && i>=y/2 ) break;
        else{
            while(i<=x && i<=y) if(isPrime(++i)) break; //search for next prime to divide with
        }
    }

    
    return gcd;
}



// RECURSIVE
int rec_GCD(int x, int y){

    if(y == 0) return x;

    return rec_GCD(y,x%y);
}


// EXTRA
bool isPrime(int x){
    bool prime;
    if(x == 2){
        prime = true;
    }
    else{
        for (int i = 2; i<(x/2); i++){
            if(x%i==0){
                prime = false;
                break;
            }else{prime == true;}
        }
    }



    return prime;
}

int getInteger(){
    bool check;
    int integer;

    do{
        std::cin >> integer;
        if(std::cin.fail() || integer < 1){
            std::cout << "That's not a positive integer!\n";
            check = false;
            std::cin.clear();
            std::cin.ignore(100,'\n');
        }
        else check = true;
    
    }while(!check);

    return integer;
}