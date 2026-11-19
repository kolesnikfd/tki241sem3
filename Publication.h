#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace miit::algebra
{
	/**
	* @brief Абстрактный базовый класс издания библиотеки
	*        Хранит общие для всех изданий данные: название, авторов, тематику,
	*        издательство, год издания и место на полке
	*        Конкретный вид издания задаётся в наследниках через getKind()
	*/
	class Publication
	{
		private:
			std::string title;
			std::vector<std::string> authors;
			std::string topic;
			std::string publisher;
			size_t year;
			size_t rack;
			size_t shelf;

		protected:
			/**
			* @brief Конструктор. Защищённый: объект базового класса создать нельзя,
			*        его вызывают только конструкторы наследников
			* @param title Название
			* @param authors Список авторов (может быть пустым)
			* @param topic Тематика
			* @param publisher Издательство
			* @param year Год издания
			* @param rack Номер стеллажа
			* @param shelf Номер полки на стеллаже
			*/
			Publication(const std::string& title, const std::vector<std::string>& authors,
				const std::string& topic, const std::string& publisher,
				const size_t year, const size_t rack, const size_t shelf);

		public:
			/**
			* @brief Виртуальный деструктор
			*/
			virtual ~Publication();

			/**
			* @brief Название издания
			*/
			const std::string& getTitle() const;

			/**
			* @brief Список авторов
			*/
			const std::vector<std::string>& getAuthors() const;

			/**
			* @brief Авторы одной строкой через запятую
			*        Если авторов нет, возвращает "не указаны"
			*/
			std::string getAuthorsText() const;

			/**
			* @brief Тематика издания
			*/
			const std::string& getTopic() const;

			/**
			* @brief Издательство
			*/
			const std::string& getPublisher() const;

			/**
			* @brief Год издания
			*/
			size_t getYear() const;

			/**
			* @brief Номер стеллажа
			*/
			size_t getRack() const;

			/**
			* @brief Номер полки
			*/
			size_t getShelf() const;

			/**
			* @brief Местонахождение издания в виде строки, например "стеллаж 3, полка 2"
			*/
			std::string getLocation() const;

			/**
			* @brief Вид издания (например, "Книга")
			*        Чисто виртуальный метод, реализуется в наследниках
			*/
			virtual std::string getKind() const = 0;

			/**
			* @brief Представить издание в виде многострочного текста
			*        Наследники дополняют результат своими полями
			*/
			virtual std::string toString() const;
	};
}
