#include <iostream>
#include <iomanip>
#include <string>
#include "main.h"
#include "board_information.h"
#include "GameFunction.h"
#include "file_save.h"
#include "print.h"

using namespace std;

//Pause the program to let the players more easy to read the important messages.
//When paused, type in "q" to generate quit prompt.
void pause(){
    cout << "Press ENTER to continue. ";
    char r;
    cin.get(r);
    if (r == 'q'){
        cout << "Do you want to quit? (y/n): ";
        cin >> r;
        while (r != 'y' && r != 'n'){
            cout << "Please try again." << endl << "Do you want to quit? (y/n): ";
            cin >> r;
        }
        if (r == 'y'){
            cout << "Do you need to save? (y/n): ";
            cin >> r;
            while (r != 'y' && r != 'n'){
                cout << "Please try again." << endl << "Do you want to save? (y/n): ";
                cin >> r;
            }
            if (r == 'y')
                save_file();
            else {
                cout << "Okay." << endl << "Press ENTER to continue.";
                cin.get();
                print_home();
            }
        }
    }
}

//Print all the information of the game board
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
    //Convert linear array to 2D array to print.
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
    //Also print the square the player is now stepping at
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

//Print the home screen
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
    home_menu();
}

