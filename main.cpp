#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "printbox.h"

#define SQUARE "\xE2 \x96 \xA0"

using namespace std;

void print_home(){
    cout << "Welcome to the home screen of Monopoly!!" << endl;
    cout << "Type in \"N\" to start a new game" << endl;
    cout << "Type in \"C\" to continue with save file" << endl;
    cout << "Type in \"Q\" to quit" << endl;
}

void start_game(){
    char a[40], sq[10][10];
    for (int i = 0; i < 40; i++){
        a[i] = 'X';
    }
    change_sq_print(a,sq);
}

int main() {
    print_home();
    char cond;
    cin >> cond;
    while (cond != 'N' && cond != 'C' && cond != 'Q'){
        cout << "Wrong instruction, please try again." << endl;
        cin >> cond;
    }
    switch(cond) {
        case 'N' : start_game(); break;
        case 'C' : break;
        case 'Q' : cout << "Okay. See you later, have a nice day." << endl; break;
    }



    return 0;
}
