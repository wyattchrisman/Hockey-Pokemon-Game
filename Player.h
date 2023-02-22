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
private:
    int rank; //players rank out of 1000 for points
    string name; //players name
    int born; //year player was born
    string position; //players position (forward or defense)
    int gamesPlayed; //number of games played in career
    int goals; //number of goals scored in career
    int assists; //number of assists in career
    int points; //number of points in career
    string penalty; //number of penatly minutes in career


public:
    // Create Constructors
    Player() {
        //set all variables to something that would stand out in the data as not fitting
        rank = -1;
        name = "XXX XXX";
        born = -1;
        position = "XXX XXX";
        gamesPlayed = -1;
        goals = -1;
        assists = -1;
        points = -1;
        penalty = "XXX XXX";
    }

    // constructor that takes in all players attributes
    Player(int rank, string name, int born, string position, int gamesPlayed,
           int goals, int assists, int points, string penalty) {

        this->rank = rank;
        this->name = name;
        this->born = born;
        this->position = position;
        this->gamesPlayed = gamesPlayed;
        this->goals = goals;
        this->assists = assists;
        this->points = points;
        this->penalty = penalty;
    }

    // Create all getters
    int getRank() const {
        return rank;
    }

    string getName() const {
        return name;
    }

    int getBorn() const {
        return born;
    }

    string getPosition() const {
        return position;
    }

    int getGamesPlayed() const {
        return gamesPlayed;
    }

    int getGoals() const {
        return goals;
    }

    int getAssists() const {
        return assists;
    }

    int getPoints() const {
        return points;
    }

    string getPenalty() const {
        return penalty;
    }

    // Create all setters
    void setRank(int rank) {
        this->rank = rank;
    }

    void setName(string name) {
        this->name = name;
    }

    void setBorn(int born) {
        this->born = born;
    }

    void setPosition(string position) {
        this->position = position;
    }

    void setGamesPlayed(int gamesPlayed) {
        this->gamesPlayed = gamesPlayed;
    }

    void setGoals(int goals) {
        this->goals = goals;
    }

    void setAssists(int assists) {
        this->assists = assists;
    }

    void setPoints(int points) {
        this->points = points;
    }

    void setPenalty(string penalty) {
        this->penalty = penalty;
    }

    // Overload the stream operator for comprehensive printing
    friend ostream& operator << (ostream& outs, const Player& pla){
        outs << left << setw(23) << pla.getName();
        outs << right << setw(5) << pla.getRank();
        outs << setw(9) << pla.getBorn();
        outs << setw(10) << pla.getPosition();
        outs << setw(14) << pla.getGamesPlayed();
        outs << setw(9) << pla.getGoals();
        outs << setw(9) << pla.getAssists();
        outs << setw(9) << pla.getPoints();
        outs << setw(13) << pla.getPenalty();

        return outs;
    }

    // Overload operators for object comparison
    friend bool operator < (const Player& lhs, const Player& rhs) {
        int result = lhs.getName().compare(rhs.getName());
        if(result < 0)
            return true;
        else
            return false;
    }

    friend bool operator > (const Player& lhs, const Player& rhs){
        int result = lhs.getName().compare(rhs.getName());
        if(result > 0)
            return true;
        else
            return false;
    }

    friend bool operator <= (const Player& lhs, const Player& rhs){
        int result = lhs.getName().compare(rhs.getName());
        if(result <= 0)
            return true;
        else
            return false;
    }

    friend bool operator >= (const Player& lhs, const Player& rhs){
        int result = lhs.getName().compare(rhs.getName());
        if(result >= 0)
            return true;
        else
            return false;
    }

    friend bool operator == (const Player& lhs, const Player& rhs){
        int result = lhs.getName().compare(rhs.getName());
        if(result == 0)
            return true;
        else
            return false;
    }

    friend bool operator != (const Player& lhs, const Player& rhs){
        int result = lhs.getName().compare(rhs.getName());
        if(result != 0)
            return true;
        else
            return false;
    }



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
            points = -1;
    string name = "XXX XXX", position = "XXX XXX", penalty = "XXX XXX";
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

        getline(inFile, penalty);


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