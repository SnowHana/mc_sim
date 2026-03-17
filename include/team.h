#ifndef TEAM_H
#define TEAM_H

#include <string>
#include <random>
#include <vector>

class Team {
    private:
        std::string name;
        double winRate;
    public:
        // Constructor
        Team(const std::string& n, double w);
        // Getter
        const std::string& getName() const { return name; }
        const double& getWinRate() const { return winRate; }
        // Fight against other fighter
        bool fights(const Team& opponent, std::mt19937& gen) const;
};

#endif