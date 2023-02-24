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
void getPlayerStats(vector<unique_ptr<Player>> &players, int index, double &fightStat, double &shotStat, double &passStat);
void getPlayerIndex(vector<unique_ptr<Player>> &players, vector<unique_ptr<Player>> &usedPlayers, unique_ptr<Player> &newPlayer);

int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<unique_ptr<Player>> players;

    getDataFromFile(filename,players);

    vector<unique_ptr<Player>> usedPlayers;



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

void getPlayerStats(vector<unique_ptr<Player>>& players, int index, double &fightStat, double &shotStat, double &passStat){
    cout << "Player name: " << players[index]->getName() << endl;
    cout << "Player type: " << players[index]->playerSaying() << endl;

    fightStat = players[index]->getFightStat();
    cout << "Fighter Stat: " << fightStat << endl;

    shotStat = players[index]->getShotStat();
    cout << "Shot Stat: " << shotStat << endl;

    passStat = players[index]->getPassStat();
    cout << "Pass Stat: " << passStat << endl;
    cout << endl;
}

void getPlayerIndex(vector<unique_ptr<Player>>& players, vector<unique_ptr<Player>>& usedPlayers, unique_ptr<Player> &newPlayer){
    srand(time(NULL));

    newPlayer = players[rand()%1000];
    usedPlayers.push_back(newPlayer);

}