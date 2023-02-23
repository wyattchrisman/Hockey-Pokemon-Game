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

    // These numbers are divided by a value that will allow the top players to have about a score of 80
    fightStat = (penalty/4950)*veteranStatMultiplier;
    shotStat = (goals/11.1)*veteranStatMultiplier;
    passStat = (assists/2240)*veteranStatMultiplier;
}

Veteran::Veteran(int rank, string name, int born, string position, int gamesPlayed, int goals,
                     int assists, int points, int penalty, double fightStat, double shotStat, double passStat) :
        Player(rank, name, born, position, gamesPlayed,goals, assists,
               points, penalty, fightStat, shotStat, passStat){
}

string Veteran::playerSaying() {
    string catchPhrase;
    int i;
    if(0 >= i >= 2) {
        catchPhrase = "";
    }
    if(3 >= i >= 5) {
        catchPhrase = "";
    } else {
        catchPhrase = "Veteran";
    }



    return catchPhrase;
}