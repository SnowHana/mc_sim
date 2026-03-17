#include <iostream>
#include <cassert>
#include "fighter.h"
#include "fightnight.h"

void test_fighter_creation() {
    // Basic fighter creation
    Fighter f("Topuria", 67.0, 145.0, 69.0, 3.32, 0.46, 3.35, 0.67, 1.92, 0.56, 0.92, 0.5, 0);
    assert(f.getName() == "Topuria");
    std::cout << "✅ test_fighter_creation passed!" << std::endl;
}

void test_match_addition() {
    FightNight fn;
    Fighter f1("Jones", 76.0, 205.0, 84.0, 4.30, 0.57, 2.22, 0.64, 1.85, 0.44, 0.95, 0.8, 0);
    Fighter f2("Miocic", 76.0, 240.0, 80.0, 4.82, 0.52, 3.00, 0.54, 2.09, 0.35, 0.73, 0.0, 2);
    fn.addMatch(f1, f2);
    assert(fn.getFightcards().size() == 1);
    std::cout << "✅ test_match_addition passed!" << std::endl;

    Fighter f3("Topuria", 67.0, 145.0, 69.0, 3.32, 0.46, 3.35, 0.67, 1.92, 0.56, 0.92, 0.5, 0);
    Fighter f4("Volka", 66.0, 145.0, 71.5, 6.25, 0.50, 3.36, 0.58, 1.84, 0.37, 0.72, 0.2, 2);
    fn.addMatch(f3, f4);
    assert(fn.getFightcards().size() == 2);
    std::cout << "✅ test_match_addition passed!" << std::endl;
}

int main() {
    test_fighter_creation();
    test_match_addition();
    std::cout << "All tests passed successfully!" << std::endl;
    return 0;
}