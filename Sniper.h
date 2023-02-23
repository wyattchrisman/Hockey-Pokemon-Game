//
// Created by Wyatt Chrisman on 2/21/23.
//

#ifndef M2OEP_WCHRISMA_SNIPER_H
#define M2OEP_WCHRISMA_SNIPER_H


#include "Player.h"

class Sniper : public Player {
public:
    Sniper();

    explicit Sniper(int rank, string name, int born, string position, int gamesPlayed,
                     int goals, int assists, int points, int penalty, double fightStat, double shotStat, double passStat);

    virtual std::string playerSaying() override;

};


#endif //M2OEP_WCHRISMA_SNIPER_H
