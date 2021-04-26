#include "print.h"
#include <iostream>

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
    for (int row = 0; row < 11; row++){
        for (int col = 0;col < 11; col++){
            cout << sq[row][col] << " ";
        }
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
