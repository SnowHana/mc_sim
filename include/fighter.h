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

struct Match {
    const Fighter* redCorner;
    const Fighter* blueCorner;
};

class FightNight {
    private:
        std::vector<Match> fightCards;
    public:
        // Vector of pairs : ie. <"Miocic", "Jones">
        void addMatch(const Fighter& f1, const Fighter& f2);
        void removeMatch(const Fighter& f1, const Fighter& f2);

        // Prediction
        std::vector<double> prediction_mc(std::mt19937& gen, const int simNum) const;
        
        // Getter
        const std::vector<Match>& getFightcards() { return fightCards; }
};
#endif