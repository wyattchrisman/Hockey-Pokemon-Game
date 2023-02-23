//
// Created by Wyatt Chrisman on 2/21/23.
//


#include "Fighter.h"
using namespace std;

Fighter::Fighter() : Player(){
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
    fightStat = 0;
    shotStat = 0;
    passStat = 0;
}

Fighter::Fighter(int rank, string name, int born, string position, int gamesPlayed, int goals,
               int assists, int points, int penalty, int fightStat, int shotStat, int passStat) :
        Player(rank, name, born, position, gamesPlayed,goals, assists,
               points, penalty, fightStat, shotStat, passStat){
}

string Fighter::playerSaying() {
    string catchPhrase;
    int i;
    if(0 >= i >= 2) {
        catchPhrase = "";
    }
    if(3 >= i >= 5) {
        catchPhrase = "";
    } else {
        catchPhrase = "";
    }



    return catchPhrase;
}