#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <random>

class Fighter {
    public:
        std::string name;
        double winRate;

    // Constructor
    Fighter(std::string n, double w);
    
    bool fights(const Fighter& opponent, std::mt19937& gen);
};

#endif