#include "Book.h"

miit::algebra::Book::Book(const std::string& title, const std::vector<std::string>& authors,
	const std::string& topic, const std::string& publisher,
	const size_t year, const size_t rack, const size_t shelf)
	: Publication(title, authors, topic, publisher, year, rack, shelf)
{
}

std::string miit::algebra::Book::getKind() const
{
	return "Книга";
}
