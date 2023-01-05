#ifndef HOME_H
#define HOME_H
#include<iostream>
#include"user-pass.h"
#include<map>
using namespace std;

enum commands{
    _guest_entry,
    _admin_entry,
    _setting,
    _registeration,
    _bad_command
};


void wellcome_message()
{
    cout << " ----------------------------------------------\n"
            "|                 Welcome                     |\n"
            "|               Puzzle game                   |\n"
            "|                                             |\n"
            "|    guest                     for guest entry|\n"
            "|    admin                     for admin entry|\n"
            "|    setting                   go to setting  |\n"
            "|    registeration             to register    |\n"
            " ----------------------------------------------\n" ;
}
#endif // HOME_H
