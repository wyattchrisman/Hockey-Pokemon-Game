#include "Player.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

vector<Player> setPlayerTypes(vector<Player> players);

int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<Player> players;
    getDataFromFile(filename,players);

    vector<Player> playerTypes = setPlayerTypes(players);



    return 0;
};


vector<Player> setPlayerTypes(vector<Player> players){
    vector<Player> newPlayers;
    bool setType;

    for(int i = 0; i < players.size(); ++i){
        setType = false;
        if(players[i].getGoals() >= 310){

        }
    }


}
