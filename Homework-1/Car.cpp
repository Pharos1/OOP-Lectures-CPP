#include <string>
#include <stdexcept>
#include <utility>
#include "Headers/Car.hpp"

Car::Car() : brand("Unknown"), year(2000), price(0.0) { ++total; }
Car::Car(std::string b, int y, double p)
	: brand(std::move(b)), year(y), price(p) {
	if (p < 0) throw std::invalid_argument("Negative price");
	++total;
}

const std::string& Car::getBrand() const { return brand; }
int Car::getYear() const { return year; }
double Car::getPrice() const { return price; }

void Car::setPrice(double p) {
	if (p < 0) throw std::invalid_argument("Negative price");
	price = p;
}

std::string Car::to_string() const {
	return brand + " (" + std::to_string(year) + ") - " +
		std::to_string(price) + " BGN.";
}

int Car::getTotal() { return total; }

// Initialize car total
inline int Car::total = 0;