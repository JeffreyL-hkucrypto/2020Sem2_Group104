#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "printbox.h"
#include "gamefunction.h"

using namespace std;

void start_game(){
    char a[40], sq[10][10];
    for (int i = 0; i < 40; i++){
        a[i] = 'X';
    }
    int np;
    cout<<"number of player?(2-4)"<<endl;
    cin>>np;
    while (np!=2 && np!=3 &&np!=4){
        cout<<"Invalid input, please try again."<<endl;
        cout<<"number of player?(2-4)"<<endl;
        cin>>np;
    }
    Getplayer(np);  //the code is included in gamefunction.cpp
    gameloop(np);
    
    cout<<"------------------------------------------------------END------------------------------------------------------------------------"<<endl;
}

int main() {
    print_home();
    char cond;
    cin >> cond;
    while (cond != 'N' && cond != 'C' && cond != 'Q'){
        cout << "Invalid input, please try again." << endl;
        cin >> cond;
    }
    switch(cond) {
        case 'N' : start_game(); break;
        case 'C' : break;
        case 'Q' : cout << "Okay. See you later, have a nice day." << endl; break;
    }
    return 0;
}
