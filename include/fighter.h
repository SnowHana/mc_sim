#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <random>

class Fighter {
    private:
        std::string name;
        double height;
        double weight;
        double reach;
        double slpm;
        double str_acc;
        double sapm;
        double str_def;
        double td_avg;
        double td_acc;
        double td_def;
        double sub_avg;
        int style; // 0 = Balanced, 1 = Grappler, 2 = Striker
    public:
        // Constructor
        Fighter(const std::string& n, double h, double w, double r, double sl, double sa, double sap, double sd, double ta, double tac, double td, double sub, int st);
        
        // Getter
        const std::string& getName() const { return name; }
        
        // Fight against other fighter
        bool fights(const Fighter& opponent, std::mt19937& gen) const;
};

#endif