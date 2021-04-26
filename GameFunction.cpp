#include "main.h"
#include <fstream>

using namespace std;

int check_owned(int num){
    for (int i = 0; i < players.size(); i++){
        for (int j = 0; j < players[i].owned.size(); j++) {
            if (players[i].owned[j] == num)
                return i;
        }
    }
}

bool returning(string file) {
    ifstream fin;
    fin.open(file);
    if (fin.fail())
        return 1;
    else {
        int i;
        fin >> i;
        for (int j = 0; j < i; j++) {
            player f;
            fin >> f.name;
            fin >> f.status;
            fin >> f.icon;
            fin >> f.money;
            fin >> f.position;
            fin >> f.doubled_counter;
            players.push_back(f);
        }
        cout << "Data has input successfully." << endl;
        pause();
    }
}

void GetPlayer(int i) {
    for (int j = 0; j < i; j++) {
        cout << "Please enter your name: ";
        player val;
        cin >> val.name;
        val.status = "playing";
        val.icon = 'Z';
        val.money = 150000;
        val.position = 0;
        val.doubled_counter = 0;
        players.push_back(val);
    }
}

int checklosing(int num_player) {
    for (int j = 0; j < num_player; j++) {
        if (players[j].money <= 0) {
            players[j].status = "bankrupt";
            cout << players[j].name << " went bankrupt." << endl;
            pause();
            num_player--;
        }
    }
    return num_player;
}

void OnStartPoint(player pla) {
    cout << "You have got M$2000 by passing through the start point" << endl;
    pause();
    pla.money += 2000;
}

void OnFreeparking(player pla) {
    cout << pla.name << "just visited the car park." << endl;
    pause();
}

void OnTax(player pla){
    char ans;
    cout << "You have to pay either a. [10% of money] or b.[M$2000]" << endl;
    cout << "You have M$" << pla.money << " now." << endl;
    cout << "Which one you would choose? (a/b): ";
    cin >> ans;
    while (ans != 'a' && ans != 'b'){
        cout << "Invalid input, please try again." << endl;
        cout << "You have to pay either a. [10% of money] or b.[M$2000]" << endl;
        cout << "Which one you would choose? (a/b): ";
        cin >> ans;
    }
    if (ans == 'a')
        pla.money = pla.money * 0.9;
    else
        pla.money -= 2000;
    cout << "Your account remains: M$" << pla.money;
    pause();
}

void OnSuperTax(player pla){
    cout << "You have to pay M$1000." << endl;
    pause();
    pla.money -= 1000;
}

void OnJail(player pla) {
    cout << pla.name << " just visited the jail." << endl;
    pause();
}

void OnGotoJail(player pla) {
    cout << "GO TO JAIL!!!!!" << endl;
    Jail(pla);
    pause();
}

void OnCommunityChest(player pla){
    cout << "nothing happened yet." << endl;
    pause();
}

void OnChance(player pla){
    cout << "nothing happened yet." << endl;
    pause();
}

void OnLand(int pos, player pla) {
    char ans;
    if (board[pos].status == "available") {
        cout << pla.name << ", would you pay M$" << board[pos].cost << " to buy " << board[pos].name << "? (y/n)"
             << endl;
        cin >> ans;
        while (ans != 'y' && ans != 'n') {
            cout << "Invalid input, please try again." << endl;
            cout << pla.name << ", would you pay M$" << board[pos].cost << " to buy " << board[pos].name << "? (y/n) ";
            cin >> ans;
        }
        if (ans == 'y') {
            if (pla.money > board[pos].cost) {
                pla.money -= board[pos].cost;
                board[pos].status = "sold";
                pla.owned.push_back(board[pos].land_id);
                cout << "You own " << board[pos].name << " now" << endl;
                cout << "Your account remains: M$" << pla.money << endl;
                pause();
            }
            else {
                cout << "You don't have enough money to buy this property." << endl;
                pause();
            }
        }
    }
    else if (board[pos].status == "sold"){
            string owner = players[check_owned(board[pos].land_id)].name;
            cout << board[pos].name << " is owned by player: " << owner << endl;
            cout << pla.name << "have to play M$" << board[pos].rent << " to player: " << owner << " as rent." << endl;
            pause();
            pla.money -= board[pos].rent;
            players[check_owned(board[pos].land_id)].money += board[pos].rent;
            cout << "Your account remains: M$" << pla.money << endl;
            pause();
        }
    }

void CheckEvent(player pla) {
    int pos = pla.position;
    cout << pla.name << ", you are at " << board[pos].name << " now." << endl;

    if (pos == 0) {
        OnStartPoint(pla);
    }
    else if (pos == 2 || pos == 17 || pos == 33) {
        OnCommunityChest(pla);
    }
    else if (pos == 7 || pos == 22 || pos == 36) {
        OnChance(pla);
    }
    else if (pos == 20) {
        OnFreeparking(pla);
    }
    else if (pos == 30) {
        OnGotoJail(pla);
    }
    else if (pos == 10) {
        OnJail(pla);
    }
    else if (pos == 4) {
        OnTax(pla);
    }
    else if (pos == 39){
        OnSuperTax(pla);
    }
    else {
        OnLand(pos, pla);
    }
}

void gameloop(int i) {
    string fake_dice;
    int real_dice1, real_dice2;
    int num_player;
    make_board();
    while (num_player > 1) {
        for (int j = 0; j < i; j++) {
            if (players[j].status != "bankrupt") {
                if (pla_in_jail.count(players[j].name) > 0) {
                    jail_break(players[j]);
                }
                else {
                    game_board(players[j]);
                    cout << players[j].name << "is playing." << endl;
                    cout << players[j].name << "Please enter a number to roll a dice" << endl;
                    cin >> fake_dice;
                    srand(time(NULL));
                    real_dice1 = (rand() % 6) + 1;
                    real_dice2 = (rand() % 6) + 1;
                    cout << "You've rolled " << real_dice1 << " & " << real_dice2 << endl
                         << "Press ENTER to continue." << endl;
                    cin.get();
                    cout << real_dice1 + real_dice2 << "steps forward" << endl;
                    pause();
                    players[j].position += (real_dice1 + real_dice2);
                    if (players[j].position >= 41){
                        players[j].position = players[j].position % 41;
                        OnStartPoint(players[j]);
                    }
                    CheckEvent(players[j]);
                    num_player = checklosing(num_player);
                    if (real_dice1 == real_dice2) {
                        if (players[j].doubled_counter < 2) {
                            players[j].doubled_counter++;
                            j--;
                        } else {
                            players[j].position = 10;
                            players[j].doubled_counter = 0;
                            OnGotoJail(players[j]);
                        }
                    }
                }
            } else {
                cout << players[j].name << "went bankrupt" << endl;
                pause();
            }
        }
    }
    for (int k = 0; k < i; k++) {
        if (players[k].status != "bankrupt") {
            cout << "Congratulations! " << players[k].name << " is the winner!!" << endl;
            pause();
        }
    }
}


