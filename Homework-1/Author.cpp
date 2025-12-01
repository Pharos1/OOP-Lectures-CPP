#include "Headers/Author.hpp"

Author::Author() : name("Unknown"), birthYear(1900) {}
Author::Author(const std::string& name, int birthYear) : name(std::move(name)), birthYear(birthYear) {}

std::string Author::to_string() const {
	return name + " | born in " + std::to_string(birthYear) + "\n";
}


//Getters
std::string Author::getName() const { return name; }
int Author::getBirthYear() const { return birthYear; }

//Setters
void Author::setName(const std::string& name) {
	this->name = name;
}
void Author::setBirthYear(const int birthYear) {
	if (birthYear < 1850 || birthYear > 2025) {
		std::cerr << "ERR::Invalid year entered " << std::to_string(birthYear) << ". Value must be between 1850 and 2025\n";
		return;
	}

	this->birthYear = birthYear;
}