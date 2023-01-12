#ifndef HOME_H
#define HOME_H
#include<iostream>
#include<map>
using namespace std;

enum commands{
    _guest_entry,
    _help,
    _setting,
    _registeration,
    _sign_in,
    _bad_command,
    _quit,
    _jadval
};


commands get_commands();
void wellcome_message();
void setting();
#endif // HOME_H
