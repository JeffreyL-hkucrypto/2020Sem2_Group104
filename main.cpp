#include <iostream>
#include <string>
#include <vector>
#include "GameFunction.h"
#include "print.h"

using namespace std;

//Start the game with number of player returned,
void start_game(int np){
    gameloop(np);   //the function is included in GameFunction.cpp

    //After the game is finished, back to home screen
    for (int x = 0; x < 100; x++){
        if (x == 50)
            cout << "END";
        cout << "=";
    }
    cout << endl;
    cout << "Press ENTER back to Home Menu.";
    cin.get();
    print_home();
}

//When starting a new game, we need to know how many players in that game.
void new_player() {
    int np;
    cout << "Number of player?(2-4): ";
    cin >> np;
    //Need to be between 2 to 4 players.
    while (np != 2 && np != 3 && np != 4) {
        cout << "Invalid input, please try again." << endl;
        cout << "Number of player?(2-4): ";
        cin >> np;
    }
    GetPlayer(np);  //the function is included in GameFunction.cpp
    start_game(np);
}

//When the user select load save to continue, a file name is needed to input.
void inputfile() {
    string f;
    cout << "Select a save file to continue" << endl
         << "Please be noted that the file should be .txt text file "
         << "and in the same directory with your game" << endl
         << "Example: type in \"Save1\""
         << "File name: ";
    cin >> f;
    int np = returning(f);
    //If the system failed to open the file, user would be told to input again.
    while(np == 0){
        cout << "Could not access this directory, please try again." << endl;
        pause();
        cout << "Select a save file to continue" << endl
             << "Please be noted that the file should be .txt text file "
             << "and in the same directory with your game" << endl
             << "Example: type in \"Save1.txt\"" << endl
             << "File name: ";
        cin >> f;
    }
    //Start the game after the file data
    start_game(np);
}

//Home menu react to different instruction given.
void home_menu(){
    char cond;
    cin >> cond;
    while (cond != 'N' && cond != 'C' && cond != 'Q'){
        cout << "Invalid input, please try again." << endl;
        cin >> cond;
    }
    switch(cond) {
        case 'N' : new_player(); break;
        case 'C' : inputfile(); break;
        case 'Q' : cout << "Okay. See you later, have a nice day." << endl; break;
        default : break;
    }
}

int main() {
    print_home();
    home_menu();
    return 0;
}
