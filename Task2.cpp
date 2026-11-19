#include "Task2.h"

miit::algebra::Task2::Task2(Matrix<int>& matrix, const Generator& generator)
	: Exercise(matrix, generator)
{
}

void miit::algebra::Task2::solve()
{
	size_t cols = this->matrix.getCols();

	if (cols < 2)
	{
		return;
	}

	for (size_t i = this->matrix.getRows(); i > 0; i--)
	{
		size_t row = i - 1;
		int second = this->matrix[row][1];
		int beforeLast = this->matrix[row][cols - 2];

		if (second > beforeLast)
		{
			this->matrix.removeRow(row);
		}
	}
}
