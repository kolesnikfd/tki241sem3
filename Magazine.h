#pragma once

#include "Publication.h"

namespace miit::algebra
{
	/**
	* @brief Журнал. Дополнительно хранит номер выпуска
	*/
	class Magazine : public Publication
	{
		private:
			size_t issueNumber;

		public:
			/**
			* @brief Конструктор
			* @param title Название
			* @param authors Список авторов (у журнала может быть пустым)
			* @param topic Тематика
			* @param publisher Издательство
			* @param year Год издания
			* @param rack Номер стеллажа
			* @param shelf Номер полки
			* @param issueNumber Номер выпуска
			*/
			Magazine(const std::string& title, const std::vector<std::string>& authors,
				const std::string& topic, const std::string& publisher,
				const size_t year, const size_t rack, const size_t shelf,
				const size_t issueNumber);

			/**
			* @brief Номер выпуска
			*/
			size_t getIssueNumber() const;

			/**
			* @brief Вид издания: "Журнал"
			*/
			std::string getKind() const override;

			/**
			* @brief Общее описание издания и номер выпуска
			*/
			std::string toString() const override;
	};
}
