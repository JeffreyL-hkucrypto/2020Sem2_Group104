#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "printbox.h"
#include "gamefunction.h"

using namespace std;

void start_game() {
    char a[40];
    for (int i = 0; i < 40; i++) {
        a[i] = 'X';
    }
    int np;
    cout << "number of player?(2-4): ";
    cin >> np;
    while (np != 2 && np != 3 && np != 4) {
        cout << "Invalid input, please try again." << endl;
        cout << "number of player?(2-4): ";
        cin >> np;
    }
    GetPlayer(np);  //the code is included in gamefunction.cpp
    gameloop(np);

    cout
            << "------------------------------------------------------END------------------------------------------------------------------------"
            << endl;
}

void inputfile() {
    string f;
    cout << "Select a save file to continue" << endl
         << "Please be noted that the file should be .txt text file "
         << "and in the same directory with your game" << endl
         << "Example: type in \"Save1\""
         << "File name: ";
    cin >> f;
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
