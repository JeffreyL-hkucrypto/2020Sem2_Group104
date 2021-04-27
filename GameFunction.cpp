#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include "GameFunction.h"

using namespace std;

class player {
public:
    string status;
    string name;
    char icon;
    int money{};
    int position{};
    int doubled_counter{};
    vector<int> owned;
};
vector<player> players;

class Land{
public:
    string name;
    string status;
    int land_id;
    int cost;
    int rent;
};
vector<Land> board;

map<string, int> pla_in_jail;

void pause();
void save_file();
void gameloop(int i);

//To create the vector which contains the information of the positions on the board
void make_board () {

    Land StartPoint;
    StartPoint.name = "Start Point";
    StartPoint.status = "N/A";
    StartPoint.land_id = 0;
    StartPoint.cost = 0;
    StartPoint.rent = 0;
    board.push_back(StartPoint);

    Land Tin_Shui_Wai;
    Tin_Shui_Wai.name = "Tin_Shui_Wai";
    Tin_Shui_Wai.status = "available";
    Tin_Shui_Wai.land_id = 1;
    Tin_Shui_Wai.cost = 600;
    Tin_Shui_Wai.rent = 20;
    board.push_back(Tin_Shui_Wai);

    Land Community_Chest;
    Community_Chest.name = "Community Chest";
    Community_Chest.status = "N/A";
    Community_Chest.land_id = 0;
    Community_Chest.cost = 0;
    Community_Chest.rent = 0;
    board.push_back(Community_Chest);

    Land Cheung_Chau;
    Cheung_Chau.name = "Cheung Chau";
    Cheung_Chau.status = "available";
    Cheung_Chau.land_id = 2;
    Cheung_Chau.cost = 600;
    Cheung_Chau.rent = 40;
    board.push_back(Cheung_Chau);

    Land Income_Tax;
    Income_Tax.name = "Income Tax";
    Income_Tax.status = "N/A";
    Income_Tax.land_id = 0;
    Income_Tax.cost = 0;
    Income_Tax.rent = 0;
    board.push_back(Income_Tax);

    Land Tung_Chung_Sta;
    Tung_Chung_Sta.name = "Tung_Chung_Station";
    Tung_Chung_Sta.status = "available";
    Tung_Chung_Sta.land_id = 3;
    Tung_Chung_Sta.cost = 2000;
    Tung_Chung_Sta.rent = 200;
    board.push_back(Tung_Chung_Sta);

    Land Ap_Lei_Chau;
    Ap_Lei_Chau.name = "Ap_Lei_Chau";
    Ap_Lei_Chau.status = "available";
    Ap_Lei_Chau.land_id = 4;
    Ap_Lei_Chau.cost = 1000;
    Ap_Lei_Chau.rent = 60;
    board.push_back(Ap_Lei_Chau);

    Land Chance;
    Chance.name = "Chance";
    Chance.status = "N/A";
    Chance.land_id = 0;
    Chance.cost = 0;
    Chance.rent = 0;
    board.push_back(Chance);

    Land Kwun_Tong;
    Kwun_Tong.name = "Kwun Tong";
    Kwun_Tong.status = "available";
    Kwun_Tong.land_id = 5;
    Kwun_Tong.cost = 1000;
    Kwun_Tong.rent = 60;
    board.push_back(Kwun_Tong);

    Land Lam_Tin;
    Lam_Tin.name = "Lam Tin";
    Lam_Tin.status = "available";
    Lam_Tin.land_id = 6;
    Lam_Tin.cost = 1200;
    Lam_Tin.rent = 80;
    board.push_back(Lam_Tin);

    Land Just_Visting;
    Just_Visting.name = "Stanley Prison";
    Just_Visting.status = "N/A";
    Just_Visting.land_id = 0;
    Just_Visting.cost = 0;
    Just_Visting.rent = 0;
    board.push_back(Just_Visting);

    Land Tuen_Mun;
    Tuen_Mun.name = "Tuen Mun";
    Tuen_Mun.status = "available";
    Tuen_Mun.land_id = 7;
    Tuen_Mun.cost = 1400;
    Tuen_Mun.rent = 100;
    board.push_back(Tuen_Mun);

    Land HK_electric;
    HK_electric.name = "Hong Kong Electric";
    HK_electric.status = "available";
    HK_electric.land_id = 8;
    HK_electric.cost = 1500;
    HK_electric.rent = 150;
    board.push_back(HK_electric);

    Land Yuen_Long;
    Yuen_Long.name = "Yuen Long";
    Yuen_Long.status = "available";
    Yuen_Long.land_id = 9;
    Yuen_Long.cost = 1400;
    Yuen_Long.rent = 100;
    board.push_back(Yuen_Long);

    Land Tai_Po;
    Tai_Po.name = "Tai Po";
    Tai_Po.status = "available";
    Tai_Po.land_id = 10;
    Tai_Po.cost = 1600;
    Tai_Po.rent = 120;
    board.push_back(Tai_Po);

    Land Tsing_Yi_Sta;
    Tsing_Yi_Sta.name = "Tsing Yi Station";
    Tsing_Yi_Sta.status = "available";
    Tsing_Yi_Sta.land_id = 11;
    Tsing_Yi_Sta.cost = 2000;
    Tsing_Yi_Sta.rent = 200;
    board.push_back(Tsing_Yi_Sta);

    Land Tai_Wai;
    Tai_Wai.name = "Tai Wai";
    Tai_Wai.status = "available";
    Tai_Wai.land_id = 12;
    Tai_Wai.cost = 1800;
    Tai_Wai.rent = 140;
    board.push_back(Tai_Wai);

    board.push_back(Community_Chest);

    Land Sha_Tin;
    Sha_Tin.name = "Sha Tin";
    Sha_Tin.status = "available";
    Sha_Tin.land_id = 13;
    Sha_Tin.cost = 1800;
    Sha_Tin.rent = 140;
    board.push_back(Sha_Tin);

    Land Ma_On_Shan;
    Ma_On_Shan.name = "Ma On Shan";
    Ma_On_Shan.status = "available";
    Ma_On_Shan.land_id = 14;
    Ma_On_Shan.cost = 2000;
    Ma_On_Shan.rent = 160;
    board.push_back(Ma_On_Shan);

    Land Free_Parking;
    Free_Parking.name = "Free Parking";
    Free_Parking.status = "N/A";
    Free_Parking.land_id = 0;
    Free_Parking.cost = 0;
    Free_Parking.rent = 0;
    board.push_back(Free_Parking);

    Land Tseung_Kwan_O;
    Tseung_Kwan_O.name = "Tseung Kwan O";
    Tseung_Kwan_O.status = "available";
    Tseung_Kwan_O.land_id = 15;
    Tseung_Kwan_O.cost = 2200;
    Tseung_Kwan_O.rent = 180;
    board.push_back(Tseung_Kwan_O);

    board.push_back(Chance);

    Land Tsuen_Wan;
    Tsuen_Wan.name = "Tsuen Wan";
    Tsuen_Wan.status = "available";
    Tsuen_Wan.land_id = 16;
    Tsuen_Wan.cost = 2200;
    Tsuen_Wan.rent = 180;
    board.push_back(Tsuen_Wan);

    Land Aberdeen;
    Aberdeen.name = "Aberdeen";
    Aberdeen.status = "available";
    Aberdeen.land_id = 17;
    Aberdeen.cost = 2400;
    Aberdeen.rent = 200;
    board.push_back(Aberdeen);


    Land Kowloon_Tong_Sta;
    Kowloon_Tong_Sta.name = "Kowloon Tong Station";
    Kowloon_Tong_Sta.status = "available";
    Kowloon_Tong_Sta.land_id = 18;
    Kowloon_Tong_Sta.cost = 2000;
    Kowloon_Tong_Sta.rent = 200;
    board.push_back(Kowloon_Tong_Sta);

    Land Mong_Kok;
    Mong_Kok.name="Mong Kok";
    Mong_Kok.status = "available";
    Mong_Kok.land_id=19;
    Mong_Kok.cost = 2600;
    Mong_Kok.rent = 220;
    board.push_back(Mong_Kok);

    Land Tsim_Sha_Tsui;
    Tsim_Sha_Tsui.name = "Tsim Sha Tsui";
    Tsim_Sha_Tsui.status = "available";
    Tsim_Sha_Tsui.land_id=20;
    Tsim_Sha_Tsui.cost = 2600;
    Tsim_Sha_Tsui.rent = 220;
    board.push_back(Tsim_Sha_Tsui);

    Land Water_Works;
    Water_Works.name= "Water Works";
    Water_Works.status = "available";
    Water_Works.land_id=21;
    Water_Works.cost = 1500;
    Water_Works.rent = 150;
    board.push_back(Water_Works);

    Land West_Kowloon;
    West_Kowloon.name="West Kowloon";
    West_Kowloon.status = "available";
    West_Kowloon.land_id=22;
    West_Kowloon.cost = 2800;
    West_Kowloon.rent = 220;
    board.push_back(West_Kowloon);

    Land Go_To_Jail;
    Go_To_Jail.name="GO TO JAIL";
    Go_To_Jail.status = "N/A";
    Go_To_Jail.land_id=0;
    Go_To_Jail.cost = 0;
    Go_To_Jail.rent = 0;
    board.push_back(Go_To_Jail);

    Land CauseWay_Bay;
    CauseWay_Bay.name="Causeway Bay";
    CauseWay_Bay.status = "available";
    CauseWay_Bay.land_id=23;
    CauseWay_Bay.cost = 3000;
    CauseWay_Bay.rent = 260;
    board.push_back(CauseWay_Bay);

    Land Wan_Chai;
    Wan_Chai.name="Wan Chai";
    Wan_Chai.status = "available";
    Wan_Chai.land_id=24;
    Wan_Chai.cost = 3000;
    Wan_Chai.rent = 260;
    board.push_back(Wan_Chai);

    board.push_back(Community_Chest);

    Land Central;
    Central.name="Central";
    Central.status = "available";
    Central.land_id=25;
    Central.cost = 3200;
    Central.rent = 280;
    board.push_back(Central);

    Land Hong_Kong_Sta;
    Hong_Kong_Sta.name="Hong Kong Station";
    Hong_Kong_Sta.status = "available";
    Hong_Kong_Sta.land_id=26;
    Hong_Kong_Sta.cost = 2000;
    Hong_Kong_Sta.rent = 200;
    board.push_back(Hong_Kong_Sta);

    board.push_back(Chance);

    Land HKU;
    HKU.name="The University of Hong Kong";
    HKU.status = "available";
    HKU.land_id=27;
    HKU.cost = 3500;
    HKU.rent = 350;
    board.push_back(HKU);

    Land Super_Tax;
    Super_Tax.name = "Super Tax";
    Super_Tax.status = "N/A";
    Super_Tax.cost = 0;
    Super_Tax.rent = 0;
    board.push_back(Super_Tax);

    Land The_Peak;
    The_Peak.name="The Peak";
    The_Peak.status = "available";
    The_Peak.land_id=28;
    The_Peak.cost = 4000;
    The_Peak.rent = 500;
    board.push_back(The_Peak);

}

