#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "get_players.h"

using namespace std;

class player {
public:
    std::string status;
    std::string name;
    char icon;
    int money{};
    int position{};
    int doubled_counter{};
    std::vector<int> owned;
};

vector<player> players;

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
        val.money = 150000;
        val.position = 0;
        val.doubled_counter = 0;
        players.push_back(val);
    }
}