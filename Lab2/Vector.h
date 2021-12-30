#pragma once
#include "Matrix.h"
template<typename T>
class Vector {
private:
	T* inputArr;
	int sizeArray;



	void incrementArr();
	void decrementArr();

public:
	//ctor deep copy
	Vector(const Vector<T> &adrs);
	Vector(int size);
	~Vector();

	int getSize();

	T& operator [](int i) const;

	//pre-increment
	Vector<T>& operator++();
	Vector<T>& operator--();

	//post-increment
	Vector<T> operator--(int);
	Vector<T> operator++(int);

	static Vector<T> getConvertMatrix(Matrix<T> tdArray, const int sizeRow, const int sizeCell);
};