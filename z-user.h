#ifndef ZUSER_H
#define ZUSER_H
#include<string>
#include<iostream>

using namespace std;
#define user_table "users.txt"

class registeration{
public:
    string username;
    string password;
    registeration();
    string score;
};

#endif // ZUSER_H
