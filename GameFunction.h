#ifndef MONOPOLY_GAMEFUNCTION_H
#define MONOPOLY_GAMEFUNCTION_H
class player {
public:
    std::string status;
    std::string name;
    int money{};
    int steps{};
    int position{};
    int doubled_counter{};
    std::vector<int> owned;
};
std::vector<player> players;
void GetPlayer(int i);
int checklosing(int num_player);
void OnStartPoint(player pla);
void OnFreeparking(const player& pla);
void OnJail(const player& pla);
void OnGotoJail(player pla);
void OnLand(int pos, player pla);
void CheckEvent(player pla);
void gameloop(int i);
#endif //MONOPOLY_GAMEFUNCTION_H
