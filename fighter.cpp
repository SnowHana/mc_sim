#include "fighter.h"

Fighter::Fighter(std::string n, double w) : name(n), winRate(w) {}

// Method
bool Fighter::fights(const Fighter& opponent, std::mt19937& gen) {
    double total = this->winRate + opponent.winRate;
    double prob = this->winRate / total;

    std::uniform_real_distribution<double> dist(0.0, 1.0);

    return dist(gen) < prob;
}