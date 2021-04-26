#include "main.h"
#include <iomanip>


using namespace std;

void pause(){
    cout << "Press ENTER to continue.";
    cin.get();
}

void game_board(player pla){
    char line[40];
    for (int i = 0; i < 40; i++) {
        line[i] = 'X';
    }
    for (int np = 0; np < players.size(); np++){
        line[players[np].position] = players[np].icon;
    }
    Land curr_land = board[pla.position];
    char sq[11][11];
    int temp;
    for (int row = 0; row < 11; row++){
        for (int col = 0; col < 11; col++){
            sq[row][col] = ' ';
        }
    }
    for (int i = 0; i < 40; i++){
        if (i < 10){
            sq[0][i] = line[i];
        }
        else if (i >= 10 && i < 20){
            sq[i - 10][10] = line[i];
        }
        else if (i >= 20 && i < 30){
            temp = i - 20;
            sq[10][10 - temp] = line[i];
        }
        else {
            temp = i - 30;
            sq[10 - temp][0] = line[i];
        }
    }
    temp = 0;
    for (int row = 0; row < 11; row++){
        for (int col = 0;col < 11; col++){
            cout << sq[row][col] << " ";
        }
        if (row == 0 || row == 5)
            cout << setw(10) << "===========================================" << endl;
        else if (row == 1)
            cout << setw(10) << curr_land.name << endl;
        else if (row == 2)
            cout << setw(10) << "Status: " << curr_land.status << endl;
        else if (row == 3)
            cout << setw(10) << "Selling Price: " << curr_land.cost << endl;
        else if (row == 4)
            cout << setw(10) << "Rent: " << curr_land.rent << endl;
        else if (temp < players.size()){
            cout << players[temp].name << ": M$" << players[temp].money << endl;
            temp++;
        }
        else
            cout << endl;
    }
}

void print_home(){
    cout << "   ***  ***     ******     **    **     ******     *******      ******     **         **    **" << endl;
    cout << "   ********    **    **    ***   **    **    **    **    **    **    **    **          **  **" << endl;
    cout << "   ** ** **   **      **   ** ** **   **      **   *******    **      **   **           ****" << endl;
    cout << "   **    **    **    **    **   ***    **    **    **          **    **    **            **" << endl;
    cout << "   **    **     ******     **    **     ******     **           ******     ********      **" << endl;
    cout << "Welcome to the home screen of Monopoly!!" << endl;
    cout << "Type in \"N\" to start a new game." << endl;
    cout << "Type in \"C\" to continue with save file." << endl;
    cout << "Type in \"Q\" to quit." << endl;
}

