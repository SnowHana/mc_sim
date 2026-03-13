#include "fightnight.h"
#include <iostream>


void FightNight::addMatch(const Fighter& f1, const Fighter& f2) {
    // TODO: Add....
    // Sanity check would be...
    // 1. Checking fighter s are legit? OR Same match already exist?
    Match match;
    match.redCorner = &f1;
    match.blueCorner = &f2;

    fightCards.push_back(match);
    std::cout << "Added match: " << f1.getName() << " vs " << f2.getName() << "\n";
}

std::vector<double> FightNight::prediction_mc(std::mt19937& gen, const int simNum) const {
    // Predict all matches using Monte Carlo
    std::vector<double> results;
    for (const auto& match : fightCards) {
        std::cout << match.redCorner->getName() << " vs " << match.blueCorner->getName() << "-> : ";
        std::size_t f1Wins = 0;
        for (std::size_t i = 0; i < static_cast<std::size_t>(simNum); ++i) {
            if (match.redCorner->fights(*match.blueCorner, gen)) {
                f1Wins++;
            }
        }
        double winProb = static_cast<double>(f1Wins) / simNum;
        std::cout << winProb * 100 << "%" << " vs " << (1 - winProb) * 100 << "%" << std::endl;
        results.push_back(f1Wins);
    }

    return results;
    
}