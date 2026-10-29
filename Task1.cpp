#include "Task1.h"

miit::algebra::Task1::Task1(Matrix<int>& matrix, Generator& generator)
	: Exercise(matrix, generator)
{
}

void miit::algebra::Task1::solve()
{
	for (int j = 0; j < this->matrix.getCols(); j++)
	{
		for (int i = 0; i < this->matrix.getRows(); i++)
		{
			if (this->matrix[i][j] % 3 == 0)
			{
				this->matrix[i][j] = 0;
			}
		}
	}
}
