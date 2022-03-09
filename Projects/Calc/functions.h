#pragma once

void introduction();
void instructions(bool);
char get_command();
bool do_command(char, Stack&);
bool isOperator(char);
bool calculator(Stack&, std::string&);