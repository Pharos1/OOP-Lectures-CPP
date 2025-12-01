#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Author {
	std::string name;
	int birthYear;

public:
	Author();
	Author(std::string name, int birthYear);

	std::string to_string() const;

	//Getters
	std::string getName() const;
	int getBirthYear() const;

	//Setters
	void setName(const std::string& name);
	void setBirthYear(const int year);
};