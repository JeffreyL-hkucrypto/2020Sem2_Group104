#ifndef MONOPOLY_GAMEFUNCTION_H
#define MONOPOLY_GAMEFUNCTION_H
#include <iostream>
#include <vector>

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
void GetPlayer(int i);
void gameloop(int i);
#endif //MONOPOLY_GAMEFUNCTION_H
