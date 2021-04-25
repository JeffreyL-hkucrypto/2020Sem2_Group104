#ifndef INC_2020SEM2_GROUP104_BOARD_INFORMATION_H
#define INC_2020SEM2_GROUP104_BOARD_INFORMATION_H
#include <string>
#include <vector>
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
#endif //INC_2020SEM2_GROUP104_BOARD_INFORMATION_H
