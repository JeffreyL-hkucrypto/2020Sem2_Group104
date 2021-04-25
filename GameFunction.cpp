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
    i.money=150000;
    i.steps=0;
    i.position=0;
    players.push_back(i);
}
  
void checklosing(int num_player ){
   for (int j=0;j<num_player;j++){
     if (players[j].moeny<=0){
       players[j].status="bankrupt";
       cout<<"player "<<j+1<<" went bankrupt"<<endl;
       num_player--;
     }
   }
    return num_player;
}
  
void OnStartPoint(int pla){
  cout<<"player"<<pla+1<<"you have got <<"2000"<<"by passing through the start point"<<endl;
  players[pla].money+=2000;
}
  
void OnFreeparking (int pla){
  cout << "Player" << pla + 1 << "just visit the car park." << endl;
}

void OnLand(int pos , int pla){
  sring ans;
  if (lands[(board[pos])].status="available"){
    cout<<"player"<<pla+1<<"would you pay<<lands[(board[pos])].cost<<"to buy"<<board[pos]<<"(y/n)"<<endl;
    while (ans!="y" && ans!="n" ){
      cout<<"Invalid input, please try again."<<endl;
      cout<<"player"<<pla+1<<"would you pay<<lands[(board[pos])].cost<<"to buy"<<board[pos]<<"(y/n)"<<endl;
      cin>>ans;
    }
    if (ans=="y"){
      if(players[pla].moeny>lands[(board[pos])].cost){
        players[pla].moeny-=lands[(board[pos])].cost;
        lands[(board[pos])].status=pla;
        cout<<"player"<<pla +1<<" own "<<board[pos]<<" now"<<endl;
        cout<<"player"<<pla +1<<"account remains: "<<players[pla].money<<endl;
      }
      else{
        cout<<"You don't have enough money to buy this property."<<endl;
      }
   }
   else{
     cout<<board[pos]<<"is owned by player:"<<lands[(board[pos])].status +1 <<endl;  //have to +1 before printing out the player number
     cout<<pla+1<<"have to play "<<lands[(board[pos])].rent<<" to player: "<<lands[(board[pos])].status +1<<" as rent "<<endl;
     players[pla].moeny-=lands[(board[pos])].rent;
     players[(lands[(board[pos])].status)].moeny+=lands[(board[pos])].rent;
     cout<<"player"<<pla +1<<"account remains: "<<players[pla].money<<endl;
     cout<<"player"<<(lands[(board[pos])].status) +1<<"account remains: "<<[players[(board[pos])].status)].money<<endl;
   }  
}
     
      
    
  
  
void CheckEvent(int pos , int pla){
  cout<<"player"<<pla+1<<"you are at"<<board[pos]<<" now" <<endl;

  if (pos==0){
    OnStartPotint(pla);
  }
  elif (pos == 2 || pos == 17 || pos == 33){
    OnCommunityChest(pla);
  }
  elif (pos == 7 || pos == 22 || pos == 36){
    Onchange(pla);
  }
  elif (pos == 20){
    OnFreeparking(pla);
  }
  elif (pos == 30){
    Onjail(pla);
  }
  elif ( ){
  }
  elif ( ){
    
  else {
    Onland(pos,pla);
  }
}
void gameloop(int i){
  string fake_dice;
  int real_dice1, real_dice2;
  int num_player;
  int flag;
  while (num_player > 1){
    for (int j=0; j<i; j++){
      if (players[j].status != "bankrupt"){
        cout << "player" << j+1 << "Please enter a number to roll a dice" << endl;
        cin >> fake_dice ;
        srand(time(NULL));
        real_dice1 = rand() % 6;
        real_dice2 = rand() % 6;
        cout << "You've rolled " << real_dice1 << " & " << real_dice2 << endl;
        cout << real_dice1 + real_dice2 << "steps forward" << endl;
        players[j].steps += real_dice;
        players[j].position = players[j].steps % 40;
        CheckEvent(players[j].position,j);
        num_player = checklosing(num_player);
      if (real_dice1 == real_dice2){
        j--;
      }
     }
     else{
       cout<< "player" << j+1 << "went bankrupt" << endl;
     }
  for (int k=0 ; k<i ; k++){
    if (players[k].status != "bankrupt"){
      cout << "player:" << k+1 <<" is the winner" << endl;
  }
}
  
  
