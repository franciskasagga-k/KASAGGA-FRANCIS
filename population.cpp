#include <iostream>

int main() {
    // Given values
    long current_population = 312032486;
    long seconds_in_year = 365 * 24 * 60 * 60; // 31,536,000 seconds

    // Rates per year
    double births_per_year = seconds_in_year / 7.0;
    double deaths_per_year = seconds_in_year / 13.0;
    double immigrants_per_year = seconds_in_year / 45.0;

    // Annual population change
    double net_change_per_year = births_per_year - deaths_per_year + immigrants_per_year;

    // Display population projection for each of the next 5 years
    for (int year = 1; year <= 5; ++year) {
        current_population += static_cast<long>(net_change_per_year);
        std::cout << "Year " << year << " Population: " << current_population << std::endl;
    }

    return 0;
}