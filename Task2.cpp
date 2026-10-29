#include "Task2.h"

miit::algebra::Task2::Task2(Matrix<int>& matrix, Generator& generator)
	: Exercise(matrix, generator)
{
}

void miit::algebra::Task2::solve()
{
	int cols = this->matrix.getCols();

	if (cols < 2)
	{
		return;
	}

	for (int i = this->matrix.getRows() - 1; i >= 0; i--)
	{
		int second = this->matrix[i][1];
		int beforeLast = this->matrix[i][cols - 2];

		if (second > beforeLast)
		{
			this->matrix.removeRow(i);
		}
	}
}
