#include "Headers/Book.hpp"

Book::Book() : title("Untitled"), author(Author()), year(1900), price(0.0), isbn("Undefined") {}
Book::Book(std::string title, Author author, int year, double price, std::string isbn)
	: title(std::move(title)), author(std::move(author)), year(year), price(price), isbn(std::move(isbn)) {}

Book::~Book() {
	--totalBooks;
}

//Copy constructor
Book::Book(const Book& rhs) {
	title = rhs.title;
	author = rhs.author;
	year = rhs.year;
	price = rhs.price;
	isbn = rhs.isbn;
}
 
//Copy asignment
Book& Book::operator=(const Book& rhs) {
	if (this != &rhs) {
		title = rhs.title;
		author = rhs.author;
		year = rhs.year;
		price = rhs.price;
		isbn = rhs.isbn;
	}

	return *this;
}

//Move constructor
Book::Book(Book&& src) noexcept {
	title = src.title;
	author = src.author;
	year = src.year;
	price = src.price;
	isbn = src.isbn;

	src.title = "Untitled";
	src.author = Author();
	src.year = 0;
	src.price = 0.0;
	src.isbn = "Undefined";
}

//Move assignment
Book& Book::operator=(Book&& src) noexcept {
	if (this != &src) {
		title = src.title;
		author = src.author;
		year = src.year;
		price = src.price;
		isbn = src.isbn;

		src.title = "Untitled";
		src.author = Author();
		src.year = 0;
		src.price = 0.0;
		src.isbn = "Undefined";

	}
	return *this;
}

void Book::setYear(int year) {
	if (year < 1850 || year > 2025) {
		std::cerr << "ERR::Book::Invalid year entered " << std::to_string(year) << ". Value must be between 1850 and 2025\n";
		return;
	}
	this->year = year;
}

void Book::setPrice(double price) {
	if (price < 0) {
		std::cerr << "ERR::Book::Invalid price entered " << std::to_string(price) << ". Value must be >= 0\n";
		return;
	}

	this->price = price;
}

std::string Book::to_string() const {
	return "\"" + title + "\"" + " written by " + author.getName() + " published in " + std::to_string(year) + " priced at " + std::to_string(price) + " with ISBN " + isbn + "\n";
}