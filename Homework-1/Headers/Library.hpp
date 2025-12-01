#pragma once
#include <vector>
#include "Book.hpp"
#include "Member.hpp"
#include "Loan.hpp"

class Library {
	std::vector<Book> books;
	std::vector<Member> members;
	std::vector<Loan> loans;

public:
	void addBook(Book b);
	void addMember(Member m);
	bool hasBook(const std::string& isbn) const;
	bool isBookAvailable(const std::string& isbn) const;
	bool loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due);
	bool returnBook(const std::string& isbn, const std::string& memberId);
	std::vector<Book> findByAuthor(const std::string& authorName) const;
	std::string to_string() const;
};