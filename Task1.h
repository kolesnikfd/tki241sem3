#pragma once

#include "Exercise.h"

namespace miit::algebra
{
	/**
	* @brief Задание 1 
	*/
	class Task1 : public Exercise
	{
		public:
			/**
			* @brief Конструктор
			*/
			Task1(Matrix<int>& matrix, const Generator& generator);

			/**
			* @brief Выполнить задание
			*/
			void solve() override;
	};
}
