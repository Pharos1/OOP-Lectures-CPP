#pragma once
#include <string>

class Member {
	std::string name;
	std::string memberId;
	int yearJoined;

public:
	Member() = default;
	Member(std::string name, std::string memberId, int yearJoined);

	const std::string getName() const { return name; }
	const std::string getMemberId() const { return memberId; }
	int getYearJoined() const { return yearJoined; }

	void setName(std::string name) { this->name = std::move(name); }
	void setMemberId(std::string memberId);
	void setYearJoined(int year);

	std::string to_string() const;
};