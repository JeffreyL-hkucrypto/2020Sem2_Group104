#ifndef MAIN_CPP_GET_PLAYERS_H
#define MAIN_CPP_GET_PLAYERS_H
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
int returning(std::string file);
void GetPlayer(int i);
#endif //MAIN_CPP_GET_PLAYERS_H
