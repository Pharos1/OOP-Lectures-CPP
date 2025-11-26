#include <string>
#include <vector>
#include <utility>
#include "Headers/Dealer.hpp"

Dealer::Dealer(std::string n) : name(std::move(n)) {}

void Dealer::addCar(const Car& c) { stock.push_back(c); }

double Dealer::totalValue() const {
    double sum = 0;
    for (const auto& c : stock) sum += c.getPrice();
    return sum;
}

std::vector<Car> Dealer::newerThan(int year) const {
    std::vector<Car> result;
    for (const auto& c : stock)
        if (c.getYear() > year)
            result.push_back(c);
    return result;
}

std::string Dealer::to_string() const {
    return "Dealer: " + name +
        "\nTotal cars: " + std::to_string(stock.size()) +
        "\nInventory value: " + std::to_string(totalValue()) + " BGN.";
}