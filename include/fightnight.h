#ifndef FIGHTNIGHT_H
#define FIGHTNIGHT_H

#include "fighter.h"

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
        const std::vector<Match>& getFightcards() const { return fightCards; }
};

#endif