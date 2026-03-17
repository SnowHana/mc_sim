#include <iostream>
#include "fighter.h"
#include "fightnight.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // name, h, w, r, sl, sa, sap, sd, ta, tac, td, sub, st
    Fighter f1("Jon Jones", 76.0, 205.0, 84.0, 4.30, 0.57, 2.22, 0.64, 1.85, 0.44, 0.95, 0.8, 0);
    Fighter f2("Stipe Miocic", 76.0, 240.0, 80.0, 4.82, 0.52, 3.00, 0.54, 2.09, 0.35, 0.73, 0.0, 2);

    // if (f1.fights(f2, gen)) {
    //     std::cout << f1.name << " wins!" << std::endl;
    // } else {
    //     std::cout << f2.name << " wins!" << std::endl;
    // }
    FightNight ufc300;
    ufc300.addMatch(f1, f2);

    std::cout << "----Fight Prediction----" << std::endl;
    ufc300.prediction_mc(gen, 100);


    return 0;
}