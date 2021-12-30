#include "Matrix.h"


template<typename T>
inline Matrix<T>::Matrix(const Matrix<T>& adrsMatrix)
{

	this->rows = adrsMatrix.rows;
	this->cells = adrsMatrix.cells;

	this->sourceArray = new T * [rows];

	for (size_t i = 0; i < rows; i++)
	{
		sourceArray[i] = new T[cells];
	}

	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cells; j++)
		{
			this->sourceArray[i][j] = adrsMatrix.sourceArray[i][j];
		}
	}
}

template<typename T>
inline int Matrix<T>::getRows()
{
	return this->rows;
}

template<typename T>
inline int Matrix<T>::getCells()
{
	return this->cells;
}

template<typename T>
Matrix<T> Matrix<T>::getMatrix(const int sizeRow, const int sizeCell)
{
		Matrix<T> tdArray(sizeRow, sizeCell);

		for (size_t i = 0; i < sizeRow; i++)
		{
			for (size_t j = 0; j < sizeCell; j++)
			{
				tdArray[i][j] = sqrtf(i + j + 1);
			}
		}

		return tdArray;

}

template<typename T>
inline Matrix<T>::Matrix(int rows, int cells)
{
	this->cells = cells;
	this->rows = rows;

	this->sourceArray = new T * [rows];

	for (size_t i = 0; i < rows; i++)
	{
		sourceArray[i] = new T[cells];
	}
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	Clear();
}

template<typename T>
inline T*& Matrix<T>::operator[](int i) const
{
	return this->sourceArray[i];
}


template<typename T>
inline Matrix<T>& Matrix<T>::operator++()
{
	this->incrementArr();

	return *this;
}

template<typename T>
inline Matrix<T>& Matrix<T>::operator--()
{
	this->decrementArr();

	return *this;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator--(int)
{
	Matrix<T> temp(*this);

	this->decrementArr();

	return temp;
}

template<typename T>
inline Matrix<T> Matrix<T>::operator++(int)
{
	Matrix<T> temp(*this);

	this->incrementArr();

	return temp;
}


template<typename T>
inline void Matrix<T>::incrementArr()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cells; j++)
		{
			this->sourceArray[i][j]++;
		}
	}
}

template<typename T>
inline void Matrix<T>::decrementArr()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cells; j++)
		{
			this->sourceArray[i][j]--;
		}
	}
}