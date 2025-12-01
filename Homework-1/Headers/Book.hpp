#pragma once
#include <string>
#include "Author.hpp"

class Book {
	std::string title;
	Author author;
	int year;
	double price;
	std::string isbn;

	inline static int totalBooks;

public:
	Book();
	Book(std::string title, Author author, int year, double price, std::string isbn);

	~Book();

	Book(const Book& rhs);
	Book& operator=(const Book& rhs);
	Book(Book&& src) noexcept;
	Book& operator=(Book&& src) noexcept;

	const std::string& getTitle() const { return title; }
	const Author& getAuthor() const { return author; }
	int getYear() const { return year; }
	double getPrice() const { return price; }
	const std::string& getIsbn() const { return isbn; }

	inline static int getTotalBooks() { return totalBooks; }

	void setTitle(std::string title) { this->title = std::move(title); }
	void setAuthor(Author author) { this->author = std::move(author); }
	void setYear(int year);
	void setPrice(double price);
	void setIsbn(std::string isbn) { this->isbn = isbn; }

	std::string to_string() const;
};