#pragma once

#include "Generator.h"
#include "Matrix.h"

namespace miit::algebra
{
	/**
	* @brief базовый класс задания. агрегирует матрицу и генератор
	*/
	class Exercise
	{
		protected:
			Matrix<int>& matrix;
			Generator& generator;

		public:
			/**
			* @brief конструктор
			* @param matrix матрица с которой работает задание
			* @param generator генератор которым заполняется матрица
			*/
			Exercise(Matrix<int>& matrix, Generator& generator);

			/**
			* @brief виртуальный деструктор
			*/
			virtual ~Exercise();

			/**
			* @brief заполнить матрицу числами из генератора
			*/
			void fillMatrix();

			/**
			* @brief выполнить задание
			*/
			virtual void solve() = 0;
	};
}
