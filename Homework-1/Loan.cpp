#include "Headers/Loan.hpp"
#include <iostream>

Loan::Loan(std::string isbn, std::string memberId, std::string startDate, std::string dueDate, bool returned) {
	if (dueDate < startDate) {
		std::cerr << "ERR::Loan::Due date is before start day or they are not in YYYY-MM-DD format!\n";
		return;
	}

	this->isbn = std::move(isbn);
	this->memberId = std::move(memberId);
	this->startDate = std::move(startDate);
	this->dueDate = std::move(dueDate);

	this->returned = returned;
}


bool Loan::isOverdue(const std::string& today) const {
	if (today > dueDate)
		return true;
	else
		return false;
}

std::string Loan::to_string() const {
	return "Book with isbn " + isbn + " loaned to member with id " + memberId + " loaned at " + startDate + " must be returned due " + dueDate + " status: " + (returned ? "returned" : "not returned");
}