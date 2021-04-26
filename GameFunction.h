#ifndef MONOPOLY_GAMEFUNCTION_H
#define MONOPOLY_GAMEFUNCTION_H
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
void GetPlayer(int i);
bool returning(std::string file);
void gameloop(int i);
#endif //MONOPOLY_GAMEFUNCTION_H