//To get the player information
int returning(string file) {
    ifstream fin;
    fin.open(file);
    if (fin.fail())
        return 0;
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
        cout << "Data has input successfully." << endl << "Press ENTER to continue.";
        cin.get();
        fin.close();
        return i;
    }
}

//To initiate the player information
void GetPlayer(int i) {
    for (int j = 0; j < i; j++) {
        cout << "Please enter your name: ";
        player val;
        cin >> val.name;
        val.status = "playing";
        cout << "Please enter your icon: ";
        cin >> val.icon;
        val.money = 15000;
        val.position = 0;
        val.doubled_counter = 0;
        players.push_back(val);
    }
}

//Start the game with number of player returned,
void start_game(int np){
    gameloop(np);   //the function is included in GameFunction.cpp

    //After the game is finished, back to home screen
    for (int x = 0; x < 100; x++){
        if (x == 50)
            cout << "END";
        cout << "=";
    }
    cout << endl;
    cout << "Press ENTER back to Home Menu.";
    cin.get();
    print_home();
}

//When starting a new game, we need to know how many players in that game.
void new_player() {
    int np;
    cout << "Number of player?(2-4): ";
    cin >> np;
    //Need to be between 2 to 4 players.
    while (np != 2 && np != 3 && np != 4) {
        cout << "Invalid input, please try again." << endl;
        cout << "Number of player?(2-4): ";
        cin >> np;
    }
    GetPlayer(np);  //the function is included in GameFunction.cpp
    start_game(np);
}

