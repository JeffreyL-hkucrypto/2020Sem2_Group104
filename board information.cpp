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
Lands["Start Point"]=Start_Point;

board.push_back("Tin Shui Wai");
Land_info Tin_Shui_Wai;
Tin_Shui_Wai.status="available";
Tin_Shui_Wai.cost=0;
Tin_Shui_Wai.rent=0;
Lands["Tin Shui Wai"]=Tin_Shui_Wai ;

board.push_back("Community Chest");
Land_info Community_Chest;
Community_Chest.status="Community Chest";
Community_Chest.cost=0;
Community_Chest.rent=0;
Lands["Community Chest"]=Community_Chest ;

board.push_back("Cheung Chau");
Land_info Cheung_Chau;
Cheung Chau.status="available";
Cheung Chau.cost=0;
Cheung Chau.rent=0;
Lands["Cheung Chau"]=Cheung_Chau ;

board.push_back("Income Tax");
Land_info Income_Tax;
Income_Tax.status="Income Tax";
Income_Tax.cost=0;
Income_Tax.rent=0;             
Lands["Income Tax"]=Income_Tax ;            

board.push_back("Tung Chung Station");
Land_info Tung_Chung_Station;
Tung_Chung_Station.status="available";
Tung_Chung_Station.cost=0;
Tung_Chung_Station.rent=0;             
Lands["Tung Chung Station"]=Tung_Chung_Station ;

board.push_back("Ap Lei Chau");
Land_info Ap_Lei_Chau;
Ap_Lei_Chau.status="available";
Ap_Lei_Chau.cost=0;
Ap_Lei_Chau.rent=0;             
Lands["Ap Lei Chau"]=Ap_Lei_Chau;


board.push_back("Change");
Land_info Change_;
Change_.status="Change";
Change_.cost=0;
Change_.rent=0;  
Lands["Change"]=Change_;


board.push_back("Kwun Tong");
Land_info Kwun_Tong;
Kwun_Tong.status="available";
Kwun_Tong.cost=0;
Kwun_Tong.rent=0;             
Lands["Kwun Tong"]=Kwun_Tong;

board.push_back("Lam Tin");
Land_info Lam_Tin;
Lam_Tin.status="available";
Lam_Tin.cost=0;
Lam_Tin.rent=0;             
Lands["Lam Tin"]=Lam_Tin;

board.push_back("Just Visting");
Land_info Just_Visting;
Just_Visting.status="Just Visting";
Just_Visting.cost=0;
Just_Visting.rent=0;             
Lands["Just Visting"]=Just_Visting;

board.push_back("Tuen Mun");
Land_info Tuen_Mun;
Tuen_Mun.status="available";
Tuen_Mun.cost=0;
Tuen_Mun.rent=0;             
Lands["Tuen Mun"]=Tuen_Mun;

board.push_back("Hong Kong electric");
Land_info Hong_Kong_electric;
Hong_Kong_electric.status="available";
Hong_Kong_electric.cost=0;
Hong_Kong_electric.rent=0;
Lands["Hong Kong electric"]=Hong_Kong_electric;


board.push_back("Yuen Long");
Yuen_Long.status="available";
Yuen_Long.cost=0;
Yuen_Long.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Tai Po");
Tai_Po.status="available";
Tai_Po.cost=0;
Tai_Po.rent=0;             
Lands["Tai Po"]=Tai_Po;

board.push_back("Tsing Yi Station");
Tsing_Yi_Station.status="available";
Tsing_Yi_Station.cost=0;
Tsing_Yi_Station.rent=0;             
Lands["Tsing Yi Station"]=Tsing_Yi_Station;

board.push_back("Tai Wai");
Tai_Wai.status="available";
Tai_Wai.cost=0;
Tai_Wai.rent=0;             
Lands["Tai Wai"]=Tai_Wai;

board.push_back("Community Chest");

board.push_back("Sha Tin");
Sha_Tin.status="available";
Sha_Tin.cost=0;
Sha_Tin.rent=0;             
Lands["Sha Tin"]=Sha_Tin;

board.push_back("Ma On Shan");
Ma_On_Shan.status="available";
Ma_On_Shan.cost=0;
Ma_On_Shan.rent=0;             
Lands["Ma On Shan"]=Ma_On_Shan;

board.push_back("Free Parking");
Free_Parking.status="Free Parking";
Free_Parking.cost=0;
Free_Parking.rent=0;             
Lands["Free Parking"]=Free_Parking;

board.push_back("Tseung Kwan O");
Tseung_Kwan_O.status="available";
Tseung_Kwan_O.cost=0;
Tseung_Kwan_O.rent=0;             
Lands["Tseung Kwan O"]=Tseung_Kwan_O;

board.push_back("Chance");


board.push_back("Tsuen Wan");
Tsuen_Wan.status="available";
Tsuen_Wan.cost=0;
Tsuen_Wan.rent=0;             
Lands["Tsuen Wan"]=Tsuen_Wan;

board.push_back("Adberdeen");
Adberdeen.status="available";
Adberdeen.cost=0;
Adberdeen.rent=0;             
Lands["Adberdeen"]=Adberdeen;

board.push_back("Kowloon Tong Station");
Kowloon_Tong.status="Kowloon Tong";
Kowloon_Tong.cost=0;
Kowloon_Tong.rent=0;             
Lands["Kowloon Tong"]=Kowloon_Tong;

board.push_back("Mong Kok");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Tsim Sha Tsui");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Water Works");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("West Kowloon");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Go To Jail");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("CauseWay Bay");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Wan Chai");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Community Chest");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Central");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Hong Kong Station");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("Chance");


board.push_back("Pok Fu Lam");
Pok_Fu_Lam.status="Pok Fu Lam";
Pok_Fu_Lam.cost=0;
Pok_Fu_Lam.rent=0;             
Lands["Pok Fu Lam"]=Pok_Fu_Lam;

board.push_back("Super Tax");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

board.push_back("The Peak");
Start_Point.status="Yuen Long";
Start_Point.cost=0;
Start_Point.rent=0;             
Lands["Yuen Long"]=Yuen_Long;

