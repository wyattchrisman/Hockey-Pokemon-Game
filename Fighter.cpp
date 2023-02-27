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

    fightStat = -1;
    shotStat = -1;
    passStat = -1;
}

Fighter::Fighter(int rank, string name, int born, string position, int gamesPlayed, int goals,
               int assists, int points, int penalty, double fightStat, double shotStat, double passStat) :
        Player(rank, name, born, position, gamesPlayed,goals, assists,
               points, penalty, fightStat*1.2, shotStat, passStat){
}

string Fighter::playerSaying() {
    string catchPhrase;
    int i = rand()%10;
    if(0 <= i <= 2) {
        catchPhrase = "I'm known for my fighting ability, we'll see what you got";
    }
    if(3 <= i <= 5) {
        catchPhrase = "You better watch out, you're gonna regret challenging me";
    } else {
        catchPhrase = "I hope you brought your A-game!";
    }
    return catchPhrase;
}

string Fighter::getPlayerType() {
    return "Fighter";
}