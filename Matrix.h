#pragma once

#include "Generator.h"
#include <cstddef>
#include <istream>
#include <ostream>
#include <string>
#include <vector>

namespace miit::algebra
{
	/**
	* @brief Шаблонный класс двумерного массива
	*        Данные хранятся в vector из строк 
	*        Класс не работает с вводом-выводом напрямую: для вывода есть toString()
	* @tparam T Тип элементов
	*/
	template <typename T>
	class Matrix
	{
		private:
			std::vector<std::vector<T>> data;

		public:
			/**
			* @brief Конструктор по умолчанию
			*/
			Matrix();

			/**
			* @brief Конструктор матрицы заданного размера 
			* @param rows Количество строк
			* @param cols Количество столбцов
			*/
			Matrix(const size_t rows, const size_t cols);

			/**
			* @brief Конструктор копирования
			*/
			Matrix(const Matrix& other);

			/**
			* @brief Конструктор перемещения
			*/
			Matrix(Matrix&& other) noexcept;

			/**
			* @brief Деструктор
			*/
			~Matrix();

			/**
			* @brief Оператор копирующего присваивания
			*/
			Matrix& operator=(const Matrix& other);

			/**
			* @brief Оператор перемещающего присваивания
			*/
			Matrix& operator=(Matrix&& other) noexcept;

			/**
			* @brief Количество строк
			*/
			size_t getRows() const;

			/**
			* @brief Количество столбцов
			*/
			size_t getCols() const;

			/**
			* @brief Доступ к строке по индексу
			*        При неверном индексе бросает std::out_of_range
			*/
			std::vector<T>& operator[](const size_t row);

			/**
			* @brief Доступ к строке по индексу для константной матрицы
			*/
			const std::vector<T>& operator[](const size_t row) const;

			/**
			* @brief Заполнить матрицу числами из генератора
			* @param generator Генератор, выдающий числа
			*/
			void fill(const Generator& generator);

			/**
			* @brief Удалить строку по индексу
			*/
			void removeRow(const size_t row);

			/**
			* @brief Представить матрицу в виде строки
			*/
			std::string toString() const;
	};

	/**
	* @brief Оператор сдвига влево: вывод матрицы в выходной поток
	*/
	template <typename T>
	std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);

	/**
	* @brief Оператор сдвига вправо: чтение элементов матрицы из входного потока
	*        Размер матрицы должен быть задан заранее
	*/
	template <typename T>
	std::istream& operator>>(std::istream& in, Matrix<T>& matrix);
}

#include "Matrix.cpp"
