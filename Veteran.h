//
// Created by Wyatt Chrisman on 2/23/23.
//

#include "Player.h"

#ifndef M2OEP_WCHRISMA_VETERAN_H
#define M2OEP_WCHRISMA_VETERAN_H

class Veteran : public Player {
public:
    Veteran();

    explicit Veteran(int rank, string name, int born, string position, int gamesPlayed, int goals,
                    int assists, int points, int penalty, double fightStat, double shotStat, double passStat);


    virtual std::string playerSaying() override;

    virtual std::string getPlayerType() override;
};

#endif //M2OEP_WCHRISMA_VETERAN_H
