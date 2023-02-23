//
// Created by Wyatt Chrisman on 2/21/23.
//

#include "Playmaker.h"
using namespace std;

Playmaker::Playmaker() : Player(){
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

Playmaker::Playmaker(int rank, string name, int born, string position, int gamesPlayed, int goals,
                 int assists, int points, int penalty, double fightStat, double shotStat, double passStat) :
        Player(rank, name, born, position, gamesPlayed,goals, assists,
               points, penalty, fightStat, shotStat, passStat*1.2){
}

string Playmaker::playerSaying() {
    string catchPhrase;
    int i;
    if(0 >= i >= 2) {
        catchPhrase = "";
    }
    if(3 >= i >= 5) {
        catchPhrase = "";
    } else {
        catchPhrase = "Playmaker";
    }



    return catchPhrase;
}