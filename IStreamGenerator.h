#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
	/**
	* @brief генератор который читает числа из входного потока
	*/
	class IStreamGenerator : public Generator
	{
		private:
			std::istream& in;

		public:
			/**
			* @brief конструктор.
			* @param in входной поток
			*/
			IStreamGenerator(std::istream& in = std::cin);

			/**
			* @brief прочитать очередное число из потока
			*/
			int generate() override;
	};
}
