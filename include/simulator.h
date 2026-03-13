#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "fightnight.h"
#include <map>
#include <memory>
/**
 * @brief Simulate bankroll...
 * 
 */

struct Bet {
    double betAmount;
    const Fighter* fighterPick;
    bool isCorrect;
    const Match match;
};

class Simulator {
    private:
        std::mt19937 gen;
        std::vector<std::unique_ptr<Fighter>> fightersDatabase;
        std::vector<Bet> betRecords;
        double accountBalance;



    public:
        Simulator();

        void runInterface();
        void showOdds(const FightNight& fn);
        // void addFighter()


};
#endif