//
// Created by Wyatt Chrisman on 2/22/23.
//

#include "Player.h"

#ifndef M2OEP_WCHRISMA_NORMAL_H
#define M2OEP_WCHRISMA_NORMAL_H

class Normal : public Player {
public:
    Normal();

    explicit Normal(int rank, string name, int born, string position, int gamesPlayed,
                    int goals, int assists, int points, int penalty, double fightStat, double shotStat, double passStat);


    virtual std::string playerSaying() override;

};

#endif //M2OEP_WCHRISMA_NORMAL_H
