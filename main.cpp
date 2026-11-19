#include "Publication.h"
#include "Book.h"
#include "Textbook.h"
#include "Magazine.h"
#include "Catalog.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace miit::algebra;

enum class MenuItem
{
	Exit = 0,
	ShowAll = 1,
	FindByTitle = 2,
	FindByAuthor = 3,
	FindByTopic = 4,
	FindByPublisher = 5,
	ShowLocation = 6
};

void fillCollection(std::vector<std::unique_ptr<Publication>>& collection)
{
	collection.push_back(std::make_unique<Book>(
		"Война и мир", std::vector<std::string>{ "Толстой Л.Н." },
		"Классика", "Азбука", 2018, 1, 1));

	collection.push_back(std::make_unique<Book>(
		"Мастер и Маргарита", std::vector<std::string>{ "Булгаков М.А." },
		"Классика", "Азбука", 2019, 1, 2));

	collection.push_back(std::make_unique<Book>(
		"Трудно быть богом", std::vector<std::string>{ "Стругацкий А.Н.", "Стругацкий Б.Н." },
		"Фантастика", "АСТ", 2017, 2, 1));

	collection.push_back(std::make_unique<Textbook>(
		"Программирование на C++", std::vector<std::string>{ "Страуструп Б." },
		"Программирование", "Диалектика", 2020, 3, 1, "Объектно-ориентированное программирование"));

	collection.push_back(std::make_unique<Textbook>(
		"Дискретная математика", std::vector<std::string>{ "Новиков Ф.А.", "Иванов И.И." },
		"Математика", "Питер", 2016, 3, 2, "Дискретная математика"));

	collection.push_back(std::make_unique<Magazine>(
		"Наука и жизнь", std::vector<std::string>{},
		"Научно-популярный", "Правда", 2023, 4, 1, 5));
}

void printCollection(const std::vector<std::unique_ptr<Publication>>& collection)
{
	for (size_t i = 0; i < collection.size(); i++)
	{
		std::cout << collection[i]->toString() << std::endl;
	}
}

void printResult(const std::string& title, const std::vector<const Publication*>& found)
{
	std::cout << title << std::endl;
	if (found.empty())
	{
		std::cout << "Ничего не найдено" << std::endl;
	}
	else
	{
		std::cout << Catalog::listToString(found);
	}
}

std::string readLine(const std::string& prompt)
{
	std::string line;
	std::cout << prompt;
	std::cin >> std::ws;
	std::getline(std::cin, line);
	return line;
}

void printMenu()
{
	std::cout << "Справочная библиотеки" << std::endl;
	std::cout << static_cast<int>(MenuItem::ShowAll) << " - показать все издания" << std::endl;
	std::cout << static_cast<int>(MenuItem::FindByTitle) << " - найти по названию" << std::endl;
	std::cout << static_cast<int>(MenuItem::FindByAuthor) << " - найти труды автора" << std::endl;
	std::cout << static_cast<int>(MenuItem::FindByTopic) << " - найти по тематике" << std::endl;
	std::cout << static_cast<int>(MenuItem::FindByPublisher) << " - найти по издательству" << std::endl;
	std::cout << static_cast<int>(MenuItem::ShowLocation) << " - узнать местонахождение книги" << std::endl;
	std::cout << static_cast<int>(MenuItem::Exit) << " - выход" << std::endl;
	std::cout << "Ваш выбор: ";
}

int main()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);

	std::cout << "Все издания библиотеки:" << std::endl;
	printCollection(collection);

	Catalog catalog(collection);

	bool running = true;
	while (running)
	{
		printMenu();

		int choice = 0;
		if (!(std::cin >> choice))
		{
			std::cout << std::endl << "Ввод завершён" << std::endl;
			break;
		}

		switch (static_cast<MenuItem>(choice))
		{
			case MenuItem::ShowAll:
			{
				printCollection(collection);
				break;
			}
			case MenuItem::FindByTitle:
			{
				std::string title = readLine("Введите название: ");
				printResult("\nРезультат поиска по названию:", catalog.findByTitle(title));
				break;
			}
			case MenuItem::FindByAuthor:
			{
				std::string author = readLine("Введите автора: ");
				printResult("\nТруды автора:", catalog.findByAuthor(author));
				break;
			}
			case MenuItem::FindByTopic:
			{
				std::string topic = readLine("Введите тематику: ");
				printResult("\nИздания по тематике:", catalog.findByTopic(topic));
				break;
			}
			case MenuItem::FindByPublisher:
			{
				std::string publisher = readLine("Введите издательство: ");
				printResult("\nИздания издательства:", catalog.findByPublisher(publisher));
				break;
			}
			case MenuItem::ShowLocation:
			{
				std::string title = readLine("Введите название книги: ");
				std::string location = catalog.getLocation(title);
				if (location.empty())
				{
					std::cout << "\nКнига не найдена" << std::endl;
				}
				else
				{
					std::cout << "\nМестонахождение:" << std::endl << location;
				}
				break;
			}
			case MenuItem::Exit:
			{
				running = false;
				break;
			}
			default:
			{
				std::cout << "Такого пункта меню нет" << std::endl;
				break;
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
