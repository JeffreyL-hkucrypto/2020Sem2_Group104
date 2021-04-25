#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "board_information.h"

using namespace std;

void make_board () {

    Land StartPoint;
    StartPoint.name = "Start Point";
    StartPoint.status = "N/A";
    StartPoint.land_id = 0;
    StartPoint.cost = 0;
    StartPoint.rent = 0;
    board.push_back(StartPoint);

    Land Tin_Shui_Wai;
    Tin_Shui_Wai.name = "Tin_Shui_Wai";
    Tin_Shui_Wai.status = "available";
    Tin_Shui_Wai.land_id = 1;
    Tin_Shui_Wai.cost = 600;
    Tin_Shui_Wai.rent = 20;
    board.push_back(Tin_Shui_Wai);

    Land Community_Chest;
    Community_Chest.name = "Community Chest";
    Community_Chest.status = "N/A";
    Community_Chest.land_id = 0;
    Community_Chest.cost = 0;
    Community_Chest.rent = 0;
    board.push_back(Community_Chest);

    Land Cheung_Chau;
    Cheung_Chau.name = "Cheung Chau";
    Cheung_Chau.status = "available";
    Cheung_Chau.land_id = 2;
    Cheung_Chau.cost = 600;
    Cheung_Chau.rent = 40;
    board.push_back(Cheung_Chau);

    Land Income_Tax;
    Income_Tax.name = "Income Tax";
    Income_Tax.status = "N/A";
    Income_Tax.land_id = 0;
    Income_Tax.cost = 0;
    Income_Tax.rent = 0;
    board.push_back(Income_Tax);

    Land Tung_Chung_Sta;
    Tung_Chung_Sta.name = "Tung_Chung_Station";
    Tung_Chung_Sta.status = "available";
    Tung_Chung_Sta.land_id = 3;
    Tung_Chung_Sta.cost = 2000;
    Tung_Chung_Sta.rent = 200;
    board.push_back(Tung_Chung_Sta);

    Land Ap_Lei_Chau;
    Ap_Lei_Chau.name = "Ap_Lei_Chau";
    Ap_Lei_Chau.status = "available";
    Ap_Lei_Chau.land_id = 4;
    Ap_Lei_Chau.cost = 1000;
    Ap_Lei_Chau.rent = 60;
    board.push_back(Ap_Lei_Chau);

    Land Chance;
    Chance.name = "Chance";
    Chance.status = "N/A";
    Chance.land_id = 0;
    Chance.cost = 0;
    Chance.rent = 0;
    board.push_back(Chance);

    Land Kwun_Tong;
    Kwun_Tong.name = "Kwun Tong";
    Kwun_Tong.status = "available";
    Kwun_Tong.land_id = 5;
    Kwun_Tong.cost = 1000;
    Kwun_Tong.rent = 60;
    board.push_back(Kwun_Tong);

    Land Lam_Tin;
    Lam_Tin.name = "Lam Tin";
    Lam_Tin.status = "available";
    Lam_Tin.land_id = 6;
    Lam_Tin.cost = 1200;
    Lam_Tin.rent = 80;
    board.push_back(Lam_Tin);

    Land Just_Visting;
    Just_Visting.name = "Stanley Prison";
    Just_Visting.status = "N/A";
    Just_Visting.land_id = 0;
    Just_Visting.cost = 0;
    Just_Visting.rent = 0;
    board.push_back(Just_Visting);

    Land Tuen_Mun;
    Tuen_Mun.name = "Tuen Mun";
    Tuen_Mun.status = "available";
    Tuen_Mun.land_id = 7;
    Tuen_Mun.cost = 1400;
    Tuen_Mun.rent = 100;
    board.push_back(Tuen_Mun);

    Land HK_electric;
    HK_electric.name = "Hong Kong Electric";
    HK_electric.status = "available";
    HK_electric.land_id = 8;
    HK_electric.cost = 1500;
    HK_electric.rent = 150;
    board.push_back(HK_electric);

    Land Yuen_Long;
    Yuen_Long.name = "Yuen Long";
    Yuen_Long.status = "available";
    Yuen_Long.land_id = 9;
    Yuen_Long.cost = 1400;
    Yuen_Long.rent = 100;
    board.push_back(Yuen_Long);

    Land Tai_Po;
    Tai_Po.name = "Tai Po";
    Tai_Po.status = "available";
    Tai_Po.land_id = 10;
    Tai_Po.cost = 1600;
    Tai_Po.rent = 120;
    board.push_back(Tai_Po);

    Land Tsing_Yi_Sta;
    Tsing_Yi_Sta.name = "Tsing Yi Station";
    Tsing_Yi_Sta.status = "available";
    Tsing_Yi_Sta.land_id = 11;
    Tsing_Yi_Sta.cost = 2000;
    Tsing_Yi_Sta.rent = 200;
    board.push_back(Tsing_Yi_Sta);

    Land Tai_Wai;
    Tai_Wai.name = "Tai Wai";
    Tai_Wai.status = "available";
    Tai_Wai.land_id = 12;
    Tai_Wai.cost = 1800;
    Tai_Wai.rent = 140;
    board.push_back(Tai_Wai);

    board.push_back(Community_Chest);

    Land Sha_Tin;
    Sha_Tin.name = "Sha Tin";
    Sha_Tin.status = "available";
    Sha_Tin.land_id = 13;
    Sha_Tin.cost = 1800;
    Sha_Tin.rent = 140;
    board.push_back(Sha_Tin);

    Land Ma_On_Shan;
    Ma_On_Shan.name = "Ma On Shan";
    Ma_On_Shan.status = "available";
    Ma_On_Shan.land_id = 14;
    Ma_On_Shan.cost = 2000;
    Ma_On_Shan.rent = 160;
    board.push_back(Ma_On_Shan);

    Land Free_Parking;
    Free_Parking.name = "Free Parking";
    Free_Parking.status = "N/A";
    Free_Parking.land_id = 0;
    Free_Parking.cost = 0;
    Free_Parking.rent = 0;
    board.push_back(Free_Parking);

    Land Tseung_Kwan_O;
    Tseung_Kwan_O.name = "Tseung Kwan O";
    Tseung_Kwan_O.status = "available";
    Tseung_Kwan_O.land_id = 15;
    Tseung_Kwan_O.cost = 2200;
    Tseung_Kwan_O.rent = 180;
    board.push_back(Tseung_Kwan_O);

    board.push_back(Chance);

    Land Tsuen_Wan;
    Tsuen_Wan.name = "Tsuen Wan";
    Tsuen_Wan.status = "available";
    Tsuen_Wan.land_id = 16;
    Tsuen_Wan.cost = 2200;
    Tsuen_Wan.rent = 180;
    board.push_back(Tsuen_Wan);

    Land Aberdeen;
    Aberdeen.name = "Aberdeen";
    Aberdeen.status = "available";
    Aberdeen.land_id = 17;
    Aberdeen.cost = 2400;
    Aberdeen.rent = 200;
    board.push_back(Aberdeen);


    Land Kowloon_Tong_Sta;
    Kowloon_Tong_Sta.name = "Kowloon Tong Station";
    Kowloon_Tong_Sta.status = "available";
    Kowloon_Tong_Sta.land_id = 18;
    Kowloon_Tong_Sta.cost = 2000;
    Kowloon_Tong_Sta.rent = 200;
    board.push_back(Kowloon_Tong_Sta);

    Land Mong_Kok;
    Mong_Kok.name="Mong Kok";
    Mong_Kok.status = "available";
    Mong_Kok.land_id=19;
    Mong_Kok.cost = 2600;
    Mong_Kok.rent = 220;
    board.push_back(Mong_Kok);

    Land Tsim_Sha_Tsui;
    Tsim_Sha_Tsui.name = "Tsim Sha Tsui";
    Tsim_Sha_Tsui.status = "available";
    Tsim_Sha_Tsui.land_id=20;
    Tsim_Sha_Tsui.cost = 2600;
    Tsim_Sha_Tsui.rent = 220;
    board.push_back(Tsim_Sha_Tsui);

    Land Water_Works;
    Water_Works.name= "Water Works";
    Water_Works.status = "available";
    Water_Works.land_id=21;
    Water_Works.cost = 1500;
    Water_Works.rent = 150;
    board.push_back(Water_Works);

    Land West_Kowloon;
    West_Kowloon.name="West Kowloon";
    West_Kowloon.status = "available";
    West_Kowloon.land_id=22;
    West_Kowloon.cost = 2800;
    West_Kowloon.rent = 220;
    board.push_back(West_Kowloon);

    Land Go_To_Jail;
    Go_To_Jail.name="GO TO JAIL";
    Go_To_Jail.status = "N/A";
    Go_To_Jail.land_id=0;
    Go_To_Jail.cost = 0;
    Go_To_Jail.rent = 0;
    board.push_back(Go_To_Jail);

    Land CauseWay_Bay;
    CauseWay_Bay.name="Causeway Bay";
    CauseWay_Bay.status = "available";
    CauseWay_Bay.land_id=23;
    CauseWay_Bay.cost = 3000;
    CauseWay_Bay.rent = 260;
    board.push_back(CauseWay_Bay);

    Land Wan_Chai;
    Wan_Chai.name="Wan Chai";
    Wan_Chai.status = "available";
    Wan_Chai.land_id=24;
    Wan_Chai.cost = 3000;
    Wan_Chai.rent = 260;
    board.push_back(Wan_Chai);

    board.push_back(Community_Chest);

    Land Central;
    Central.name="Central";
    Central.status = "available";
    Central.land_id=25;
    Central.cost = 3200;
    Central.rent = 280;
    board.push_back(Central);

    Land Hong_Kong_Sta;
    Hong_Kong_Sta.name="Hong Kong Station";
    Hong_Kong_Sta.status = "available";
    Hong_Kong_Sta.land_id=26;
    Hong_Kong_Sta.cost = 2000;
    Hong_Kong_Sta.rent = 200;
    board.push_back(Hong_Kong_Sta);

    board.push_back(Chance);

    Land HKU;
    HKU.name="The University of Hong Kong";
    HKU.status = "available";
    HKU.land_id=27;
    HKU.cost = 3500;
    HKU.rent = 350;
    board.push_back(HKU);

    Land Super_Tax;
    Super_Tax.name = "Super Tax";
    Super_Tax.status = "N/A";
    Super_Tax.cost = 0;
    Super_Tax.rent = 0;
    board.push_back(Super_Tax);

    Land The_Peak;
    The_Peak.name="The Peak";
    The_Peak.status = "available";
    The_Peak.land_id=28;
    The_Peak.cost = 4000;
    The_Peak.rent = 500;
    board.push_back(The_Peak);

}