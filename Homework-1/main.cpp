#include <iostream>
#include "Headers/Author.hpp"

int main() {
	Author author("Gosho Gay", 6767);
	author.setBirthYear(1200);

	std::cout << author.to_string();
}