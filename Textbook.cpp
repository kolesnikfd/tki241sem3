#include "Textbook.h"

miit::algebra::Textbook::Textbook(const std::string& title, const std::vector<std::string>& authors,
	const std::string& topic, const std::string& publisher,
	const size_t year, const size_t rack, const size_t shelf,
	const std::string& discipline)
	: Publication(title, authors, topic, publisher, year, rack, shelf), discipline{ discipline }
{
}

const std::string& miit::algebra::Textbook::getDiscipline() const
{
	return this->discipline;
}

std::string miit::algebra::Textbook::getKind() const
{
	return "Учебник";
}

std::string miit::algebra::Textbook::toString() const
{
	return Publication::toString() + "  Дисциплина: " + this->discipline + "\n";
}
