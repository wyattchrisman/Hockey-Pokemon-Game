#include "Player.cpp"
#include "Normal.h"
#include "Sniper.h"
#include "Fighter.h"
#include "Playmaker.h"
#include <iostream>
#include <iomanip>
using namespace std;

void setPlayerTypes(vector<Player> players, vector<unique_ptr<Player>>& playerTypes);

int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<unique_ptr<Player>> players;
    getDataFromFile(filename,players);


    cout << players[0] << endl;






    return 0;
};



