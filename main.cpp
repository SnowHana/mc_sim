#include <iostream>
#include "fighter.h"

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());

    Fighter f1("Jon Jones", 0.94);
    Fighter f2("Stipe Miocic", 0.80);

    if (f1.fights(f2, gen)) {
        std::cout << f1.name << " wins!" << std::endl;
    } else {
        std::cout << f2.name << " wins!" << std::endl;
    }

    return 0;
}