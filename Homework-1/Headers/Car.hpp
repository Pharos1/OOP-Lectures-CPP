#pragma once
#include <string>
#include <stdexcept>
#include <utility>

class Car {
	std::string brand;
	int year;
	double price;
	static int total;

public:
	Car();

	Car(std::string b, int y, double p);

	~Car() = default;

	const std::string& getBrand() const;
	int getYear() const;
	double getPrice() const;
	void setPrice(double p);
	std::string to_string() const;
	static int getTotal();
};