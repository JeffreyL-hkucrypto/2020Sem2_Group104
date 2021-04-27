#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "GameFunction.h"


using namespace std;

map<string, int> pla_in_jail;

//To check the owner of the land
int check_owned(int num){     
    for (int i = 0; i < players.size(); i++){
        for (int j = 0; j < players[i].owned.size(); j++) {
            if (players[i].owned[j] == num)
                return i;
        }
    }
}

//Pause the program to let the players more easy to read the important messages.
//When paused, type in "q" to generate quit prompt.
void pause(){
    cout << "Press ENTER to continue. ";
    char r;
    cin.get(r);
    if (r == 'q'){
        cout << "Do you want to quit? (y/n): ";
        cin >> r;
        while (r != 'y' && r != 'n'){
            cout << "Please try again." << endl << "Do you want to quit? (y/n): ";
            cin >> r;
        }
        if (r == 'y'){
            cout << "Do you need to save? (y/n): ";
            cin >> r;
            while (r != 'y' && r != 'n'){
                cout << "Please try again." << endl << "Do you want to save? (y/n): ";
                cin >> r;
            }
            if (r == 'y') {
                save_file();
            }
            else {
                cout << "Okay." << endl << "Press ENTER to continue.";
                cin.get();
            }
        }
    }
}

//To save the file if the player need to quit with save
void save_file(){
    time_t timer;
    string name, time;
    name = "Save";
    time = to_string(timer);
    name = name + time;
    ofstream fout;
    fout.open(name);
    fout << players.size() << endl;
    for (int np = 0; np < players.size(); np++){
        fout << players[np].name << " " << players[np].status << " " << players[np].icon << " "
             << players[np].money << " " << players[np].position << " " << players[np].doubled_counter;
        for (int ownlan = 0; ownlan < players[np].owned.size(); ownlan++){
            fout << " " << players[np].owned[ownlan];
        }
        fout << endl;
    }
    fout.close();
    cout << "File saved" << endl;
}

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

//Checking the money information of the player and change the player status inorder to determine the winner
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

//To handle the event when players land on start point
void OnStartPoint(player pla) {
    cout << "You have got M$2000 by passing through the start point" << endl;
    pause();
    pla.money += 2000;
}

//To handle the event when players land on freeparking point
void OnFreeparking(player pla) {
    cout << pla.name << "just visited the car park." << endl;
    pause();
}

//To handle the event when players land on "tax" point
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

//To handle the event when players land on "tax" point
void OnSuperTax(player pla){
    cout << "You have to pay M$1000." << endl;
    pause();
    pla.money -= 1000;
}

//To handle the event when players land on "jail" point
void OnJail(player pla) {
    cout << pla.name << " just visited the jail." << endl;
    pause();
}

//To handle the event when players land on "GO TO JAIL" point
void OnGotoJail(player pla) {
    cout << "GO TO JAIL!!!!!" << endl;
    Jail(pla);
    pause();
}

//To handle the event when players land on "CommunityChest" point
void OnCommunityChest(player pla){
    srand (time(NULL));
    int ran = rand() % 10;
    if (ran == 0){
        cout << pla.name << " has found M$2000 in the chest." << endl;
        pla.money += 2000;
        pause();
    }
    else {
        cout << pla.name << " opened the chest, but nothing has found." << endl;
        pause();
    }
}

//To handle the event when players land on "Chance" point
void OnChance(player pla){
    srand(time(NULL));
    int ran = rand() % 5;
    if (ran == 0){
        char ans;
        cout << "Is ENGG1340 fun? (y/n): ";
        cin >> ans;
        if (ans == 'y'){
            cout << pla.name << " has said \'ENGG1340 is fun!\' for 3 times." << endl;
            pause();
            cout << "Suddenly, some money is falling from the sky." << endl;
            pla.money += 500;
            cout << "Your balance is M$" << pla.money;
            pause();
        }
        else {
            cout << "A secret noise says, \'Your answer is wrong.\'" << endl;
            cout << "He has token away M$500 from your account." << endl;
            pause();
            pla.money -= 500;
            cout << "Your account remains M$" << pla.money;
            pause();
        }
    }
    else {
        cout << "Nothing happened." << endl;
        pause();
    }
}

//To handle the event when players land on lands
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

//To determine the event that happens when players make a move
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

//Print all the information of the game board
void game_board(player pla){
    char line[40];
    for (int i = 0; i < 40; i++) {
        line[i] = 'X';
    }
    for (int np = 0; np < players.size(); np++){
        line[players[np].position] = players[np].icon;
    }
    Land curr_land = board[pla.position];
    char sq[11][11];
    int temp;
    for (int row = 0; row < 11; row++){
        for (int col = 0; col < 11; col++){
            sq[row][col] = ' ';
        }
    }
    //Convert linear array to 2D array to print.
    for (int i = 0; i < 40; i++){
        if (i < 10){
            sq[0][i] = line[i];
        }
        else if (i >= 10 && i < 20){
            sq[i - 10][10] = line[i];
        }
        else if (i >= 20 && i < 30){
            temp = i - 20;
            sq[10][10 - temp] = line[i];
        }
        else {
            temp = i - 30;
            sq[10 - temp][0] = line[i];
        }
    }
    temp = 0;
    //Also print the square the player is now stepping at
    for (int row = 0; row < 11; row++){
        for (int col = 0;col < 11; col++){
            cout << sq[row][col] << " ";
        }
        if (row == 0 || row == 5)
            cout << setw(10) << "===========================================" << endl;
        else if (row == 1)
            cout << setw(10) << curr_land.name << endl;
        else if (row == 2)
            cout << setw(10) << "Status: " << curr_land.status << endl;
        else if (row == 3)
            cout << setw(10) << "Selling Price: " << curr_land.cost << endl;
        else if (row == 4)
            cout << setw(10) << "Rent: " << curr_land.rent << endl;
        else if (temp < players.size()){
            cout << players[temp].name << ": M$" << players[temp].money << endl;
            temp++;
        }
        else
            cout << endl;
    }
}

//To control the game flow
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