//When the user select load save to continue, a file name is needed to input.
void inputfile() {
    string f;
    cout << "Select a save file to continue" << endl
         << "Please be noted that the file should be .txt text file "
         << "and in the same directory with your game" << endl
         << "Example: type in \"Save1\""
         << "File name: ";
    cin >> f;
    int np = returning(f);
    //If the system failed to open the file, user would be told to input again.
    while(np == 0){
        cout << "Could not access this directory, please try again." << endl;
        pause();
        cout << "Select a save file to continue" << endl
             << "Please be noted that the file should be .txt text file "
             << "and in the same directory with your game" << endl
             << "Example: type in \"Save1.txt\"" << endl
             << "File name: ";
        cin >> f;
    }
    //Start the game after the file data
    start_game(np);
}

//Print the home screen
void print_home(){
    cout << "   ***  ***     ******     **    **     ******     *******      ******     **         **    **" << endl;
    cout << "   ********    **    **    ***   **    **    **    **    **    **    **    **          **  **" << endl;
    cout << "   ** ** **   **      **   ** ** **   **      **   *******    **      **   **           ****" << endl;
    cout << "   **    **    **    **    **   ***    **    **    **          **    **    **            **" << endl;
    cout << "   **    **     ******     **    **     ******     **           ******     ********      **" << endl;
    cout << "Welcome to the home screen of Monopoly!!" << endl;
    cout << "Type in \"N\" to start a new game." << endl;
    cout << "Type in \"C\" to continue with save file." << endl;
    cout << "Type in \"Q\" to quit." << endl;
    char cond;
    cin >> cond;
    while (cond != 'N' && cond != 'C' && cond != 'Q'){
        cout << "Invalid input, please try again." << endl;
        cin >> cond;
    }
    switch(cond) {
        case 'N' : new_player(); break;
        case 'C' : inputfile(); break;
        case 'Q' : cout << "Okay. See you later, have a nice day." << endl; break;
        default : break;
    }
}

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
                print_home();
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
    cout << pla.name << " just visited the car park." << endl;
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
    pla.position = 10;
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
                cout << "Your account remains: M$" << pla.money << endl << "Press ENTER to continue.";
                cin.get();
            }
            else {
                cout << "You don't have enough money to buy this property." << endl << "Press ENTER to continue.";
                cin.get();
            }
        }
    }
    else if (board[pos].status == "sold"){
        string owner = players[check_owned(board[pos].land_id)].name;
        cout << board[pos].name << " is owned by player: " << owner << endl;
        cout << pla.name << " have to play M$" << board[pos].rent << " to player: " << owner << " as rent." << endl;
        pause();
        pla.money -= board[pos].rent;
        players[check_owned(board[pos].land_id)].money += board[pos].rent;
        cout << "Your account remains: M$" << pla.money << endl << "Press ENTER to continue.";
        cin.get();
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
void game_board(player &pla){
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
            cout << curr_land.name << endl;
        else if (row == 2)
            cout << "Status: " << curr_land.status << endl;
        else if (row == 3)
            cout << "Selling Price: M$" << curr_land.cost << endl;
        else if (row == 4)
            cout << "Rent: M$" << curr_land.rent << endl;
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
    int num_player = i;
    make_board();
    while (num_player > 1) {
        for (int j = 0; j < i; j++) {
            if (players[j].status != "bankrupt") {
                pause();
                game_board(players[j]);
                cout << players[j].name << " is playing." << endl;
                pause();
                if (pla_in_jail.count(players[j].name) > 0) {
                    jail_break(players[j]);
                }
                else {
                    srand(time(NULL));
                    real_dice1 = (rand() % 6) + 1;
                    real_dice2 = (rand() % 6) + 1;
                    cout << "You've rolled " << real_dice1 << " & " << real_dice2 << endl;
                    pause();
                    cout << real_dice1 + real_dice2 << " steps forward" << endl;
                    pause();
                    players[j].position += (real_dice1 + real_dice2);
                    if (players[j].position >= 41){
                        players[j].position = players[j].position % 41;
                        OnStartPoint(players[j]);
                    }
                    game_board(players[j]);
                    CheckEvent(players[j]);
                    num_player = checklosing(num_player);
                    if (real_dice1 == real_dice2) {
                        if (players[j].doubled_counter < 2) {
                            players[j].doubled_counter++;
                            j--;
                        }
                        else {
                            players[j].position = 10;
                            players[j].doubled_counter = 0;
                            OnGotoJail(players[j]);
                        }
                    }
                }
            }
            else {
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


