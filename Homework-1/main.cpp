#include <iostream>
#include "Headers/Dealer.hpp"

int main() {
    Dealer d{ "AutoMax" };
    d.addCar(Car{ "Toyota", 2020, 25500 });
    d.addCar(Car{ "Honda", 2018, 21000 });
    d.addCar(Car{ "BMW", 2021, 24000 });

    std::cout << d.to_string() << "\n";
    std::cout << "Cars newer than 2019:\n";
    for (const auto& c : d.newerThan(2019))
        std::cout << "  - " << c.to_string() << "\n";

    std::cout << "Total cars created: " << Car::getTotal() << "\n";
}