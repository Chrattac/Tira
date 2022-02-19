#include "header.h"

char compareInput(std::string& s){
    int i = 0;
    Extended_queue q;

    for(i; i<s.length(); i++){
        if(s[i] == ':') break;
        else q.append(s[i]);
    }

    i++;

    if(s.length() == i-1) return 'N';
    else if (q.size() < s.length()-i) return 'R';
    else if (q.size() > s.length()-i) return 'L';
    else return 'S';
}