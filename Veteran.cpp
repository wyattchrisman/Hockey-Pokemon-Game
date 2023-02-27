//
// Created by Wyatt Chrisman on 2/23/23.
//

#include "Veteran.h"
using namespace std;

Veteran::Veteran() : Player(){
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

Veteran::Veteran(int rank, string name, int born, string position, int gamesPlayed, int goals,
                     int assists, int points, int penalty, double fightStat, double shotStat, double passStat) :
        Player(rank, name, born, position, gamesPlayed,goals, assists, points, penalty,
               fightStat*1.075, shotStat*1.075,
               passStat*1.075){
}

string Veteran::playerSaying() {
    string catchPhrase;
    int i = rand()%10;
    if(0 <= i < 3) {
        catchPhrase = "I've been in this league longer than you've been alive!";
    }
    if(3 <= i < 6) {
        catchPhrase = "I may be old, but don't take me lightly!";
    } else {
        catchPhrase = "Let's see what you got, young-gun!";
    }

    return catchPhrase;
}

string Veteran::getPlayerType() {
    return "Veteran";
}