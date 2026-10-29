#pragma once

#include "Generator.h"
#include <istream>
#include <ostream>
#include <string>
#include <vector>

namespace miit::algebra
{
	/**
	* @brief шаблонный класс двумерного массива
	*        данные хранятся в vector из строк
	*        класс не работает с вводом-выводом напрямую для вывода есть toString()
	* @tparam T Тип элементов
	*/
	template <typename T>
	class Matrix
	{
		private:
			std::vector<std::vector<T>> data;

		public:
			/**
			* @brief конструктор по умолчанию
			*/
			Matrix();

			/**
			* @brief конструктор матрицы заданного размера
			* @param rows количество строк
			* @param cols количество столбцов
			*/
			Matrix(const int rows, const int cols);

			/**
			* @brief конструктор копирования
			*/
			Matrix(const Matrix& other);

			/**
			* @brief конструктор перемещения
			*/
			Matrix(Matrix&& other) noexcept;

			/**
			* @brief деструктор
			*/
			~Matrix();

			/**
			* @brief оператор копирующего присваивания
			*/
			Matrix& operator=(const Matrix& other);

			/**
			* @brief оператор перемещающего присваивания
			*/
			Matrix& operator=(Matrix&& other) noexcept;

			/**
			* @brief количество строк
			*/
			int getRows() const;

			/**
			* @brief количество столбцов
			*/
			int getCols() const;

			/**
			* @brief доступ к строке по индексу
			*        при неверном индексе бросает std::out_of_range
			*/
			std::vector<T>& operator[](const int row);

			/**
			* @brief доступ к строке по индексу для константной матрицы
			*/
			const std::vector<T>& operator[](const int row) const;

			/**
			* @brief Заполнить матрицу числами из генератора
			* @param generator генератор выдающий числа.
			*/
			void fill(Generator& generator);

			/**
			* @brief удалить строку по индексу
			*/
			void removeRow(const int row);

			/**
			* @brief представить матрицу в виде строки
			*/
			std::string toString() const;
	};

	/**
	* @brief оператор сдвига влево: вывод матрицы в выходной поток
	*/
	template <typename T>
	std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix);

	/**
	* @brief оператор сдвига вправо: чтение элементов матрицы из входного потока
	*        размер матрицы должен быть задан заранее
	*/
	template <typename T>
	std::istream& operator>>(std::istream& in, Matrix<T>& matrix);
}

// Реализация шаблона должна быть видна компилятору вместе с объявлением,
// поэтому файл Matrix.cpp подключается в конце заголовка
#include "Matrix.cpp"
