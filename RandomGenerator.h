#pragma once

#include "Generator.h"
#include <random>

namespace miit::algebra
{
	/**
	* @brief Генератор случайных чисел из заданного диапазона
	*/
	class RandomGenerator : public Generator
	{
		private:
			mutable std::uniform_int_distribution<int> distribution;
			mutable std::mt19937 generator;

		public:
			/**
			* @brief Конструктор
			* @param min Нижняя граница диапазона 
			* @param max Верхняя граница диапазона 
			*/
			RandomGenerator(const int min, const int max);

			/**
			* @brief Выдать случайное число из диапазона [min, max]
			*/
			int generate() const override;
	};
}
