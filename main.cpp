#include <QCoreApplication>
#include<iostream>
#include<string>
#include<fstream>
#include<QString>
#include<QStringList>
#define user_table "users.txt"
using namespace std;


class registeration{
private:
    string username;
    string password;
public:
   void adduser();
};
void password_difficulty(string password){

    long pass_len = password.length();
    while (true) {
        if((pass_len>=6) && (pass_len<=10))
            break;
        cout << "Try again! Your password should be between 6 and 10 characters." << endl;
        getline(cin,password);

    }
    bool upper = false , lower = false , specialchar = false, digit = false;
    char specialcharacter[]="*!@#$%&+";
    for(int i = 0 ; i < pass_len ; i++)
    {
        if(islower(password[i]))
            lower = true;
        if(isupper(password[i]))
            upper = true;
        if(isdigit(password[i]))
            digit = true;
        for(int j = 0; j<8;j++){
            if(password[i]==specialcharacter[j])
                specialchar = true;
        }

    }
    if((upper || lower)&& specialchar && digit && (pass_len>=8))
        cout << "Your password is strong ."<< endl;
    else if((upper || lower)&&(digit|| specialchar) && (pass_len<=8))
        cout << "Your password is average ." << endl;
    else
        cout << "Your password is weak!"<<endl;

}
void registeration::adduser(){
    ifstream user(user_table, ios::app);
    if(!user){
        cout<<"error file"<<endl;
        return;
    }

    else
    {
        cout << "Enter your username : ";
        getline(cin,username);
        user >> username;
        cout <<"Enter your password :"<<endl;
        cout << "Length of password should be between 6 and 10 characters ." << endl;
        getline(cin,password);
        user >> password;
        password_difficulty(password);
        user.close();
    }

};



int main()
{
    registeration user1;
    user1.adduser();

    return 0;
}
