#pragma once
#include <string>

class Loan {
	std::string isbn;
	std::string memberId;
	std::string startDate;
	std::string dueDate;
	bool returned;

public:
	Loan() = default;
	Loan(std::string isbn, std::string memberId, std::string startDate, std::string dueDate, bool returned);

	const std::string& getIsbn() { return isbn; }
	const std::string& getMemberId() { return memberId; }
	const std::string& getStartDate() { return startDate; }
	const std::string& getDueDate() { return dueDate; }

	void setIsbn(std::string isbn) { this->isbn = std::move(isbn); }
	void setMemberId(std::string memberId) { this->memberId = std::move(memberId); }
	void setStartDate(std::string startDate) { this->startDate = std::move(startDate); }
	void setDueDate(std::string dueDate) { this->dueDate = std::move(dueDate); }

	void markReturned() { returned = true; }
	bool isOverdue(const std::string& today) const;

	std::string to_string() const;
};