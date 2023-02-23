#include "Player.cpp"
#include "Normal.h"
#include "Sniper.h"
#include "Fighter.h"
#include "Playmaker.h"
#include <iostream>
#include <iomanip>
using namespace std;

void getDataFromFile(string filename, vector<unique_ptr<Player>>& players);
void printHeader();

int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<unique_ptr<Player>> players;
    getDataFromFile(filename,players);




    cout << players[0] << endl;


    return 0;
};

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
    int rank = -1, born = -1, gamesPlayed = -1, goals = -1, assists = -1,
            points = -1, penalty = -1, fightStat = 0, shotStat = 0, passStat = 0;
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



        bool setType = false;
        if(goals >= 310) {
            players.push_back(make_unique<Sniper>(rank, name, born, position, gamesPlayed, goals,
                                                  assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(assists >= 462 && !setType) {
            players.push_back(make_unique<Playmaker>(rank, name, born, position, gamesPlayed, goals,
                                                     assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(penalty >= 955 && !setType){
            players.push_back(make_unique<Fighter>(rank, name, born, position, gamesPlayed, goals,
                                                   assists, points, penalty, fightStat, shotStat, passStat));
        } else {
            players.push_back(make_unique<Normal>(rank, name, born, position, gamesPlayed, goals,
                                                  assists, points, penalty, fightStat, shotStat, passStat));
        }


    }
    inFile.close();
}

void printHeader() {

    cout << left << setw(25) << "NAME" << setw(6) << "RANK" << setw(11) <<
         "YEAR BORN" << setw(10) << "POSITION" << setw(14) << "GAMES PLAYED" <<
         setw(8) << "GOALS" << setw(9) << "ASSISTS" << setw(8) << "POINTS"
         << setw(15) << "PENALTY MINUTES" << endl;
    cout << setfill(' ');
}



