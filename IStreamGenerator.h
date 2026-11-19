#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
	/**
	* @brief Генератор, который читает числа из входного потока
	*/
	class IStreamGenerator : public Generator
	{
		private:
			std::istream& in;

		public:
			/**
			* @brief Конструктор
			* @param in Входной поток
			*/
			IStreamGenerator(std::istream& in = std::cin);

			/**
			* @brief Прочитать очередное число из потока
			*/
			int generate() const override;
	};
}
