#include "Catalog.h"

miit::algebra::Catalog::Catalog(const std::vector<std::unique_ptr<Publication>>& items)
	: items{ items }
{
}

bool miit::algebra::Catalog::contains(const std::string& text, const std::string& part)
{
	return text.find(part) != std::string::npos;
}

size_t miit::algebra::Catalog::getCount() const
{
	return this->items.size();
}

std::vector<const miit::algebra::Publication*> miit::algebra::Catalog::findByTitle(const std::string& title) const
{
	std::vector<const Publication*> result;
	for (size_t i = 0; i < this->items.size(); i++)
	{
		if (contains(this->items[i]->getTitle(), title))
		{
			result.push_back(this->items[i].get());
		}
	}
	return result;
}

std::vector<const miit::algebra::Publication*> miit::algebra::Catalog::findByAuthor(const std::string& author) const
{
	std::vector<const Publication*> result;
	for (size_t i = 0; i < this->items.size(); i++)
	{
		const std::vector<std::string>& authors = this->items[i]->getAuthors();
		for (size_t j = 0; j < authors.size(); j++)
		{
			if (contains(authors[j], author))
			{
				result.push_back(this->items[i].get());
				break;
			}
		}
	}
	return result;
}

std::vector<const miit::algebra::Publication*> miit::algebra::Catalog::findByTopic(const std::string& topic) const
{
	std::vector<const Publication*> result;
	for (size_t i = 0; i < this->items.size(); i++)
	{
		if (contains(this->items[i]->getTopic(), topic))
		{
			result.push_back(this->items[i].get());
		}
	}
	return result;
}

std::vector<const miit::algebra::Publication*> miit::algebra::Catalog::findByPublisher(const std::string& publisher) const
{
	std::vector<const Publication*> result;
	for (size_t i = 0; i < this->items.size(); i++)
	{
		if (contains(this->items[i]->getPublisher(), publisher))
		{
			result.push_back(this->items[i].get());
		}
	}
	return result;
}

std::string miit::algebra::Catalog::getLocation(const std::string& title) const
{
	std::vector<const Publication*> found = this->findByTitle(title);

	std::string result;
	for (size_t i = 0; i < found.size(); i++)
	{
		result += found[i]->getTitle() + ": " + found[i]->getLocation() + "\n";
	}
	return result;
}

std::string miit::algebra::Catalog::listToString(const std::vector<const Publication*>& list)
{
	std::string result;
	for (size_t i = 0; i < list.size(); i++)
	{
		result += list[i]->toString() + "\n";
	}
	return result;
}
