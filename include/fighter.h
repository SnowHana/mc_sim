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
    
    bool fights(const Fighter& opponent, std::mt19937& gen) const;
};

class FightNight {
    public:
        // Vector of pairs : ie. <"Miocic", "Jones">
        std::vector<std::pair<const Fighter*, const Fighter*>> fightCard;    
        void addMatch(const Fighter& f1, const Fighter& f2);
        void removeMatch(const Fighter& f1, const Fighter& f2);
        // Prediction
        std::vector<bool> prediction_mc(std::mt19937& gen, const int simNum);

};

#endif