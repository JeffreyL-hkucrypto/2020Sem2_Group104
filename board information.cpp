#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Land{
  public:
        string name;
        string status;
        int land_id;
        int cost;
        int rent;
};
void make_board (){
vector<Land> board;
map<Land, int> Lands;

Land StartPoint;
StartPoint.name = "Start Point";
StartPoint.status = "N/A";
StartPoint.land_id = 0;
StartPoint.cost=0;
StartPoint.rent=0;
board.push_back(StartPoint);

Land Tin_Shui_Wai;
Tin_Shui_Wai.name = "Tin_Shui_Wai";
Tin_Shui_Wai.status="available";
Tin_Shui_Wai.land_id = 1;
Tin_Shui_Wai.cost=0;
Tin_Shui_Wai.rent=0;
board.push_back(Tin_Shui_Wai);

Land Community_Chest;
Community_Chest.name="Community Chest";
Community_Chest.status="N/A";
Community_Chest.land_id = 0;
Community_Chest.cost=0;
Community_Chest.rent=0;
board.push_back(Community_Chest);

Land Cheung_Chau;
Cheung_Chau.name = "Cheung Chau";
Cheung_Chau.status="available";
Cheung_Chau.land_id = 2;
Cheung_Chau.cost=0;
Cheung_Chau.rent=0;
board.push_back(Cheung_Chau);

Land Income_Tax;
Income_Tax.name= "Income Tax";
Income_Tax.status="N/A";
Income_Tax.land_id=0;
Income_Tax.cost=0;
Income_Tax.rent=0;
board.push_back(Income_Tax);

Land Tung_Chung_Sta;
Tung_Chung_Sta.name="Tung_Chung_Station";
Tung_Chung_Sta.status="available";
Tung_Chung_Sta.land_id=3;
Tung_Chung_Sta.cost=0;
Tung_Chung_Sta.rent=0;
board.push_back(Tung_Chung_Sta);

Land Ap_Lei_Chau;
Ap_Lei_Chau.name="Ap_Lei_Chau";
Ap_Lei_Chau.status="available";
Ap_Lei_Chau.land_id=4;
Ap_Lei_Chau.cost=0;
Ap_Lei_Chau.rent=0;
board.push_back(Ap_Lei_Chau);

Land Chance;
Chance.name="Chance";
Chance.status="N/A";
Chance.land_id=0;
Chance.cost=0;
Chance.rent=0;
board.push_back(Chance);

Land Kwun_Tong;
Kwun_Tong.name="Kwun Tong";
Kwun_Tong.status="available";
    Kwun_Tong.land_id=5;
Kwun_Tong.cost=0;
Kwun_Tong.rent=0;
board.push_back(Kwun_Tong);

Land Lam_Tin;
Lam_Tin.name="Lam Tin";
Lam_Tin.status="available";
Lam_Tin.land_id=6;
Lam_Tin.cost=0;
Lam_Tin.rent=0;
    board.push_back(Lam_Tin);

Land Just_Visting;
Just_Visting.name="Stanley Prison";
Just_Visting.status="N/A";
Just_Visting.land_id=0;
Just_Visting.cost=0;
Just_Visting.rent=0;
    board.push_back(Just_Visting);

Land Tuen_Mun;
Tuen_Mun.name="Tuen Mun";
Tuen_Mun.status="available";
Tuen_Mun.land_id=7;
Tuen_Mun.cost=0;
Tuen_Mun.rent=0;
    board.push_back(Tuen_Mun);

Land HK_electric;
HK_electric.name = "Hong Kong Electric";
HK_electric.status="available";
HK_electric.land_id=8;
HK_electric.cost=0;
HK_electric.rent=0;
    board.push_back(HK_electric);

Land Yuen_Long;
Yuen_Long.name="Yuen Long";
Yuen_Long.status="available";
Yuen_Long.land_id=9;
Yuen_Long.cost=0;
Yuen_Long.rent=0;
    board.push_back(Yuen_Long);

Land Tai_Po;
Tai_Po.name="Tai Po";
Tai_Po.status="available";
Tai_Po.land_id=10;
Tai_Po.cost=0;
Tai_Po.rent=0;
    board.push_back(Tai_Po);

Land Tsing_Yi_Sta;
Tsing_Yi_Sta.name="Tsing Yi Station";
Tsing_Yi_Sta.status="available";
Tsing_Yi_Sta.land_id=11;
Tsing_Yi_Sta.cost=0;
Tsing_Yi_Sta.rent=0;
    board.push_back(Tsing_Yi_Sta);

Land Tai_Wai;
Tai_Wai.name="Tai Wai";
Tai_Wai.status="available";
Tai_Wai.land_id=12;
Tai_Wai.cost=0;
Tai_Wai.rent=0;
    board.push_back(Tai_Wai);

board.push_back("Community Chest");

board.push_back("Sha Tin");
Land Sha_Tin;
Sha_Tin.status="available";
Sha_Tin.cost=0;
Sha_Tin.rent=0;             
Lands["Sha Tin"]=Sha_Tin;

board.push_back("Ma On Shan");
Land Ma_On_Shan;
Ma_On_Shan.status="available";
Ma_On_Shan.cost=0;
Ma_On_Shan.rent=0;             
Lands["Ma On Shan"]=Ma_On_Shan;

board.push_back("Free Parking");
Land Free_Parking;
Free_Parking.status="Free Parking";
Free_Parking.cost=0;
Free_Parking.rent=0;             
Lands["Free Parking"]=Free_Parking;

board.push_back("Tseung Kwan O");
Land Tseung_Kwan_O;
Tseung_Kwan_O.status="available";
Tseung_Kwan_O.cost=0;
Tseung_Kwan_O.rent=0;             
Lands["Tseung Kwan O"]=Tseung_Kwan_O;

board.push_back("Chance");


board.push_back("Tsuen Wan");
Land Tsuen_Wan;
Tsuen_Wan.status="available";
Tsuen_Wan.cost=0;
Tsuen_Wan.rent=0;             
Lands["Tsuen Wan"]=Tsuen_Wan;

board.push_back("Adberdeen");
Land Adberdeen;
Adberdeen.status="available";
Adberdeen.cost=0;
Adberdeen.rent=0;             
Lands["Adberdeen"]=Adberdeen;

board.push_back("Kowloon Tong Station");
Land Kowloon_Tong_Station;
Kowloon_Tong_Station.status="Kowloon Tong Station";
Kowloon_Tong_Station.cost=0;
Kowloon_Tong_Station.rent=0;             
Lands["Kowloon Tong Station"]=Kowloon_Tong_Station;

board.push_back("Mong Kok");
Land Mong_Kok;
Mong_Kok.status="available";
Mong_Kok.cost=0;
Mong_Kok.rent=0;             
Lands["Mong Kok"]=Mong_Kok;

board.push_back("Tsim Sha Tsui");
Land Tsim_Sha_Tsui;
Tsim_Sha_Tsui.status="available";
Tsim_Sha_Tsui.cost=0;
Tsim_Sha_Tsui.rent=0;             
Lands["Tsim Sha Tsui"]=Tsim_Sha_Tsui;

board.push_back("Water Works");
Land Water_Works;
Water_Works.status="available";
Water_Works.cost=0;
Water_Works.rent=0;             
Lands["Water Works"]=Water_Works;

board.push_back("West Kowloon");
Land West_Kowloon;
West_Kowloon.status="available";
West_Kowloon.cost=0;
West_Kowloon.rent=0;             
Lands["West Kowloon"]=West_Kowloon;

board.push_back("Go To Jail");
Land Go_To_Jail;
Go_To_Jail.status="Jail";
Go_To_Jail.cost=0;
Go_To_Jail.rent=0;             
Lands["Go To Jail"]=Go_To_Jail;

board.push_back("CauseWay Bay");
Land CauseWay_Bay;
CauseWay_Bay.status="available";
CauseWay_Bay.cost=0;
CauseWay_Bay.rent=0;             
Lands["CauseWay Bay"]=CauseWay_Bay;

board.push_back("Wan Chai");
Land Wan_Chai;
Wan_Chai.status="available";
Wan_Chai.cost=0;
Wan_Chai.rent=0;             
Lands["Wan Chai"]=Wan_Chai;

board.push_back(Community_Chest);


board.push_back("Central");
Land Central;
Central.status="available";
Central.cost=0;
Central.rent=0;             
Lands["Central"]=Central;

board.push_back("Hong Kong Station");
Land Hong_Kong_Station;
Hong_Kong_Station.status="available";
Hong_Kong_Station.cost=0;
Hong_Kong_Station.rent=0;             
Lands["Hong Kong Station"]=Hong_Kong_Station;

board.push_back(Chance);


board.push_back("Pok Fu Lam");
Land Pok_Fu_Lam;
Pok_Fu_Lam.status="available";
Pok_Fu_Lam.cost=0;
Pok_Fu_Lam.rent=0;             
Lands["Pok Fu Lam"]=Pok_Fu_Lam;

board.push_back("Super Tax");
Land Super_Tax;
Super_Tax.status="Tax";
Super_Tax.cost=0;
Super_Tax.rent=0;             
Lands["Super Tax"]=Super_Tax;

board.push_back("The Peak");
Land The_Peak;
The_Peak.status="available";
The_Peak.cost=0;
The_Peak.rent=0;             
Lands["The Peak"]=The_Peak;

