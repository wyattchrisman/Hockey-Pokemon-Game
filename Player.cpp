//
// Created by Wyatt Chrisman on 2/21/23.
//

#include "Player.h"
#include "Normal.h"
#include <vector>

Player::Player() {
    //set all variables to something that would stand out in the data as not fitting
    rank = -1;
    name = "XXX XXX";
    born = -1;
    position = "XXX XXX";
    gamesPlayed = -1;
    goals = -1;
    assists = -1;
    points = -1;
    penalty = -1;
    fightStat = -1;
    shotStat = -1;
    passStat = -1;
}

Player::Player(int rank, string name, int born, string position, int gamesPlayed,int goals,
               int assists, int points, int penalty, int fightStat, int shotStat, int passStat) {

    this->rank = rank;
    this->name = name;
    this->born = born;
    this->position = position;
    this->gamesPlayed = gamesPlayed;
    this->goals = goals;
    this->assists = assists;
    this->points = points;
    this->penalty = penalty;
    this->fightStat = fightStat;
    this->shotStat = shotStat;
    this->passStat = passStat;
}

int Player::getRank() const {
    return rank;
}

string Player::getName() const{
return name;
}

int Player::getBorn() const {
    return born;
}

string Player::getPosition() const {
    return position;
}

int Player::getGamesPlayed() const {
    return gamesPlayed;
}

int Player::getGoals() const {
    return goals;
}

int Player::getAssists() const {
    return assists;
}

int Player::getPoints() const {
    return points;
}

int Player::getPenalty() const {
    return penalty;
}

int Player::getFightStat() const{
    return fightStat;
}

int Player::getShotStat() const{
    return shotStat;
}

int Player::getPassStat() const{
    return passStat;
}

void Player::setRank(int rank) {
    this->rank = rank;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::setBorn(int born) {
    this->born = born;
}

void Player::setPosition(string position) {
    this->position = position;
}

void Player::setGamesPlayed(int gamesPlayed) {
    this->gamesPlayed = gamesPlayed;
}

void Player::setGoals(int goals) {
    this->goals = goals;
}

void Player::setAssists(int assists) {
    this->assists = assists;
}

void Player::setPoints(int points) {
    this->points = points;
}

void Player::setPenalty(int penalty) {
    this->penalty = penalty;
}

void Player::setFightStat(int fightStat) {
    this->fightStat = fightStat;
}

void Player::setShotStat(int shotStat) {
    this->shotStat = shotStat;
}

void Player::setPassStat(int passStat) {
    this->passStat = passStat;
}



/**
     *
     * NEED FIXING
     *
     */
ostream& operator << (ostream& outs, const Player& pla){
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

bool operator < (const Player& lhs, const Player& rhs) {
    int result = lhs.getName().compare(rhs.getName());
    if(result < 0)
        return true;
    else
        return false;
}

bool operator > (const Player& lhs, const Player& rhs){
    int result = lhs.getName().compare(rhs.getName());
    if(result > 0)
        return true;
    else
        return false;
}

bool operator <= (const Player& lhs, const Player& rhs){
    int result = lhs.getName().compare(rhs.getName());
    if(result <= 0)
        return true;
    else
        return false;
}

bool operator >= (const Player& lhs, const Player& rhs){
    int result = lhs.getName().compare(rhs.getName());
    if(result >= 0)
        return true;
    else
        return false;
}

bool operator == (const Player& lhs, const Player& rhs){
    int result = lhs.getName().compare(rhs.getName());
    if(result == 0)
        return true;
    else
        return false;
}

bool operator != (const Player& lhs, const Player& rhs){
    int result = lhs.getName().compare(rhs.getName());
    if(result != 0)
        return true;
    else
        return false;
}

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


        //Store info in a player object and add to vector
        players.push_back(make_unique<Normal>(rank, name, born, position, gamesPlayed, goals,
                                 assists, points, penalty, fightStat, shotStat, passStat));


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
