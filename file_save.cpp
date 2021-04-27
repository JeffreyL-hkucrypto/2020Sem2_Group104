#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "file_save.h"
#include "GameFunction.h"

using namespace std;

void save_file(){
    time_t timer;
    string name, time;
    name = "Save";
    time = to_string(timer);
    name = name + time;
    ofstream fout;
    fout.open(name);
    fout << players.size() << endl;
    for (int np = 0; np < players.size(); np++){
        fout << players[np].name << " " << players[np].status << " " << players[np].icon << " "
        << players[np].money << " " << players[np].position << " " << players[np].doubled_counter;
        for (int ownlan = 0; ownlan < players[np].owned.size(); ownlan++){
            fout << " " << players[np].owned[ownlan];
        }
        fout << endl;
    }
    fout.close();
    cout << "File saved" << endl;
}
