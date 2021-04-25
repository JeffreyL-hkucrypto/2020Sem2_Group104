#include <iostream>
#include <string>
#include <ctime>
#include "GameFunction.h"
#include "jail.h"

void Jail(player a){
    jail u;
    u.prisoner = a;
    u.round = 0;
    pla_in_jail.push_back(u);
}

void check_in_jail(){

}

void jail_break(player a){
    char ans = 'a';
    while (ans != 'y' or ans != 'n') {
        cout << "Do you want to pay M$50 in order to get out from jail? (y/n) ";
        cin >> ans;
    }
    if (ans == 'n') {
        if (counter == 3) {
            cout << "The guard says, \'Sorry, but you have to pay.\'" << endl;
            cout << "The guard has taken M$50 from your account." << endl;
            pause();
            a.money -= 50;
        }
        else {
            cout << "The guard says, \'Okay, then please roll dice.\'" << endl;
            int dice1, dice2;
            srand(time());
            dice1 = rand() % 6;
            dice2 = rand() % 6;
            if (dice1 == dice2){
                cout << "The guard says, \'Well, you'll not be lucky next time.\'" << endl;
                pause();
            }
            else {
                cout << "";

                pause();
            }
        }
    }
    else {
        cout << "The guard says, \'Good choice!\'" << endl;
        cout << "The guard has taken M$50 from your account." << endl;
        pause();
        a.money -= 50;
    }
}