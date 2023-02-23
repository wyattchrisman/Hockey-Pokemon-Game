#include "Player.cpp"
#include "Normal.h"
#include "Sniper.h"
#include "Fighter.h"
#include "Playmaker.h"
#include <iostream>
#include <iomanip>
using namespace std;

void setPlayerTypes(vector<Player> players);

int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<Player> players;
    getDataFromFile(filename,players);

    vector<unique_ptr<Player>> playerTypes;

    setPlayerTypes(players, playerTypes);



    return 0;
};


void setPlayerTypes(vector<Player> players, vector<unique_ptr<Player>>& playerTypes){
    bool setType;

    for(int i = 0; i < players.size(); ++i){
        setType = false;
        if(players[i].getGoals() >= 310){
            playerTypes.push_back(make_unique<Sniper>(players[i].getRank(), players[i].getName(), players[i].getBorn(),
            players[i].getPosition(), players[i].getGamesPlayed(), players[i].getGoals(), players[i].getAssists(),
            players[i].getPoints(), players[i].getPenalty(), players[i].getFightStat(), players[i].getShotStat(), players[i].getPassStat()));
            setType = true;
        }
        if(players[i].getAssists() >= 462 && !setType){
            playerTypes.push_back(make_unique<Playmaker>(players[i].getRank(), players[i].getName(), players[i].getBorn(),
                                                     players[i].getPosition(), players[i].getGamesPlayed(), players[i].getGoals(), players[i].getAssists(),
                                                     players[i].getPoints(), players[i].getPenalty(), players[i].getFightStat(), players[i].getShotStat(), players[i].getPassStat()));
            setType = true;
        }
        if(players[i].getPenalty() >= 955 && !setType){
            playerTypes.push_back(make_unique<Fighter>(players[i].getRank(), players[i].getName(), players[i].getBorn(),
                                                     players[i].getPosition(), players[i].getGamesPlayed(), players[i].getGoals(), players[i].getAssists(),
                                                     players[i].getPoints(), players[i].getPenalty(), players[i].getFightStat(), players[i].getShotStat(), players[i].getPassStat()));
        } else {
            playerTypes.push_back(make_unique<Normal>(players[i].getRank(), players[i].getName(), players[i].getBorn(),
                                                       players[i].getPosition(), players[i].getGamesPlayed(), players[i].getGoals(), players[i].getAssists(),
                                                       players[i].getPoints(), players[i].getPenalty(), players[i].getFightStat(), players[i].getShotStat(), players[i].getPassStat()));
        }
    }
}
