#include <QCoreApplication>
#include<iostream>
#include<fstream>
#include<string>
//#include<bits.h>
using namespace std;
#define user_table_file "users.txt"

//class registeration{
//public:
//   string username;
//   long long password;
//   void adduser();
//};
//registeration :: adduser(string username,long long password){
//    ifstream std_file (user_table_file);
//        if(std_file.is_open()){

//        }
//    cout << "Enter your username : ";
//    getline(cin,username);
//    cout << "Enter your password : ";
//    cin >> password;
//};
void password_difficulty(string password){

    long pass_len = password.length();
    while (true) {
        if((pass_len>=6) && (pass_len<=10))
            break;
        cout << "Try again! Your password should be between 6 and 10." << endl;
        cin >> password;

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
    if((upper || lower)&& specialchar && digit && (pass_len >=8))
        cout << "Your password is strong ."<< endl;
    else if((upper || lower)&&(digit|| specialchar) && (pass_len<=8))
        cout << "Your password is average ." << endl;
    else
        cout << "Your password is weak. You should change your password !"<<endl;

}
//void get_password(){
//    string password;
//    long pass_len = password.length();
//    cout << "Length of password should be between 6 and 10 ." << endl;
//    while (true) {
//        cin >> password;
//        if((pass_len>=6) && (pass_len<=10))
//            break;
//        cout << "Try again! Your password should be between 6 and 10." << endl;

//    }
//    password_difficulty(password,pass_len);

//}
int main()
{
    cout << "Length of password should be between 6 and 10 ." << endl;
    string password;
    cin >> password;
    password_difficulty(password);

    return 0;
}
