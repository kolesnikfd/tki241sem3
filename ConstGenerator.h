#pragma once

#include "Generator.h"

namespace miit::algebra
{
	/**
	* @brief Генератор, который всегда выдаёт одно и то же значение
	*/
	class ConstGenerator : public Generator
	{
		private:
			int value;

		public:
			/**
			* @brief Конструктор
			* @param value Значение, которое будет выдаваться всегда
			*/
			ConstGenerator(const int value);

			/**
			* @brief Выдать константное значение
			*/
			int generate() const override;
	};
}
