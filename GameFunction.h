#ifndef MONOPOLY_GAMEFUNCTION_H
#define MONOPOLY_GAMEFUNCTION_H
class player;
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
