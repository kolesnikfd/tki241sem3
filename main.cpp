#include "Matrix.h"
#include "Generator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "ConstGenerator.h"
#include "Task1.h"
#include "Task2.h"

#include <iostream>
#include <memory>

using namespace miit::algebra;

enum class FillMode
{
	Random = 1,
	Keyboard = 2,
	Zeros = 3,
	Constant = 4
};

void printMatrix(const std::string& title, const Matrix<int>& matrix)
{
	std::cout << title << std::endl;
	if (matrix.getRows() == 0)
	{
		std::cout << "(пустая матрица)" << std::endl;
	}
	else
	{
		std::cout << matrix << std::endl;
	}
}

void printMenu()
{
	std::cout << "Как заполнить матрицу?" << std::endl;
	std::cout << static_cast<int>(FillMode::Random) << " - случайными числами" << std::endl;
	std::cout << static_cast<int>(FillMode::Keyboard) << " - с клавиатуры" << std::endl;
	std::cout << static_cast<int>(FillMode::Zeros) << " - нулями" << std::endl;
	std::cout << static_cast<int>(FillMode::Constant) << " - одним и тем же числом" << std::endl;
}

std::unique_ptr<Generator> chooseGenerator()
{
	printMenu();

	int choice = 0;
	std::cin >> choice;

	switch (static_cast<FillMode>(choice))
	{
		case FillMode::Random:
		{
			int min = 0;
			int max = 0;
			std::cout << "Введите границы диапазона (min max): ";
			std::cin >> min >> max;
			return std::make_unique<RandomGenerator>(min, max);
		}
		case FillMode::Keyboard:
		{
			std::cout << "Числа будете вводить по строкам, через пробел или Enter" << std::endl;
			return std::make_unique<IStreamGenerator>(std::cin);
		}
		case FillMode::Constant:
		{
			int value = 0;
			std::cout << "Введите число: ";
			std::cin >> value;
			return std::make_unique<ConstGenerator>(value);
		}
		case FillMode::Zeros:
		default:
		{
			return std::make_unique<ZeroGenerator>();
		}
	}
}

int main()
{
	int n = 0;
	int m = 0;
	std::cout << "Введите количество строк n и столбцов m: ";
	std::cin >> n >> m;

	if (n <= 0 || m <= 0)
	{
		std::cout << "Размеры должны быть положительными" << std::endl;
		return 1;
	}

	Matrix<int> matrix(static_cast<size_t>(n), static_cast<size_t>(m));
	std::unique_ptr<Generator> generator = chooseGenerator();

	Task1 task1(matrix, *generator);
	Task2 task2(matrix, *generator);

	task1.fillMatrix();
	printMatrix("\nИсходная матрица:", matrix);

	task1.solve();
	printMatrix("После задания 1 (кратные трём заменены нулём):", matrix);

	task2.solve();
	printMatrix("После задания 2 (удалены строки, где 2-й элемент > предпоследнего):", matrix);

	Matrix<int> copy = matrix;
	Matrix<int> other;
	other = copy;
	printMatrix("Копия итоговой матрицы:", other);

	return 0;
}
