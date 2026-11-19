#pragma once

#include "Publication.h"

namespace miit::algebra
{
	/**
	* @brief Книга. Простое издание без дополнительных полей
	*/
	class Book : public Publication
	{
		public:
			/**
			* @brief Конструктор
			* @param title Название
			* @param authors Список авторов
			* @param topic Тематика
			* @param publisher Издательство
			* @param year Год издания
			* @param rack Номер стеллажа
			* @param shelf Номер полки
			*/
			Book(const std::string& title, const std::vector<std::string>& authors,
				const std::string& topic, const std::string& publisher,
				const size_t year, const size_t rack, const size_t shelf);

			/**
			* @brief Вид издания: "Книга"
			*/
			std::string getKind() const override;
	};
}
