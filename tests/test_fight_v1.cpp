#include <iostream>
#include <cassert>
#include "fighter.h"

void test_fighter_creation() {
    // Basic fighter creation
    Fighter f("Topuria", 0.75);
    assert(f.getName() == "Topuria");
    assert(f.getWinRate() == 0.75);
    std::cout << "✅ test_fighter_creation passed!" << std::endl;
}

void test_match_addition() {
    FightNight fn;
    Fighter f1("Jones", 0.5), f2("Miocic", 0.5);
    fn.addMatch(f1, f2);
    assert(fn.getFightcards().size() == 1);
    std::cout << "✅ test_match_addition passed!" << std::endl;

    Fighter f3("Topuria", 0.5), f4("Volka", 0.5);
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