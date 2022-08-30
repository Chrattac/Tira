#include "header.h"

int Key::comparisons = 0;

Key::Key(){}

Key::Key(int x) { set_key(x); }

int Key::get_key() const {
    return key;
}

void Key::set_key(int x){
    key = x;
}

