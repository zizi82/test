#ifndef USERLOG_H
#define USERLOG_H
#include<map>
#include"z-user.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

class z_user{
public:
    map <string , registeration> user_tb;
    z_user();
    void adduser();
    void login();
    void guest();
    ~z_user();
    void score_tb();
};

#endif // USERLOG_H
