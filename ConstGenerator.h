#pragma once

#include "Generator.h"

namespace miit::algebra
{
	/**
	* @brief генератор который всегда выдаёт одно и то же значение
	*/
	class ConstGenerator : public Generator
	{
		private:
			int value;

		public:
			/**
			* @brief конструктор
			* @param value значение
			*/
			ConstGenerator(const int value);

			/**
			* @brief выдать константное значение
			*/
			int generate() override;
	};
}
