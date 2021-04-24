#include "printbox.h"
#include <iostream>

using namespace std;

void change_sq_print(char line[], char sq[][10]){
    int temp;
    for (int row = 0; row < 10; row++){
        for (int col = 0; col < 10; col++){
            sq[row][col] = ' ';
        }
    }
    for (int i = 0; i < 40; i++){
        if (i < 10){
            sq[0][i] = line[i];
        }
        else if (i >= 10 && i < 19){
            sq[i - 9][9] = line[i];
        }
        else if (i >= 19 && i < 29){
            temp = i - 19;
            sq[9][9 - temp] = line[i];
        }
        else {
            temp = i - 29;
            sq[9 - temp][0] = line[i];
        }
    }
    for (int row = 0; row < 10; row++){
        for (int col = 0;col < 10; col++){
            cout << sq[row][col] << " ";
        }
        cout << endl;
    }
}
