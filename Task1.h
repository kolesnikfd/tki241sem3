#pragma once

#include "Exercise.h"

namespace miit::algebra
{
	/**
	* @brief задание 1: заменить нулём элементы,
	*        кратные трём, в каждом столбце матрицы
	*/
	class Task1 : public Exercise
	{
		public:
			/**
			* @brief конструктор
			*/
			Task1(Matrix<int>& matrix, Generator& generator);

			/**
			* @brief выполнить задание
			*/
			void solve() override;
	};
}
