#include<iostream>
#include<string>
#include<fstream>
#include"user-log.h"
#include"z-user.h"
#include"home.h"

using namespace std;



int main()
{

    wellcome_message();
    setting();
    z_user n;
    while (true) {
        commands z = get_commands();
        switch (z) {
        case _sign_in: n.login();break;
        case _registeration: n.adduser();break;
        case _quit: return 0;
        case _help: wellcome_message();break;
        case _jadval:n.score_tb();break;
        case _setting:setting();break;
        case _guest_entry:n.guest();break;
        case _bad_command: cout<<"bad command!"<<endl;break;
        }
    }
    return 0;
}
