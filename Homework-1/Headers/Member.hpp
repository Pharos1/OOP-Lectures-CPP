#pragma once
#include <string>

class Member {
	std::string name;
	std::string memberId;
	int yearJoined;



	std::string to_string() const;
};