#include "Headers/Member.hpp";
#include <iostream>

Member::Member(std::string name, std::string memberId, int yearJoined) : name(std::move(name)), memberId(std::move(memberId)), yearJoined(yearJoined) {}

void Member::setMemberId(std::string memberId) {
	if (memberId == "") {
		std::cerr << "ERR::Empty memberId entered";
		return;
	}

	this->memberId = memberId;
}
void Member::setYearJoined(int year) {
	if (year < 1850 || year > 2025) {
		std::cerr << "ERR::Member::Invalid year entered " << std::to_string(year) << ". Value must be between 1850 and 2025\n";
		return;
	}
}

std::string Member::to_string() const {
	return name + " with id " + memberId + " joined " + std::to_string(yearJoined);
}