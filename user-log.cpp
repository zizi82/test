#include<iostream>
#include"user-log.h"
#include"z-user.h"
#include<iomanip>
#include"game.h"
using namespace std;


z_user::z_user()
{
    ifstream std_file ;
    std_file.open(user_table);
    registeration ba;
    string s1,s2,s3,s4;
    while(std_file.good()){
        getline(std_file,s1);
        istringstream s(s1);
        s>>s2>>s3>>s4;
        ba.username = s2;
        ba.password =s3;
        ba.score = s4;
        user_tb[s2]=ba;
    }
    std_file.close();

}


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


int level(int l){
    switch (l) {
    case 1: return 50;
    case 2: return 45;
    case 3: return 40;
    case 4: return 35;
    case 5: return 30;
    }
    return 40;
}
void z_user::adduser()
{
    registeration user;
    string s4;
    cout<<"Enter your username: "<<endl;
    cin.ignore();
    getline(cin,s4);
    if(user_tb.find(s4)!=user_tb.end()){
        cout << "username tekrari!"<<endl;
        return;
    }
    user.username = s4;
    cout<<"Enter your password: "<<endl;
    getline(cin,user.password);
    password_difficulty(user.password);
    user.score='0';
    user_tb [s4]=user;
}

void z_user::login()
{

    string username, password;
    cout << "enter username: " << endl;
    cin.ignore();

    getline(cin,username);
    if(user_tb.find(username)==user_tb.end()){
        cout<<"username not found."<<endl;
        return;
    }
    registeration s5;
    s5.username = username;
    for(auto& x:user_tb){
        if(x.first==username){
            s5 = x.second;
        }
    }
    cout<<s5.password<<endl;
    cout << "enter password: " << endl;
    getline(cin,password);
    if(password != s5.password){
        cout<<"Invalid password !"<<endl;
        return;
    }
    s5.password = password;
    cout <<"Please choose your level :"<<endl;
    int k;
    cin >> k;
    int q = level(k);
    cout << "8-puzzle or 15-puzzle ? (Enter 8 or 15) "<<endl;
    int s;
    int e ;
    cin >> s;
    cout << "start game."<<endl;
    e = puzzel_game(q,s);
    if(s==8)
        e=e*k;
    else
        e=e*k*2;
    cout <<"score: "<< e << endl;
    s5.score = to_string(e);
    user_tb[username]=s5;
}

void z_user::guest()
{
    cout <<"Please choose your level :"<<endl;
    int k;
    cin >> k;
    int q = level(k);
    cout << "8-puzzle or 15-puzzle ? (Enter 8 or 15) "<<endl;
    int s;
    int e ;
    cin >> s;
    cout << "start game."<<endl;
    e = puzzel_game(q,s);
    cout <<"score: "<< e << endl;
}

z_user::~z_user()
{
    ifstream user1;
    user1.open(user_table);
    user1.close();
    remove(user_table);
    ofstream user2;
    user2.open(user_table,ios::app | ios::out);
    for(auto x:user_tb){
        registeration user=x.second;
        user2<<user.username<< " " <<user.password<<" "<<user.score<<endl;
    }

}

void z_user::score_tb()
{
    cout << left<< setw(10)<<"username"<<left<<setw(5)<<" "<<left<<setw(10)<<"score"<<endl;
    for(auto x:user_tb){
        registeration us = x.second;
        cout<<left<<setw(10)<<x.first<<left<<setw(5)<<" "<<left<<setw(10)<<us.score<<endl;
    }

}
