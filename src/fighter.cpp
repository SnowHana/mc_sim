#include "fighter.h"
#include <iostream>


Fighter::Fighter(std::string n, double w) : name(n), winRate(w) {}

// Method
bool Fighter::fights(const Fighter& opponent, std::mt19937& gen) const {
    double total = this->winRate + opponent.winRate;
    double prob = this->winRate / total;

    std::uniform_real_distribution<double> dist(0.0, 1.0);

    return dist(gen) < prob;
}

void FightNight::addMatch(const Fighter& f1, const Fighter& f2) {
    fightCard.push_back(std::make_pair(&f1, &f2));
    std::cout << "Added match: " << f1.name << " vs " << f2.name << "\n";
}

std::vector<bool> FightNight::prediction_mc(std::mt19937& gen, const int simNum) {
    // Predict all matches?
    std::vector<bool> results;
    for (const auto [f1, f2] : fightCard) {
        std::cout << f1->name << " vs " << f2->name << "-> : ";
        bool f1Win = f1->fights(*f2, gen);
        std::cout << f1Win; 
        results.push_back(f1Win);
    }

    return results;
    
}