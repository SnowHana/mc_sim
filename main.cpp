#include <iostream>
#include <vector>
#include <random>
#include <cmath>

int main() {
    // 1. Initial param.
    double s0 = 100;        // Starting price
    double mu = 0.05;       // Expected return
    double sigma = 0.25;    // Volatality
    double T = 1.0;         // Time in years
    int steps = 10000;      // Number of simulations

    // 2. RGN (Random Number Generator)
    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution<double> dist(0, 1);
    
    std::vector<double> final_prices;
    final_prices.push_back(s0);
    final_prices.reserve(steps + 10);

    for (int i = 0; i < steps; i++) {
        double Z = dist(gen);
        double sT = s0 * std::exp((mu - (sigma * sigma) / 2) * (T) + sigma * std::sqrt(T) * Z);
        final_prices.push_back(sT);
    }

    std::cout << "Initial price: " << final_prices[0] << "\n";
    for (int i = 1; i < 50; i++){
        std::cout << i << " th prices: " << final_prices[i] << "\n";
    }

    return 0;
}