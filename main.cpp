#include "Player.cpp"
#include "Normal.cpp"
#include "Sniper.cpp"
#include "Fighter.cpp"
#include "Playmaker.cpp"
#include "Veteran.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

void getDataFromFile(string filename, vector<unique_ptr<Player>>& players);
void printHeader();
void getPlayerAmounts(vector<unique_ptr<Player>>& players);
void getPlayerStats(unique_ptr<Player> &player, double &fightStat, double &shotStat, double &passStat);
void getPlayer(vector<unique_ptr<Player>> &players, unique_ptr<Player> &newPlayer, unique_ptr<Player> &discardPlayer);

int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<unique_ptr<Player>> players;

    getDataFromFile(filename,players);

    unique_ptr<Player> newPlayer, discardPlayer;

    srand(time(NULL));

    printHeader();
    for(int i = 0; i < 1000; ++i){
        getPlayer(players, newPlayer, discardPlayer);
        cout << i << ": " << newPlayer << endl;
    }




//    cout << "\nUSED\n" << endl;
//    printHeader();
//    for(int i = 0; i < usedPlayers.size(); ++i){
//        cout << usedPlayers[i] << endl;
//    }


    return 0;
};

// Add all players to vector from file
void getDataFromFile(string filename, vector<unique_ptr<Player>>& players) {
    //open file
    ifstream inFile;
    inFile.open(filename);

    //get header
    string header;
    if(inFile){
        //Read in the header for each category
        getline(inFile, header);
        //cout << header << endl;
    } else {
        cout << "File could not be opened." << endl;
    }

    //set variables to recognizable values
    int rank = -1, born = -1, gamesPlayed = -1, goals = -1,
        assists = -1,points = -1, penalty = -1;

    double fightStat = -1, shotStat = -1, passStat = -1;

    string name = "XXX XXX", position = "XXX XXX";
    char comma;

    //loop to validate that file continues while printing player data
    while(inFile && inFile.peek() != EOF) {
        //assign player rank and print
        inFile >> rank;
        inFile >> comma;

        getline(inFile, name, ',');
        //cout << name << endl;

        inFile >> born;
        //cout << born << endl;
        inFile >> comma;

        getline(inFile, position, ',');

        inFile >> gamesPlayed;
        inFile >> comma;

        inFile >> goals;
        inFile >> comma;

        inFile >> assists;
        inFile >> comma;

        inFile >> points;
        //cout << points << endl;
        inFile >> comma;

        inFile >> penalty;

        fightStat = penalty/49.5;
        shotStat = goals/11.1;
        passStat = assists/22.40;

        bool setType = false;
        if(goals >= 356) {
            players.push_back(make_unique<Sniper>(rank, name, born, position, gamesPlayed, goals,
                                                  assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(assists >= 409 && !setType) {
            players.push_back(make_unique<Playmaker>(rank, name, born, position, gamesPlayed, goals,
                                                     assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(penalty >= 798 && !setType){
            players.push_back(make_unique<Fighter>(rank, name, born, position, gamesPlayed, goals,
                                                   assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(gamesPlayed >= 700 && !setType){
            players.push_back(make_unique<Veteran>(rank, name, born, position, gamesPlayed, goals,
                                                   assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(!setType){
            players.push_back(make_unique<Normal>(rank, name, born, position, gamesPlayed, goals,
                                                  assists, points, penalty, fightStat, shotStat, passStat));

        }


    }
    inFile.close();
}

// For user comprehension of player stats
void printHeader() {

    cout << left << setw(25) << "NAME" << setw(6) << "RANK" << setw(11) <<
         "YEAR BORN" << setw(10) << "POSITION" << setw(14) << "GAMES PLAYED" <<
         setw(8) << "GOALS" << setw(9) << "ASSISTS" << setw(8) << "POINTS"
         << setw(15) << "PENALTY MINUTES" << endl;
    cout << setfill(' ');
}

// For sake of balancing out the number of each category
void getPlayerAmounts(vector<unique_ptr<Player>>& players) {
    int vet = 0, snip = 0, fight = 0, play = 0, normal = 0;
    for(int i = 0; i < players.size(); ++i){
        if(players[i]->playerSaying() == "Normal"){
            ++normal;
        }
        if(players[i]->playerSaying() == "Veteran"){
            ++vet;
        }
        if(players[i]->playerSaying() == "Sniper"){
            ++snip;
        }
        if(players[i]->playerSaying() == "Fighter"){
            ++fight;
        }
        if(players[i]->playerSaying() == "Playmaker"){
            ++play;
        }
    }

    cout << "Normal: " << normal << endl;
    cout << "Veteran: " << vet << endl;
    cout << "Sniper: " << snip << endl;
    cout << "Fighter: " << fight << endl;
    cout << "Playmaker: " << play << endl;
}

void getPlayerStats(unique_ptr<Player> &player, double &fightStat, double &shotStat, double &passStat){
    cout << "Player name: " << player->getName() << endl;
    cout << "Player type: " << player->getPlayerType() << endl;

    fightStat = player->getFightStat();
    cout << "Fighter Stat: " << fightStat << endl;

    shotStat = player->getShotStat();
    cout << "Shot Stat: " << shotStat << endl;

    passStat = player->getPassStat();
    cout << "Pass Stat: " << passStat << endl;
    cout << endl;
}

void getPlayer(vector<unique_ptr<Player>>& players, unique_ptr<Player> &newPlayer, unique_ptr<Player> &discardPlayer){


    int randNum = rand()%players.size();

    if (players[randNum]->getPlayerType() == "Normal") {
        unique_ptr<Player> discardPlayer = make_unique<Normal>(players[randNum]->getRank(),
                                                               players[randNum]->getName(),
                                                               players[randNum]->getBorn(),
                                                               players[randNum]->getPosition(),
                                                               players[randNum]->getGamesPlayed(),
                                                               players[randNum]->getGoals(),
                                                               players[randNum]->getAssists(),
                                                               players[randNum]->getPoints(),
                                                               players[randNum]->getPenalty(),
                                                               players[randNum]->getFightStat(),
                                                               players[randNum]->getShotStat(),
                                                               players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();

    }
    if (players[randNum]->getPlayerType() == "Sniper") {
        unique_ptr<Player> discardPlayer = make_unique<Sniper>(players[randNum]->getRank(),
                                                               players[randNum]->getName(),
                                                               players[randNum]->getBorn(),
                                                               players[randNum]->getPosition(),
                                                               players[randNum]->getGamesPlayed(),
                                                               players[randNum]->getGoals(),
                                                               players[randNum]->getAssists(),
                                                               players[randNum]->getPoints(),
                                                               players[randNum]->getPenalty(),
                                                               players[randNum]->getFightStat(),
                                                               players[randNum]->getShotStat(),
                                                               players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }
    if (players[randNum]->getPlayerType() == "Fighter") {
        unique_ptr<Player> discardPlayer = make_unique<Fighter>(players[randNum]->getRank(),
                                                                players[randNum]->getName(),
                                                                players[randNum]->getBorn(),
                                                                players[randNum]->getPosition(),
                                                                players[randNum]->getGamesPlayed(),
                                                                players[randNum]->getGoals(),
                                                                players[randNum]->getAssists(),
                                                                players[randNum]->getPoints(),
                                                                players[randNum]->getPenalty(),
                                                                players[randNum]->getFightStat(),
                                                                players[randNum]->getShotStat(),
                                                                players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }
    if (players[randNum]->getPlayerType() == "Playmaker") {
        unique_ptr<Player> discardPlayer = make_unique<Playmaker>(players[randNum]->getRank(),
                                                                  players[randNum]->getName(),
                                                                  players[randNum]->getBorn(),
                                                                  players[randNum]->getPosition(),
                                                                  players[randNum]->getGamesPlayed(),
                                                                  players[randNum]->getGoals(),
                                                                  players[randNum]->getAssists(),
                                                                  players[randNum]->getPoints(),
                                                                  players[randNum]->getPenalty(),
                                                                  players[randNum]->getFightStat(),
                                                                  players[randNum]->getShotStat(),
                                                                  players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }
    if (players[randNum]->getPlayerType() == "Veteran") {
        unique_ptr<Player> discardPlayer = make_unique<Veteran>(players[randNum]->getRank(),
                                                                players[randNum]->getName(),
                                                                players[randNum]->getBorn(),
                                                                players[randNum]->getPosition(),
                                                                players[randNum]->getGamesPlayed(),
                                                                players[randNum]->getGoals(),
                                                                players[randNum]->getAssists(),
                                                                players[randNum]->getPoints(),
                                                                players[randNum]->getPenalty(),
                                                                players[randNum]->getFightStat(),
                                                                players[randNum]->getShotStat(),
                                                                players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }

}
