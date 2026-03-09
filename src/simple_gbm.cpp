#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <algorithm>
#include <numeric>
/**
 * Simple simulator using GBM
 * https://en.wikipedia.org/wiki/Geometric_Brownian_motion
 * Single step (1 year)
 */
int main() {
    // 1. Initial param.
    double s0 = 100;        // Starting price
    double mu = 0.05;       // Expected return
    double sigma = 0.25;    // Volatality
    double T = 1.0;         // Time in years
    int steps = 1000;      // Number of simulations

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

    int entry_num;
    std::cout << "Enter a number to view i th price.\n";
    while (std::cin >> entry_num) {
        if (entry_num >= final_prices.size() || entry_num < 0) {
            std::cout << "Enter a valid number\n";
            continue;
        } 
        std::cout << entry_num << " th prices: " << final_prices[entry_num] << "\n";
        std::cout << "Enter a number to view i th price.\n";
    }

    // View max, min, avg
    auto [min_it, max_it] = std::minmax_element(final_prices.begin(), final_prices.end());

    double sum = std::accumulate(final_prices.begin(), final_prices.end(), 0.0);
    double avg = sum / final_prices.size();

    std::cout << "MIN: " << *min_it << "\n";
    std::cout << "MAX: " << *max_it << "\n";
    std::cout << "AVG: " << avg << "\n";

    return 0;
}