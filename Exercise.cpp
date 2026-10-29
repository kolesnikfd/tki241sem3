#include "Exercise.h"

miit::algebra::Exercise::Exercise(Matrix<int>& matrix, Generator& generator)
	: matrix{ matrix }, generator{ generator }
{
}

miit::algebra::Exercise::~Exercise()
{
}

void miit::algebra::Exercise::fillMatrix()
{
	this->matrix.fill(this->generator);
}
