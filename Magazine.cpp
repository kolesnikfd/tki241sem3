#include "Magazine.h"

miit::algebra::Magazine::Magazine(const std::string& title, const std::vector<std::string>& authors,
	const std::string& topic, const std::string& publisher,
	const size_t year, const size_t rack, const size_t shelf,
	const size_t issueNumber)
	: Publication(title, authors, topic, publisher, year, rack, shelf), issueNumber{ issueNumber }
{
}

size_t miit::algebra::Magazine::getIssueNumber() const
{
	return this->issueNumber;
}

std::string miit::algebra::Magazine::getKind() const
{
	return "Журнал";
}

std::string miit::algebra::Magazine::toString() const
{
	return Publication::toString() + "  Номер выпуска: " + std::to_string(this->issueNumber) + "\n";
}
