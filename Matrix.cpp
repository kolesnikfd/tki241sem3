#pragma once

#include "Matrix.h"
#include <stdexcept>
#include <utility>

template <typename T>
miit::algebra::Matrix<T>::Matrix()
{
}

template <typename T>
miit::algebra::Matrix<T>::Matrix(const int rows, const int cols)
	: data(rows, std::vector<T>(cols))
{
}

template <typename T>
miit::algebra::Matrix<T>::Matrix(const Matrix& other)
	: data(other.data)
{
}

template <typename T>
miit::algebra::Matrix<T>::Matrix(Matrix&& other) noexcept
	: data(std::move(other.data))
{
}

template <typename T>
miit::algebra::Matrix<T>::~Matrix()
{
}

template <typename T>
miit::algebra::Matrix<T>& miit::algebra::Matrix<T>::operator=(const Matrix& other)
{
	if (this != &other)
	{
		this->data = other.data;
	}
	return *this;
}

template <typename T>
miit::algebra::Matrix<T>& miit::algebra::Matrix<T>::operator=(Matrix&& other) noexcept
{
	if (this != &other)
	{
		this->data = std::move(other.data);
	}
	return *this;
}

template <typename T>
int miit::algebra::Matrix<T>::getRows() const
{
	return static_cast<int>(this->data.size());
}

template <typename T>
int miit::algebra::Matrix<T>::getCols() const
{
	if (this->data.empty())
	{
		return 0;
	}
	return static_cast<int>(this->data[0].size());
}

template <typename T>
std::vector<T>& miit::algebra::Matrix<T>::operator[](const int row)
{
	return this->data.at(row);
}

template <typename T>
const std::vector<T>& miit::algebra::Matrix<T>::operator[](const int row) const
{
	return this->data.at(row);
}

template <typename T>
void miit::algebra::Matrix<T>::fill(Generator& generator)
{
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			this->data[i][j] = static_cast<T>(generator.generate());
		}
	}
}

template <typename T>
void miit::algebra::Matrix<T>::removeRow(const int row)
{
	if (row < 0 || row >= this->getRows())
	{
		throw std::out_of_range("Matrix::removeRow: неверный номер строки");
	}
	this->data.erase(this->data.begin() + row);
}

template <typename T>
std::string miit::algebra::Matrix<T>::toString() const
{
	std::string result;
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			result += std::to_string(this->data[i][j]);
			result += "\t";
		}
		result += "\n";
	}
	return result;
}

template <typename T>
std::ostream& miit::algebra::operator<<(std::ostream& out, const Matrix<T>& matrix)
{
	out << matrix.toString();
	return out;
}

template <typename T>
std::istream& miit::algebra::operator>>(std::istream& in, Matrix<T>& matrix)
{
	for (int i = 0; i < matrix.getRows(); i++)
	{
		for (int j = 0; j < matrix.getCols(); j++)
		{
			in >> matrix[i][j];
		}
	}
	return in;
}
