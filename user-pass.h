#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include"home.h"
#include<map>
#ifndef USER_H
#define USER_H
using namespace std;
#define user_table "users.txt"

class registeration{
public:
    map <string , registeration> user_tb;
    string username;
    string password;
    void checkusername();
    void login();

    void add_user();
    ~registeration();
};

//registeration::registeration(){

//    ifstream std_file ;
//    std_file.open(user_table);
//    string s1,s2,s3;
//    while(std_file.good()){
//        getline(std_file,s1);
//        istringstream s(s1);
//        s>>s2>>s3;
//        registeration a;
//        a.username = s2;
//        a.password =s3;
//        user_tb[s2]=a;

//    }
//    std_file.close();

////    if (std_file.is_open()) {
////        while (!std_file.eof()) {
////            string line ;
////            getline ( std_file , line ) ;
////            vector<string> res = split(line,',');
////            for ( auto x : res )
////                cout << x << endl ;
////        }
////    }
//}

void password_difficulty(string &password){

    long pass_len = password.length();
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
void registeration::login()
    {
    ofstream users(user_table,ios::app);
    string username, password;
    cout << "enter username: " << endl;
    cin >> username;
    users<<username;
    cout << "enter password: " << endl;
    cout << "Length of password should be between 6 and 10 characters ." << endl;
    cin >> password;
    users<<password;
    password_difficulty(password);
    if (users.is_open())
    {
        while (!users.eof())
        {

            if (username == username && password == password)
            {
                cout << "Login successfully." << endl;
                //cust_mainmenu();
                break;
            }
            else
            {
                cout << "Wrong username or password!" << endl;
                break;
            }
        }

        users.close();
    }
}


void registeration::add_user()
{
    registeration user;
    string s4;
    cout<<"Enter your username: "<<endl;
    getline(cin,s4);
    if(user_tb.find(s4)!=user_tb.end()){
        cout << "username tekrari!"<<endl;
        return;
    }
    user.username = s4;
    cout<<"Enter your password: "<<endl;
    getline(cin,user.password);
    password_difficulty(user.password);
    user_tb [s4]=user;
}
registeration::~registeration()
{
    ofstream std_file;
    std_file.open(user_table,ios::app | ios::out);

    for ( auto x : user_tb ) {
        registeration stud = x.second ;
        std_file <<
                    stud.username << " " <<
                    stud.password << endl ;

    }

}
#endif // USER_H
