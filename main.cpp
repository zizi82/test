#include<iostream>
#include<string>
#include<fstream>
#include"user-pass.h"
#include "home.h"

using namespace std;



int main()
{

    wellcome_message();
    registeration user1;
   // user1.username_and_password();
    user1.add_user();

    return 0;
}
