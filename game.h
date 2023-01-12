#ifndef GAME_H
#define GAME_H
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include<cstdlib>
using namespace std;

const int arraySize = 4;
string t1[ arraySize ] [ arraySize ] ={{"1","2","3","4"},
                                             {"5","6","7","8"},
                                             {"9","10","11","12"},
                                             {"13","14"," ","15"}};

string tc1  [ arraySize ] [ arraySize ] = {{"1","2","3","4"},
                                             {"5","6","7","8"},
                                             {"9","10","11","12"},
                                             {"13","14","15"," "}};

string t2[3][3]={{"1","2","3"},
                 {"4","5","6"},
                 {"7"," ","8"}};
string tc2[3][3]={{"1","2","3"},
                  {"4","5","6"},
                  {"7","8"," "}};
int f = 3;
int f1 = 2;
int z = 2;
int z1 = 1;
void left_side(){
    int s = f1;
    if(s + 1 < 4 && s >= 0){
    t1[f][f1] = t1[f][f1 + 1];
    t1[f][f1 + 1] = ' ';
    f1 += 1;
    }
};

void right_side(){
    int r = f1;
    if(r + 1 <= 4 && r > 0){
    t1[f][f1] = t1[f][f1 - 1];
    t1[f][f1 - 1] = ' ';
    f1 -= 1;
    }
};

void up_side(){
    int u = f;
    if(u + 1 < 4 && u >= 0){
    t1[f][f1] = t1[f + 1][f1];
    t1[f + 1][f1] = ' ';
    f += 1;
    }
};

void down_side(){
    int d = f;
    if(d + 1 <= 4 && d > 0){
    t1[f][f1] = t1[f - 1][f1];
    t1[f - 1][f1] = ' ';
    f -= 1;
    }
};

void left_side3(){
    int s = z1;
    if(s + 1 < 3 && s >= 0){
    t2[z][z1] = t2[z][z1 + 1];
    t2[z][z1 + 1] = ' ';
    z1 += 1;
    }
};


void right_side3(){
    int r = z1;
    if(r + 1 <= 3 && r > 0){
    t2[z][z1] = t2[z][z1 - 1];
    t2[z][z1 - 1] = ' ';
    z1 -= 1;
    }
};

void up_side3(){
    int u = z;
    if(u + 1 < 3 && u >= 0){
    t2[z][z1] = t2[z + 1][z1];
    t2[z + 1][z1] = ' ';
    z += 1;
    }
};

void down_side3(){

    int d = z;
    if(d + 1 <= 3 && d > 0){
    t2[z][z1] = t2[z - 1][z1];
    t2[z - 1][z1] = ' ';
    z -= 1;
    }
};


void bargasht(char o[],int p){
    if(o[p-1]=='R'||o[p-1]=='r'){
        left_side();
        return;
    }
    if(o[p-1]=='L'||o[p-1]=='l'){
        right_side();
        return;
    }
    if(o[p-1]=='U'||o[p-1]=='u'){
        down_side();
        return;
    }
    if(o[p-1]=='D'||o[p-1]=='d'){
        up_side();
        return;
    }
    if(o[p-1]=='B'||o[p-1]=='b'){
        bargasht(o,p-1);
        return;
    }
}

void bargasht3(char o[],int p){
    if(o[p-1]=='R'||o[p-1]=='r'){
        left_side3();
        return;
    }
    if(o[p-1]=='L'||o[p-1]=='l'){
        right_side3();
        return;
    }
    if(o[p-1]=='U'||o[p-1]=='u'){
        down_side3();
        return;
    }
    if(o[p-1]=='D'||o[p-1]=='d'){
        up_side3();
        return;
    }
    if(o[p-1]=='B'||o[p-1]=='b'){
        bargasht3(o,p-1);
        return;
    }
}
void random(){

    for (int i=0 ; i<10000 ; i++){
        int a=1+rand()%4;
        switch (a) {
        case 1:
            up_side();
            break;
        case 2:
            down_side();
            break;
        case 3:
            right_side();
            break;
        case 4:
            left_side();
            break;

        }
    }
}

