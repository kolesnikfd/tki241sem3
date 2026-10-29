#include "Matrix.h"
#include "ConstGenerator.h"
#include "ZeroGenerator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "Task1.h"
#include "Task2.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace miit::algebra;

int failed = 0;
int total = 0;

// Простая проверка: выводит сообщение, если условие ложно
void check(bool condition, const std::string& name)
{
	total++;
	if (!condition)
	{
		failed++;
		std::cout << "[FAIL] " << name << std::endl;
	}
	else
	{
		std::cout << "[ OK ] " << name << std::endl;
	}
}

// Создать матрицу 3x4 из набора чисел (по строкам)
Matrix<int> makeMatrix(int rows, int cols, const int* values)
{
	Matrix<int> matrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = values[i * cols + j];
		}
	}
	return matrix;
}

void testMatrix()
{
	Matrix<int> empty;
	check(empty.getRows() == 0 && empty.getCols() == 0, "Matrix: конструктор по умолчанию");

	Matrix<int> a(2, 3);
	check(a.getRows() == 2 && a.getCols() == 3, "Matrix: размеры");
	check(a[1][2] == 0, "Matrix: начальные значения нулевые");

	a[0][1] = 7;
	Matrix<int> b = a;
	b[0][1] = 5;
	check(a[0][1] == 7 && b[0][1] == 5, "Matrix: копирование независимо");

	Matrix<int> c;
	c = a;
	check(c[0][1] == 7, "Matrix: оператор присваивания");

	Matrix<int> d = std::move(c);
	check(d[0][1] == 7 && c.getRows() == 0, "Matrix: перемещение");

	bool thrown = false;
	try
	{
		a[5][0] = 1;
	}
	catch (const std::out_of_range&)
	{
		thrown = true;
	}
	check(thrown, "Matrix: выход за границы бросает исключение");

	Matrix<int> e(1, 2);
	e[0][0] = 1;
	e[0][1] = 2;
	check(e.toString() == "1\t2\t\n", "Matrix: toString");

	std::ostringstream out;
	out << e;
	check(out.str() == "1\t2\t\n", "Matrix: оператор <<");

	std::istringstream in("8 9");
	in >> e;
	check(e[0][0] == 8 && e[0][1] == 9, "Matrix: оператор >>");

	Matrix<int> f(3, 1);
	f[0][0] = 1;
	f[1][0] = 2;
	f[2][0] = 3;
	f.removeRow(1);
	check(f.getRows() == 2 && f[1][0] == 3, "Matrix: removeRow");
}

void testGenerators()
{
	Matrix<int> matrix(2, 2);

	ConstGenerator constGen(4);
	matrix.fill(constGen);
	check(matrix[0][0] == 4 && matrix[1][1] == 4, "ConstGenerator");

	ZeroGenerator zeroGen;
	matrix.fill(zeroGen);
	check(matrix[0][1] == 0 && matrix[1][0] == 0, "ZeroGenerator");

	RandomGenerator randomGen(-5, 5);
	matrix.fill(randomGen);
	bool inRange = true;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (matrix[i][j] < -5 || matrix[i][j] > 5)
			{
				inRange = false;
			}
		}
	}
	check(inRange, "RandomGenerator: числа в диапазоне");

	std::istringstream in("1 2 3 4");
	IStreamGenerator streamGen(in);
	matrix.fill(streamGen);
	check(matrix[0][0] == 1 && matrix[0][1] == 2 && matrix[1][0] == 3 && matrix[1][1] == 4,
		"IStreamGenerator");
}

void testTask1()
{
	ZeroGenerator generator;
	int values[] = { 3, 4, -6, 7,
	                 5, 9, 10, 0,
	                 -3, 1, 12, 8 };
	Matrix<int> matrix = makeMatrix(3, 4, values);

	Task1 task(matrix, generator);
	task.solve();

	int expected[] = { 0, 4, 0, 7,
	                   5, 0, 10, 0,
	                   0, 1, 0, 8 };
	Matrix<int> result = makeMatrix(3, 4, expected);
	check(matrix.toString() == result.toString(), "Task1: кратные трём заменены нулями");
}

void testTask2()
{
	ZeroGenerator generator;

	// Строка 0: 2-й = 9, предпоследний = 3  -> удалить
	// Строка 1: 2-й = 1, предпоследний = 5  -> оставить
	// Строка 2: 2-й = 4, предпоследний = 4  -> оставить (не больше)
	int values[] = { 1, 9, 3, 0,
	                 2, 1, 5, 0,
	                 7, 4, 4, 1 };
	Matrix<int> matrix = makeMatrix(3, 4, values);

	Task2 task(matrix, generator);
	task.solve();

	check(matrix.getRows() == 2, "Task2: количество оставшихся строк");
	check(matrix[0][0] == 2 && matrix[1][0] == 7, "Task2: остались нужные строки");

	// Все строки удаляются подряд
	int values2[] = { 0, 5, 1, 0,
	                  0, 6, 2, 0 };
	Matrix<int> matrix2 = makeMatrix(2, 4, values2);
	Task2 task2(matrix2, generator);
	task2.solve();
	check(matrix2.getRows() == 0, "Task2: удаление всех строк");

	// Один столбец - ничего не делаем
	Matrix<int> matrix3(2, 1);
	Task2 task3(matrix3, generator);
	task3.solve();
	check(matrix3.getRows() == 2, "Task2: один столбец, матрица не меняется");
}

int main()
{
	testMatrix();
	testGenerators();
	testTask1();
	testTask2();

	std::cout << "\nПройдено: " << (total - failed) << " из " << total << std::endl;
	return failed == 0 ? 0 : 1;
}
