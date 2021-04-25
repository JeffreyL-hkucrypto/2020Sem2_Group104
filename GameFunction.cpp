#include <iostream>
#include <string>
#include <vector>
#include "print.h"
#include "GameFunction.h"

using namespace std;

class player {
public:
    string status;
    string name;
    int money;
    int steps;
    int position;
    int doubled_counter;
};

vector<player> players;

void GetPlayer(int i) {
    for (int j = 0; j < i; j++) {
        cout << "Please enter your name: ";
        player i;
        cin >> i.name;
        i.status = "playing";
        i.money = 150000;
        i.steps = 0;
        i.position = 0;
        i.doubled_counter = 0;
        players.push_back(i);
    }
}

int checklosing(int num_player) {
    for (int j = 0; j < num_player; j++) {
        if (players[j].money <= 0) {
            players[j].status = "bankrupt";
            cout << players[j].name << " went bankrupt" << endl
                 << "Press ENTER to continue.";
            cin.get();
            num_player--;
        }
    }
    return num_player;
}

void OnStartPoint(player pla) {
    cout << pla.name << ", you have got M$2000 by passing through the start point" << endl
         << "Press ENTER to continue." << endl;
    cin.get();
    pla.money += 2000;
}

void OnFreeparking(player pla) {
    cout << pla.name << "just visited the car park." << endl
         << "Press ENTER to continue.";
    cin.get();
}

void OnJail(player pla) {
    if (pla_in_jail.size() == 0) {
        cout << pla.name << "just visited the jail." << endl
             << "Press ENTER to continue.";
        cin.get();
    } else {
        int num = pla_in_jail.size();
        cout << pla.name << "just paid a visit to ";
        for (int n = 0; n < num; n++) {
            cout << pla_in_jail[n].player;
        }
        cout << "." << endl << "Press ENTER to continue.";
        cin.get();
    }
}

void OnGotoJail(player pla) {
    Jail(pla);
}

void OnLand(int pos, player pla) {
    char ans;
    if (lands[(board[pos])].status = "available") {
        cout << pla.name << ", would you pay " << lands[(board[pos])].cost << "to buy " << board[pos] << "? (y/n)"
             << endl;
        cin >> ans;
        while (ans != 'y' && ans != 'n') {
            cout << "Invalid input, please try again." << endl;
            cout << pla.name << ", would you pay M$" << lands[(board[pos])].cost << "to buy" << board[pos] << "? (y/n)"
                 << endl;
            cin >> ans;
        }
        if (ans == 'y') {
            if (pla.moeny > lands[(board[pos])].cost) {
                pla.moeny -= lands[(board[pos])].cost;
                lands[(board[pos])].status = pla;
                cout << pla.name << " own " << board[pos] << " now" << endl;
                cout << pla.name << "account remains: M$" << pla.money << endl;
            } else {
                cout << "You don't have enough money to buy this property." << endl;
            }
        } else {
            cout << board[pos] << "is owned by player:" << lands[(board[pos])].status + 1
                 << endl;  //have to +1 before printing out the player number
            cout << pla.name << "have to play " << lands[(board[pos])].rent << " to player: "
                 << lands[(board[pos])].status + 1 << " as rent " << endl;
            pla.moeny -= lands[(board[pos])].rent;
            players[(lands[(board[pos])].status)].moeny += lands[(board[pos])].rent;
            cout << pla.name << "account remains: M$" << pla.money << endl;
            cout << "player" << (lands[(board[pos])].status) + 1 << "account remains: "
                 <<[players[(board[pos])].status)].money << endl;
        }
    }
}


void CheckEvent(player pla) {
    int pos = pla.position;
    cout << pla.name << ", you are at " << board[pos] << " now." << endl;

    if (pos == 0) {
        OnStartPotint(pla);
    } else if (pos == 2 || pos == 17 || pos == 33) {
        OnCommunityChest(pla);
    } else if (pos == 7 || pos == 22 || pos == 36) {
        Onchange(pla);
    } else if (pos == 20) {
        OnFreeparking(pla);
    } else if (pos == 30) {
        OnGotoJail(pla);
    } else if (pos == 10) {
        OnJail(pla);
    } else {
        Onland(pos, pla);
    }
}

void gameloop(int i) {
    string fake_dice;
    int real_dice1, real_dice2;
    int num_player;
    while (num_player > 1) {
        for (int j = 0; j < i; j++) {
            if (players[j].status != "bankrupt") {

                cout << players[j].name << "Please enter a number to roll a dice" << endl;
                cin >> fake_dice;
                srand(time(NULL));
                real_dice1 = rand() % 6;
                real_dice2 = rand() % 6;
                cout << "You've rolled " << real_dice1 << " & " << real_dice2 << endl
                     << "Press ENTER to continue." << endl;
                cin.get();
                cout << real_dice1 + real_dice2 << "steps forward" << endl
                     << "Press ENTER to continue.";
                cin.get();
                players[j].steps += (real_dice1 + real_dice2);
                players[j].position = players[j].steps % 40;

                CheckEvent(players[j]);
                num_player = checklosing(num_player);
                if (real_dice1 == real_dice2) {
                    if (players[j].doubled_counter < 2) {
                        players[j].doubled_counter++;
                        j--;
                    } else {
                        players[j].position = 9;
                        players[j].steps = 9;
                        players[j].doubled_counter = 0;
                        OnGotoJail(players[j]);
                    }
                }
            } else {
                cout << players[j].name << "went bankrupt" << endl;
            }
            for (int k = 0; k < i; k++) {
                if (players[k].status != "bankrupt") {
                    cout << "Congratulations! " << players[k].name << " is the winner!!" << endl;
                }
            }
        }
    }
}
