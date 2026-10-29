#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
	/**
	* @brief генератор случайных чисел из заданного диапазона
	*/
	class RandomGenerator : public Generator
	{
		private:
			std::uniform_int_distribution<int> distribution;
			std::mt19937 generator;

		public:
			/**
			* @brief конструктор
			* @param min нижняя граница диапазона 
			* @param max верхняя граница диапазона
			*/
			RandomGenerator(const int min, const int max);

			/**
			* @brief выдать случайное число из диапазона [min, max]
			*/
			int generate() override;
	};
}
