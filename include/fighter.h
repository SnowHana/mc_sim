#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <random>
#include <vector>

class Fighter {
    private:
        std::string name;
        double winRate;
    public:
        // Constructor
        Fighter(const std::string& n, double w);
        // Getter
        const std::string& getName() const { return name; }
        const double& getWinRate() const { return winRate; }
        // Fight against other fighter
        bool fights(const Fighter& opponent, std::mt19937& gen) const;
};

#endif