void random3(){

    for (int i=0 ; i<10000 ; i++){
        int a=1+rand()%4;
        switch (a) {
        case 1:
            up_side3();
            break;
        case 2:
            down_side3();
            break;
        case 3:
            right_side3();
            break;
        case 4:
            left_side3();
            break;

        }
    }
}
int winnner1(){
    int w=0;
    for(int i = 0;i<4;++i){
        for(int j = 0; j<4;++j){
            if(t1[i][j]==tc1[i][j]){
                w = 1;
            }
            else
                return -1;
        }
    }
    return w;
}
int winnner2(){
    int w=0;
    for(int i = 0;i<3;++i){
        for(int j = 0; j<3;++j){
            if(t2[i][j]==tc2[i][j]){
                w = 1;
            }
            else
                return -1;
        }
    }
    return w;
}

int puzzel_game(int t,int k){
    if(k==15){
        srand(time(0));
        random();
        char d[50];
        int a = 0;
        do{
            for(int i = 0; i<4;++i){
                for(int j = 0; j<4;++j){
                     cout<<left<<setw(5)<<t1[i][j]<<left<<setw(5)<<"  ";
                }
                cout<<endl<<endl;
            }

            char r;
            cout << "R -> right , L -> left , D -> down , U -> up , B -> undo"<<endl<<endl;
            cout << "number of movements --->"<<a<<"/"<<t<<endl;
            cin >> r;
            d[a]=r;
            switch (r) {
            case 'R':
            case'r':
                right_side();
                a++;
                break;
            case 'L':
            case 'l':
                left_side();
                a++;
                break;
            case 'D':
            case 'd':
                down_side();
                a++;
                break;
            case 'U':
            case 'u':
                up_side();
                a++;
                break;
            case 'B':
            case'b':
                bargasht(d,a);
                a--;
                break;
            default: cout << "Wrong! Try again."<<endl;
                break;
            }
            int win;
            win = winnner1();
            if(win == 1){
                cout << "Hooray! You win."<<endl;
                return 15;
            }
            system("cls");
        }while (a<=t);
        cout << '\t'<<"Game over :("<<endl;
        int m = 0;
        for(int i = 0; i<4;++i){
            for(int j = 0;j<4;++j){
                if(t1[i][j]==tc1[i][j]){
                    m++;
                }
            }
        }
        return m;
    }
    if(k==8){
        srand(time(0));
        random3();
        char d[50];
        int a = 0;
        do{
            for(int i = 0; i<3;++i){
                for(int j = 0; j<3;++j){
                    cout<<left<<setw(5)<<t2[i][j]<<left<<setw(5)<<"  ";
                }
                cout<<endl<<endl;
            }

            char r;
            cout << "R -> right , L -> left , D -> down , U -> up , B -> undo"<<endl<<endl;
            cout << "number of movements --->"<<a<<"/"<<t<<endl;
            cin >> r;
            d[a]=r;
            switch (r) {
            case 'R':
            case'r':
                right_side3();
                a++;
                break;
            case 'L':
            case 'l':
                left_side3();
                a++;
                break;
            case 'D':
            case 'd':
                down_side3();
                a++;
                break;
            case 'U':
            case 'u':
                up_side3();
                a++;
                break;
            case 'B':
            case'b':
                bargasht3(d,a);
                a--;
                break;
            default: cout << "Wrong! Try again."<<endl;
                break;
            }
            int win;
            win = winnner2();
            if(win == 1){
                cout << "Hooray! You win."<<endl;
                return 8;
            }
            system("cls");
        }while (a<=t);
        cout << '\t'<<"Game over :("<<endl;
        int m = 0;
        for(int i = 0; i<3;++i){
            for(int j = 0;j<3;++j){
                if(t2[i][j]==tc2[i][j]){
                    m++;
                }
            }
        }
        return m;
    }
    return 0;

}

#endif // GAME_H
