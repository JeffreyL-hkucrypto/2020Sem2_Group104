#include<iostream>
#include<string>
#include<vector>
using namespace std;
class player{
  public:
  string status;
  int money;
  int steps;
  int position;
};
vector <player> players;

void GetPlayer(int i){
  for (int j=0;j<i;j++){
    player i ;
    i.status="playing"
    i.money=2000;
    i.steps=0;
    i.position=0;
    players.push_back(i);
}
  
void checklosing(int num_player ){
   for (int j=0;j<num_player;j++){
     if (players[j].moeny<=0){
       players[j].status="bankrupt";
       num_player--;
     }
    return num_player;
}
  
void OnStartPoint(int pos , int pla){
  cout<<"player"<<pla+1<<"you have got <<"2000"<<"by passing through the start point"<<endl;
  players[pla].money+=2000;
}

void OnLand
  
  
void CheckEvent(int pos , int pla){
    cout<<"player"<<pla+1<<"you are at"<<board[pos]<<" now" <<endl;

  if (pos==0){
    OnStartPotint(pos,pla);
  }
  elif (pos == 2 || pos == 17 || pos == 33){
    OnCommunityChest(pos,pla);
  }
  elif (pos == 7 || pos == 22 || pos == 36){
    Onchange(pos,pla);
  }
  elif (pos == 20){
    OnFreeparking(pos,pla);
  }
  elif (pos == 30){
    Onjail(pos,pla);
  }
  elif ( ){
  }
  elif ( ){
    
  else {
    Onland(pos,pla);
  }
void gameloop(int i){
  string fake_dice;
  int real_dice;
  int num_player;
  while (true){
    for (int j=0;j<i;j++){
      if (players[j].status!="bankrupt"){
        cout <<"player"<<j+1<<"please enter a number to roll a dice" << endl;
        cin >> fake_dice ;
        srand(time(NULL));
        real_dice = rand()%12+1;
        cout<<real_dice<<"steps forward"<<endl;
        players[j].steps+=real_dice;
        players[j].position = players[j].steps%40;
        CheckEvent(players[j].position,j);
        num_player=checklosing(num_player);
     }
     esle{
       cout<<"player"<<j+1<<"went bankrupt"<<endl;
     }
  }
  
  
  
