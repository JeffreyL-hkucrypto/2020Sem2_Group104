#ifndef INC_2020SEM2_GROUP104_JAIL_H
#define INC_2020SEM2_GROUP104_JAIL_H
#include <map>
#include "GameFunction.h"

std::map<player, int> pla_in_jail;
void Jail(player a);
void search_for_prisoners();
bool check_in_jail();
void jail_break(player a);
#endif //INC_2020SEM2_GROUP104_JAIL_H
