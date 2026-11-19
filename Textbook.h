#pragma once

#include "Publication.h"

namespace miit::algebra
{
	/**
	* @brief Учебник. Дополнительно хранит учебную дисциплину
	*/
	class Textbook : public Publication
	{
		private:
			std::string discipline;

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
			* @param discipline Учебная дисциплина
			*/
			Textbook(const std::string& title, const std::vector<std::string>& authors,
				const std::string& topic, const std::string& publisher,
				const size_t year, const size_t rack, const size_t shelf,
				const std::string& discipline);

			/**
			* @brief Учебная дисциплина
			*/
			const std::string& getDiscipline() const;

			/**
			* @brief Вид издания: "Учебник"
			*/
			std::string getKind() const override;

			/**
			* @brief Общее описание издания и дисциплина
			*/
			std::string toString() const override;
	};
}
