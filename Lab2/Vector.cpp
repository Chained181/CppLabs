#include "Vector.h"

template<typename T>
inline Vector<T>::Vector(const Vector<T>& adrs)
{
	this->sizeArray = adrs.sizeArray;
	this->inputArr = new T[sizeArray];

	for (size_t i = 0; i < sizeArray; i++)
	{
		this->inputArr[i] = adrs.inputArr[i];
	}
}

template<typename T>
inline Vector<T>::Vector(int size)
{
	this->sizeArray = size;
	this->inputArr = new T[sizeArray];
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete this->inputArr;
}

template<typename T>
inline inline int Vector<T>::getSize()
{
	return this->sizeArray;
}

template<typename T>
inline T& Vector<T>::operator[](int i) const
{
	return this->inputArr[i];
}

template<typename T>
inline Vector<T>& Vector<T>::operator++()
{
	this->incrementArr();

	return *this;
}

template<typename T>
inline Vector<T>& Vector<T>::operator--()
{
	this->decrementArr();

	return *this;
}

template<typename T>
inline Vector<T> Vector<T>::operator--(int)
{
	Vector<T> temp(*this);

	this->decrementArr();

	return temp;
}

template<typename T>
inline Vector<T> Vector<T>::operator++(int)
{
	Vector<T> temp(*this);

	this->incrementArr();

	return temp;
}

template<typename T>
Vector<T> Vector<T>::getConvertMatrix(Matrix<T> tdArray, const int sizeRow, const int sizeCell)
{
	Vector<T> arr(sizeRow * sizeCell);

	for (int i = 0, k = 0; i < sizeRow; i++)
	{
		for (int j = 0; j < sizeCell; j++)
		{
			arr[k] = tdArray[i][j];
			k++;
		}
	}

	return arr;
}

template<typename T>
inline void Vector<T>::incrementArr()
{
	for (size_t i = 0; i < this->sizeArray; i++)
	{
		this->inputArr[i]++;
	}
}

template<typename T>
inline void Vector<T>::decrementArr()
{
	for (size_t i = 0; i < this->sizeArray; i++)
	{
		this->inputArr[i]--;
	}
}
