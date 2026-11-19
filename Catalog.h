#pragma once

#include "Publication.h"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

namespace miit::algebra
{
	/**
	* @brief Справочная библиотеки: поиск изданий по названию, автору, тематике,
	*        издательству и выдача местонахождения на полке
	*        Каталог не владеет изданиями: он хранит ссылку на коллекцию,
	*        которая должна существовать, пока существует каталог
	*        Поиск выполняется по вхождению подстроки с учётом регистра
	*/
	class Catalog
	{
		private:
			const std::vector<std::unique_ptr<Publication>>& items;

			/**
			* @brief Проверить, что строка text содержит подстроку part
			*/
			static bool contains(const std::string& text, const std::string& part);

		public:
			/**
			* @brief Конструктор
			* @param items Коллекция изданий (объекты наследников через указатель на базовый класс)
			*/
			Catalog(const std::vector<std::unique_ptr<Publication>>& items);

			/**
			* @brief Количество изданий в каталоге
			*/
			size_t getCount() const;

			/**
			* @brief Найти издания по названию
			*/
			std::vector<const Publication*> findByTitle(const std::string& title) const;

			/**
			* @brief Найти труды автора. Учитывает соавторство: издание подходит,
			*        если автор указан среди любых его авторов
			*/
			std::vector<const Publication*> findByAuthor(const std::string& author) const;

			/**
			* @brief Найти издания по тематике
			*/
			std::vector<const Publication*> findByTopic(const std::string& topic) const;

			/**
			* @brief Найти издания по издательству
			*/
			std::vector<const Publication*> findByPublisher(const std::string& publisher) const;

			/**
			* @brief Местонахождение изданий с данным названием
			*        Каждая строка имеет вид "Название: стеллаж N, полка M"
			*        Если ничего не найдено, возвращает пустую строку
			*/
			std::string getLocation(const std::string& title) const;

			/**
			* @brief Представить список изданий в виде строки
			*/
			static std::string listToString(const std::vector<const Publication*>& list);
	};
}
