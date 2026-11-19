#pragma once

#include "Generator.h"
#include "Matrix.h"

namespace miit::algebra
{
	/**
	* @brief Базовый класс задания. Агрегирует матрицу и генератор
	*        Конкретное решение пишется в наследниках в методе solve()
	*/
	class Exercise
	{
		protected:
			Matrix<int>& matrix;
			const Generator& generator;

		public:
			/**
			* @brief Конструктор
			* @param matrix Матрица, с которой работает задание
			* @param generator Генератор, которым заполняется матрица
			*/
			Exercise(Matrix<int>& matrix, const Generator& generator);

			/**
			* @brief Виртуальный деструктор
			*/
			virtual ~Exercise();

			/**
			* @brief Заполнить матрицу числами из генератора
			*/
			void fillMatrix();

			/**
			* @brief Выполнить задание
			*/
			virtual void solve() = 0;
	};
}
