#pragma once
#include <math.h>
template<typename T>
class Matrix
{
private:
	int rows;
	int cells;
	T** sourceArray;

	void incrementArr();
	void decrementArr();
	
	void Clear() noexcept
	{
		for (size_t i = 0; i < this->cells; i++)
		{
			delete[] this->sourceArray[i];
		}

		delete[] this->sourceArray;
	}


public:
	Matrix(int rows, int cells); 
	Matrix(const Matrix<T>& adrsMatrix);
	~Matrix();
	T*& operator[](int i) const;
	static Matrix<T> getMatrix(const int sizeRow, const int sizeCell);
	//pre-increment
	Matrix<T>& operator++();
	Matrix<T>& operator--();

	//post-increment
	Matrix<T> operator--(int);
	Matrix<T> operator++(int);

	int getRows();
	int getCells();
};
