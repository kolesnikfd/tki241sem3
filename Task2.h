#pragma once

#include "Exercise.h"

namespace miit::algebra
{
	/**
	* @brief Задание 2
	*/
	class Task2 : public Exercise
	{
		public:
			/**
			* @brief Конструктор
			*/
			Task2(Matrix<int>& matrix, const Generator& generator);

			/**
			* @brief Выполнить задание
			*/
			void solve() override;
	};
}
