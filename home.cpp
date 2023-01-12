#include"home.h"


commands get_commands(){
    string operation;
    cout << " ________________________________\n " ;
    cout << " enter command : " ;
    cin >> operation;
    if(operation=="guest")
        return _guest_entry;
    if(operation=="help")
        return _help;
    if(operation=="registeration")
        return _registeration;
    if(operation=="sign-in")
        return _sign_in;
    if(operation=="quit")
        return _quit;
    if(operation=="jadval")
        return _jadval;
    if(operation=="setting")
        return _setting;
    else
        return _bad_command;
}

void setting(){
    cout<<" -----------------------------------------------------\n"
          "|   level                     number of movement      |\n"
          "|     1                              50               |\n"
          "|     2                              45               |\n"
          "|     3                              40               |\n"
          "|     4                              35               |\n"
          "|     5                              30               |\n"
          "|                                                     |\n"
          "|    size                     number of puzzle        |\n"
          "|    3 x 3                            8               |\n"
          "|    4 x 4                            15              |\n"
          " -----------------------------------------------------\n";
}
void wellcome_message()
{
    cout << " ----------------------------------------------\n"
            "|                 Welcome                     |\n"
            "|               Puzzle game                   |\n"
            "|                                             |\n"
            "|    guest                     for guest entry|\n"
            "|    help                     to help         |\n"
            "|    setting                   go to setting  |\n"
            "|    registeration             to register    |\n"
            "|    sign-in                   to voorod      |\n"
            "|    quit                      to Exit        |\n"
            "|    jadval                     to show score |\n"
            " ----------------------------------------------\n" ;
}
