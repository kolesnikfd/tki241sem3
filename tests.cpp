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

int failed = 0;
int total = 0;

void check(bool condition, const std::string& name)
{
	total++;
	if (!condition)
	{
		failed++;
		std::cout << "[FAIL] " << name << std::endl;
	}
	else
	{
		std::cout << "[ OK ] " << name << std::endl;
	}
}

bool contains(const std::string& text, const std::string& part)
{
	return text.find(part) != std::string::npos;
}

void fillCollection(std::vector<std::unique_ptr<Publication>>& collection)
{
	collection.push_back(std::make_unique<Book>(
		"Война и мир", std::vector<std::string>{ "Толстой Л.Н." },
		"Классика", "Азбука", 2018, 1, 1));

	collection.push_back(std::make_unique<Book>(
		"Трудно быть богом", std::vector<std::string>{ "Стругацкий А.Н.", "Стругацкий Б.Н." },
		"Фантастика", "АСТ", 2017, 2, 1));

	collection.push_back(std::make_unique<Textbook>(
		"Дискретная математика", std::vector<std::string>{ "Новиков Ф.А.", "Стругацкий А.Н." },
		"Математика", "Питер", 2016, 3, 2, "Дискретная математика"));

	collection.push_back(std::make_unique<Magazine>(
		"Наука и жизнь", std::vector<std::string>{},
		"Классика", "Азбука", 2023, 4, 1, 5));
}

void testPublications()
{
	Book book("Война и мир", std::vector<std::string>{ "Толстой Л.Н." },
		"Классика", "Азбука", 2018, 3, 2);

	check(book.getTitle() == "Война и мир", "Book: название");
	check(book.getAuthors().size() == 1 && book.getAuthors()[0] == "Толстой Л.Н.", "Book: авторы");
	check(book.getTopic() == "Классика", "Book: тематика");
	check(book.getPublisher() == "Азбука", "Book: издательство");
	check(book.getYear() == 2018, "Book: год издания");
	check(book.getRack() == 3 && book.getShelf() == 2, "Book: стеллаж и полка");
	check(book.getLocation() == "стеллаж 3, полка 2", "Book: местонахождение");
	check(book.getKind() == "Книга", "Book: вид издания");
	check(contains(book.toString(), "[Книга] Война и мир"), "Book: toString содержит вид и название");

	Book coauthors("Трудно быть богом", std::vector<std::string>{ "Стругацкий А.Н.", "Стругацкий Б.Н." },
		"Фантастика", "АСТ", 2017, 2, 1);
	check(coauthors.getAuthorsText() == "Стругацкий А.Н., Стругацкий Б.Н.", "Book: соавторы через запятую");

	Textbook textbook("Дискретная математика", std::vector<std::string>{ "Новиков Ф.А." },
		"Математика", "Питер", 2016, 3, 1, "Информатика");
	check(textbook.getKind() == "Учебник", "Textbook: вид издания");
	check(textbook.getDiscipline() == "Информатика", "Textbook: дисциплина");
	check(contains(textbook.toString(), "Дисциплина: Информатика"), "Textbook: toString содержит дисциплину");

	Magazine magazine("Наука и жизнь", std::vector<std::string>{},
		"Научно-популярный", "Правда", 2023, 4, 1, 5);
	check(magazine.getKind() == "Журнал", "Magazine: вид издания");
	check(magazine.getIssueNumber() == 5, "Magazine: номер выпуска");
	check(magazine.getAuthorsText() == "не указаны", "Magazine: авторов нет");
	check(contains(magazine.toString(), "Номер выпуска: 5"), "Magazine: toString содержит номер выпуска");
}

void testPolymorphism()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);

	check(collection.size() == 4, "Коллекция: размер");
	check(collection[0]->getKind() == "Книга", "Полиморфизм: Book через базовый класс");
	check(collection[2]->getKind() == "Учебник", "Полиморфизм: Textbook через базовый класс");
	check(collection[3]->getKind() == "Журнал", "Полиморфизм: Magazine через базовый класс");
	check(contains(collection[2]->toString(), "Дисциплина:"), "Полиморфизм: toString наследника");
}

void testFindByTitle()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);
	Catalog catalog(collection);

	check(catalog.getCount() == 4, "Catalog: количество изданий");

	std::vector<const Publication*> found = catalog.findByTitle("Война");
	check(found.size() == 1 && found[0]->getTitle() == "Война и мир", "findByTitle: часть названия");

	check(catalog.findByTitle("Несуществующая").empty(), "findByTitle: ничего не найдено");
}

void testFindByAuthor()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);
	Catalog catalog(collection);

	std::vector<const Publication*> found = catalog.findByAuthor("Стругацкий А.Н.");
	check(found.size() == 2, "findByAuthor: учитывает соавторство");
	check(found[0]->getTitle() == "Трудно быть богом" && found[1]->getTitle() == "Дискретная математика",
		"findByAuthor: найдены нужные труды");

	check(catalog.findByAuthor("Стругацкий Б.Н.").size() == 1, "findByAuthor: второй соавтор");
	check(catalog.findByAuthor("Неизвестный").empty(), "findByAuthor: автор не найден");
}

void testFindByTopicAndPublisher()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);
	Catalog catalog(collection);

	check(catalog.findByTopic("Классика").size() == 2, "findByTopic: книга и журнал одной тематики");
	check(catalog.findByTopic("Кулинария").empty(), "findByTopic: ничего не найдено");

	std::vector<const Publication*> found = catalog.findByPublisher("Азбука");
	check(found.size() == 2, "findByPublisher: два издания издательства");
	check(catalog.findByPublisher("Нет такого").empty(), "findByPublisher: ничего не найдено");
}

void testLocation()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);
	Catalog catalog(collection);

	check(catalog.getLocation("Трудно быть богом") == "Трудно быть богом: стеллаж 2, полка 1\n",
		"getLocation: местонахождение книги");
	check(catalog.getLocation("Нет такой").empty(), "getLocation: книга не найдена");
}

void testListToString()
{
	std::vector<std::unique_ptr<Publication>> collection;
	fillCollection(collection);
	Catalog catalog(collection);

	std::string text = Catalog::listToString(catalog.findByTitle("Наука"));
	check(contains(text, "[Журнал] Наука и жизнь"), "listToString: описание найденного издания");

	std::vector<const Publication*> empty;
	check(Catalog::listToString(empty).empty(), "listToString: пустой список");
}

void testEmptyCatalog()
{
	std::vector<std::unique_ptr<Publication>> collection;
	Catalog catalog(collection);

	check(catalog.getCount() == 0, "Пустой каталог: размер");
	check(catalog.findByTitle("Война").empty(), "Пустой каталог: поиск по названию");
	check(catalog.findByAuthor("Толстой").empty(), "Пустой каталог: поиск по автору");
	check(catalog.getLocation("Война").empty(), "Пустой каталог: местонахождение");
}

int main()
{
	testPublications();
	testPolymorphism();
	testFindByTitle();
	testFindByAuthor();
	testFindByTopicAndPublisher();
	testLocation();
	testListToString();
	testEmptyCatalog();

	std::cout << "\nПройдено: " << (total - failed) << " из " << total << std::endl;
	return failed == 0 ? 0 : 1;
}
