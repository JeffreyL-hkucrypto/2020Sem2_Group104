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
  int doubled_counter;
};
vector <player> players;

void GetPlayer(int i){
  for (int j = 0; j < i; j++){
    player i ;
    i.status = "playing";
    i.money = 150000;
    i.steps = 0;
    i.position = 0;
    i.doubled_counter = 0;
    players.push_back(i);
}
  
void checklosing(int num_player ){
   for (int j=0;j<num_player;j++){
     if (players[j].moeny<=0){
       players[j].status="bankrupt";
       cout<<"player "<<j+1<<" went bankrupt"<<endl
         << "Press ENTER to continue.";
       cin.get();
       num_player--;
     }
   }
    return num_player;
}
  
void OnStartPoint(int pla){
  cout<<"Player "<<pla+1<<"you have got <<"2000"<<"by passing through the start point"<<endl
    << "Press ENTER to continue." << endl;
  cin.get();
  players[pla].money+=2000;
}
  
void OnFreeparking (int pla){
  cout << "Player " << pla + 1 << "just visited the car park." << endl
    << "Press ENTER to continue.";
  cin.get();
}
void OnJail (int pla){
  if (pla_in_jail.size() == 0){
    cout << "Player " << pla + 1 << "just visited the jail." << endl
      << "Press ENTER to continue.";
    cin.get();
  }
  else {
    int num = pla_in_jail.size();
    cout << "Player " << pla + 1 << "just paid a visit to ";
    for (int n = 0; n < num; n++){
      cout << pla_in_jail[n].player;
    }
    cout << "." << endl << "Press ENTER to continue.";
    cin.get();
  }
}
void OnGotoJail (int pla){
  Jail(pla);
}
  
void OnLand(int pos , int pla){
  sring ans;
  if (lands[(board[pos])].status="available"){
    cout<<"player"<<pla+1<<"would you pay<<lands[(board[pos])].cost<<"to buy"<<board[pos]<<"(y/n)"<<endl;
    cin >> ans;
    while (ans != 'y' && ans != 'n'){
      cout<<"Invalid input, please try again."<<endl;
      cout<<"player"<<pla+1<<"would you pay<<lands[(board[pos])].cost<<"to buy"<<board[pos]<<"(y/n)"<<endl;
      cin>>ans;
    }
    if (ans == 'y'){
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
    OnGotoJail(pla);
  }
  elif (pos == 10){
    OnJail(pla);
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
  while (num_player > 1){
    for (int j=0; j<i; j++){
      if (players[j].status != "bankrupt"){
        cout << "player" << j+1 << "Please enter a number to roll a dice" << endl;
        cin >> fake_dice ;
        srand(time(NULL));
        real_dice1 = rand() % 6;
        real_dice2 = rand() % 6;
        cout << "You've rolled " << real_dice1 << " & " << real_dice2 << endl
          << "Press ENTER to continue." << endl;
        cin.get();
        cout << real_dice1 + real_dice2 << "steps forward" << endl
          << "Press ENTER to continue.";
        cin.get();
        players[j].steps += (real_dice1 + real_dice2);
        players[j].position = players[j].steps % 40;
        CheckEvent(players[j].position,j);
        num_player = checklosing(num_player);
      if (real_dice1 == real_dice2){
        if (player[j].doubled_counter < 2){
          player[j].doubled_counter++;
          j--;
        }
        else {
          players[j].position = 9;
          players[j].steps = 9;
          player[j].doubled_counter = 0;
          OnGotoJail(players[j]);
        }
      }
     }
     else{
       cout<< "Player" << j+1 << "went bankrupt" << endl;
     }
  for (int k=0 ; k<i ; k++){
    if (players[k].status != "bankrupt"){
      cout << "Player:" << k+1 <<" is the winner" << endl;
  }
}
  
  
