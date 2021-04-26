#ifndef INC_2020SEM2_GROUP104_MAIN_H
#define INC_2020SEM2_GROUP104_MAIN_H
#include <iostream>
#include <vector>
#include <map>

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
std::vector<player> players;
void pause();
void game_board(player pla);
void print_home();
void GetPlayer(int i);
void gameloop(int i);
class Land{
public:
    std::string name;
    std::string status;
    int land_id;
    int cost;
    int rent;
};
std::vector<Land> board;
void make_board();
std::map<std::string, int> pla_in_jail;
void Jail(player a);
void jail_break(player a);
#endif //INC_2020SEM2_GROUP104_MAIN_H
