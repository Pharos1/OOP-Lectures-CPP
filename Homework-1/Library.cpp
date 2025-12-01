#include "Headers/Library.hpp"


void Library::addBook(Book b) {
	books.push_back(std::move(b));
}
void Library::addMember(Member m) {
	members.push_back(std::move(m));
}

bool Library::hasBook(const std::string& isbn) const {
	for (const auto& b : books) {
		if (b.getIsbn() == isbn) {
			return true;
		}
	}

	return false;
}
bool Library::isBookAvailable(const std::string& isbn) const {
	for (const auto& l : loans) {
		if (l.getIsbn() == isbn) {
			return false;
		}
	}

	return true;
}
bool Library::loanBook(const std::string& isbn, const std::string& memberId, const std::string& start, const std::string& due) {
	if (isBookAvailable(isbn)) {
		loans.emplace_back(isbn, memberId, start, due, false);
		return true;
	}
	else {
		return false;
	}
}
bool Library::returnBook(const std::string& isbn, const std::string& memberId) {
	int i = 0;
	for (auto& l : loans) {
		if (l.getIsbn() == isbn) {
			l.markReturned();
			loans.erase(loans.begin() + i);
			return true;
		}
		++i;
	}
	
	return false;
}
std::vector<Book> Library::findByAuthor(const std::string& authorName) const {
	std::vector<Book> found;
	for (auto& b : books) {
		if (b.getAuthor().getName() == authorName) {
			found.push_back(b);
		}
	}

	return found;
}
std::string Library::to_string() const {
	return std::to_string(books.size()) + " books | " + std::to_string(members.size()) + " members | " + std::to_string(loans.size()) + " loans";
}