#include "fighter.h"
#include <iostream>

Fighter::Fighter(const std::string& n, double h, double w, double r, double sl, double sa, double sap, double sd, double ta, double tac, double td, double sub, int st) 
    : name(n), height(h), weight(w), reach(r), slpm(sl), str_acc(sa), sapm(sap), str_def(sd), td_avg(ta), td_acc(tac), td_def(td), sub_avg(sub), style(st) {}

// Method
bool Fighter::fights(const Fighter& opponent, std::mt19937& gen) const {
    /**
     * @brief Simulate a single fight vs Opponent using a basic rating heuristic.
     * We will score fighters based on striking and grappling output/defense.
     */
    
    // Striking Phase scoring
    double myStriking = (this->slpm * this->str_acc) + (opponent.sapm * (1.0 - opponent.str_def));
    double oppStriking = (opponent.slpm * opponent.str_acc) + (this->sapm * (1.0 - this->str_def));

    // Grappling Phase scoring
    double myGrappling = (this->td_avg * this->td_acc) + this->sub_avg + (this->td_def) * 0.5;
    double oppGrappling = (opponent.td_avg * opponent.td_acc) + opponent.sub_avg + (opponent.td_def) * 0.5;

    // Total Score
    double myScore = myStriking + myGrappling;
    double oppScore = oppStriking + oppGrappling;

    double total = myScore + oppScore;
    double prob = total > 0.0 ? (myScore / total) : 0.5;

    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(gen) < prob;
}
