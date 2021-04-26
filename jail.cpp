#include <iostream>
#include <string>
#include "GameFunction.h"
#include "print.h"

using namespace std;

void Jail(player a){
    pla_in_jail[a.name] = 0;
}

void jail_break(player a){
    char ans = 'a';
    while (ans != 'y' && ans != 'n') {
        cout << "Do you want to pay M$50 in order to get out from jail? (y/n) ";
        cin >> ans;
    }
    if (ans == 'n') {
        if (pla_in_jail[a.name] == 3) {
            cout << "The guard says, \'Sorry, but you have to pay.\'" << endl;
            cout << "The guard has taken M$50 from your account." << endl;
            pause();
            a.money -= 50;
            pla_in_jail.erase(a.name);
        }
        else {
            cout << "The guard says, \'Okay, then please roll dice.\'" << endl;
            int dice1, dice2;
            srand(time(NULL));
            dice1 = (rand() % 6) + 1;
            dice2 = (rand() % 6) + 1;
            if (dice1 == dice2){
                cout << "The guard says, \'Well, you'll not be lucky next time.\'" << endl;
                pause();
                pla_in_jail.erase(a.name);
            }
            else {
                cout << "The guard says, \'Wait for the next round.\'";
                (pla_in_jail[a.name])++;
                pause();
            }
        }
    }
    else {
        cout << "The guard says, \'Good choice!\'" << endl;
        cout << "The guard has taken M$50 from your account." << endl;
        pause();
        a.money -= 50;
        pla_in_jail.erase(a.name);
    }
}
