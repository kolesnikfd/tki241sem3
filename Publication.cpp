#include "Publication.h"

miit::algebra::Publication::Publication(const std::string& title, const std::vector<std::string>& authors,
	const std::string& topic, const std::string& publisher,
	const size_t year, const size_t rack, const size_t shelf)
	: title{ title }, authors{ authors }, topic{ topic }, publisher{ publisher },
	year{ year }, rack{ rack }, shelf{ shelf }
{
}

miit::algebra::Publication::~Publication()
{
}

const std::string& miit::algebra::Publication::getTitle() const
{
	return this->title;
}

const std::vector<std::string>& miit::algebra::Publication::getAuthors() const
{
	return this->authors;
}

std::string miit::algebra::Publication::getAuthorsText() const
{
	if (this->authors.empty())
	{
		return "не указаны";
	}

	std::string result;
	for (size_t i = 0; i < this->authors.size(); i++)
	{
		if (i > 0)
		{
			result += ", ";
		}
		result += this->authors[i];
	}
	return result;
}

const std::string& miit::algebra::Publication::getTopic() const
{
	return this->topic;
}

const std::string& miit::algebra::Publication::getPublisher() const
{
	return this->publisher;
}

size_t miit::algebra::Publication::getYear() const
{
	return this->year;
}

size_t miit::algebra::Publication::getRack() const
{
	return this->rack;
}

size_t miit::algebra::Publication::getShelf() const
{
	return this->shelf;
}

std::string miit::algebra::Publication::getLocation() const
{
	return "стеллаж " + std::to_string(this->rack) + ", полка " + std::to_string(this->shelf);
}

std::string miit::algebra::Publication::toString() const
{
	std::string result;
	result += "[" + this->getKind() + "] " + this->title + "\n";
	result += "  Авторы: " + this->getAuthorsText() + "\n";
	result += "  Тематика: " + this->topic + "\n";
	result += "  Издательство: " + this->publisher + ", " + std::to_string(this->year) + "\n";
	result += "  Расположение: " + this->getLocation() + "\n";
	return result;
}
