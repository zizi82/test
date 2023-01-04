#include<iostream>
#include<fstream>
using namespace std;
#define user_table_file "users.txt"

class registeration{
private:
    string username;
    long  password;
public:
   void adduser();
};
void registeration::adduser(){
    ofstream usertable("users.txt");
    cout << "Enter your username : ";
    getline(cin,username);
    usertable<<username;
    cout << "Enter your password : ";
    cin >> password;
    usertable<<username;
    usertable.close();
};

int main()
{


    return 0;
}
