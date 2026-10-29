#pragma once

#include "Exercise.h"

namespace miit::algebra
{
	/**
	* @brief задание 2: удалить все строки в которых
	*        второй элемент больше предпоследнего
	*/
	class Task2 : public Exercise
	{
		public:
			/**
			* @brief конструктор
			*/
			Task2(Matrix<int>& matrix, Generator& generator);

			/**
			* @brief выполнить задание
			*/
			void solve() override;
	};
}
