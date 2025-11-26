#pragma once
#include <string>
#include <vector>
#include <utility>
#include "Car.hpp"

class Dealer {
    std::string name;
    std::vector<Car> stock;

public:
    Dealer(std::string n);

    void addCar(const Car& c);

    double totalValue() const;
    std::vector<Car> newerThan(int year) const;

    std::string to_string() const;
};