#include<iostream>
#include<string>
#include<vector>
using namespace std;
class player{
  public:
  int money;
  int steps;
  int position;
};
vector <player> players;
void GetPlayer(int i){
  for (int j=0;j<i;j++){
    player i ;
    i.money=2000;
    i.steps=0;
    i.position=0;
    players.push_back(i);
}
  
void OnLand(){
  
  
