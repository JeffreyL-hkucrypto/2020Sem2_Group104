#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Land_Info{
  public:
         string status;
         int cost;
         int rent;
};
vector<string> board;
map<Land_info, int> Lands;
board.push_back("Start Point");
Land_info Start_Point;
Start_Point.status="SP";
Start_Point.cost=0;
Start_Point.rent=0;
Lands.status["Start Point"]=Start_Point;
board.push_back("Tin Shui Wai");
Land_info Tin_Shui_Wai;
Start_Point.status="available";
Start_Point.cost=0;
Start_Point.rent=0;
Lands.status["Start Point"]=Start_Point;
board.push_back("Community Chest");
board.push_back("Cheung Chau");
board.push_back("Income Tax");
board.push_back("Tung Chung Station");
board.push_back("Ap Lei Chau");
board.push_back("Change");
board.push_back("Kwun Tong");
board.push_back("Lam Tin");
board.push_back("Just Visting");
board.push_back("Tuen Mun");
board.push_back("Hong Kong electric");
board.push_back("Yuen Long");
board.push_back("Tai Po");
board.push_back("Tsing Yi Station");
board.push_back("Tai Wai");
board.push_back("Community Chest");
board.push_back("Sha Tin");
board.push_back("Ma On Shan");
board.push_back("Free Parking");
board.push_back("Tseung Kwan O");
board.push_back("Chance");
board.push_back("Tsuen Wan");
board.push_back("Adberdeen");
board.push_back("Kowloon Tong Station");
board.push_back("Mong Kok");
board.push_back("Tsim Sha Tsui");
board.push_back("Water Works");
board.push_back("West Kowloon");
board.push_back("Go To Jail");
board.push_back("CauseWay Bay");
board.push_back("Wan Chai");
board.push_back("Community Chest");
board.push_back("Central");
board.push_back("Hong Kong Station");
board.push_back("Chance");
board.push_back("Pok Fu Lam");
board.push_back("Super Tax");
board.push_back("The Peak");

