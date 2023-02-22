#include "Player.cpp"
#include <iostream>
#include <iomanip>
using namespace std;



int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<Player> players;
    getDataFromFile(filename,players);

    printHeader();
    cout << players[0] << endl;



    return 0;
};



