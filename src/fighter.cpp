#include "fighter.h"
#include <iostream>


Fighter::Fighter(const std::string& n, double w) : name(n), winRate(w) {}


// Method
bool Fighter::fights(const Fighter& opponent, std::mt19937& gen) const {
    /**
     * @brief Simulate a single fight vs Opponent
     * 
     */
    double total = this->winRate + opponent.winRate;
    double prob = this->winRate / total;

    std::uniform_real_distribution<double> dist(0.0, 1.0);

    return dist(gen) < prob;
}


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