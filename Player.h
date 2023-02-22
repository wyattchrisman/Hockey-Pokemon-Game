/**
 * Wyatt Chrisman
 * CS124
 * Section B
 */

#ifndef PROJECT1_PLAYER_H
#define PROJECT1_PLAYER_H

//add all inclusions
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using std::cout, std::endl, std::ifstream, std::string, std::vector;
using namespace std;

//create class
class Player {

    //Create all variables to be filled
protected:
    int rank; //players rank out of 1000 for points
    string name; //players name
    int born; //year player was born
    string position; //players position (forward or defense)
    int gamesPlayed; //number of games played in career
    int goals; //number of goals scored in career
    int assists; //number of assists in career
    int points; //number of points in career
    int penalty; //number of penatly minutes in career


public:
    /**
     * Requires: nothing
     * Modifies: rank, name, born, position, gamesPlayed, goals, assists, points, penalty
     * Effects: sets all player qualities to impossible values
     */
    Player();

    /**
     * Requires: all player qualities
     * Modifies: all player qualities
     * Effects: sets all player qualities to input values
     */
    explicit Player(int rank, string name, int born, string position, int gamesPlayed,
           int goals, int assists, int points, int penalty);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's rank
     */
    int getRank() const;


    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's name
     */
    string getName() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's birth year
     */
    int getBorn() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's position
     */
    string getPosition() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of games played
     */
    int getGamesPlayed() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of goals scored
     */
    int getGoals() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of assists
     */
    int getAssists() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of points
     */
    int getPoints() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of penalty minutes
     */
    int getPenalty() const;

    /**
     * Requires: rank
     * Modifies: rank
     * Effects: sets player's rank
     */
    void setRank(int rank);

    /**
     * Requires: name
     * Modifies: name
     * Effects: sets player's name
     */
    void setName(string name);

    /**
     * Requires: born
     * Modifies: born
     * Effects: sets player's year born
     */
    void setBorn(int born);

    /**
     * Requires: position
     * Modifies: position
     * Effects: sets player's position
     */
    void setPosition(string position);

    /**
     * Requires: gamesPlayed
     * Modifies: gamesPlayed
     * Effects: sets player's games played
     */
    void setGamesPlayed(int gamesPlayed);

    /**
     * Requires: goals
     * Modifies: goals
     * Effects: sets player's goals
     */
    void setGoals(int goals);

    /**
     * Requires: gamesPlayed
     * Modifies: gamesPlayed
     * Effects: sets player's assists
     */
    void setAssists(int assists);

    /**
     * Requires: points
     * Modifies: points
     * Effects: sets player's points
     */
    void setPoints(int points);

    /**
     * Requires: penalty
     * Modifies: penalty
     * Effects: sets player's penalty minutes
     */
    void setPenalty(int penalty);

    /**
     *
     * NEED FIXING
     *
     */
    friend ostream& operator << (ostream& outs, const Player& pla);

    friend bool operator < (const Player& lhs, const Player& rhs);

    friend bool operator > (const Player& lhs, const Player& rhs);

    friend bool operator <= (const Player& lhs, const Player& rhs);

    friend bool operator >= (const Player& lhs, const Player& rhs);

    friend bool operator == (const Player& lhs, const Player& rhs);

    friend bool operator != (const Player& lhs, const Player& rhs);

};

//open file that has player data and apply all data to a vector
void getDataFromFile(string filename, vector<Player>& players) {
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
            points = -1, penalty = -1;
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


        //Store info in a player object and add to vector
        players.push_back(Player(rank, name, born, position, gamesPlayed, goals,
                                 assists, points, penalty));
    }

    inFile.close();
}

//ability to get number of forwards in top 1000
int getNumForwards(string fileName, vector<Player> players) {
    ifstream inFile;
    inFile.open(fileName);
    int numForwards = 0;

    for(int i = 0; i < players.size(); ++i){
        if(players[i].getPosition() == "F"){
            ++numForwards;
        }
    }

    return numForwards;
}

//ability to get number of defenseman in top 1000
int getNumDefenseman(string fileName, vector<Player> players) {
    ifstream inFile;
    inFile.open(fileName);
    int numDefenseman = 0;

    for (int i = 0; i < players.size(); ++i) {
        if (players[i].getPosition() == "F") {
            ++numDefenseman;
        }
    }

    return numDefenseman;

}

void printHeader() {

    cout << left << setw(25) << "NAME" << setw(6) << "RANK" << setw(11) <<
         "YEAR BORN" << setw(10) << "POSITION" << setw(14) << "GAMES PLAYED" <<
         setw(8) << "GOALS" << setw(9) << "ASSISTS" << setw(8) << "POINTS"
         << setw(15) << "PENALTY MINUTES" << endl;
    cout << setfill(' ');




}
#endif