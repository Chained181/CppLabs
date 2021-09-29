#include <iostream>

using namespace std;

#include "Header.h"
#include "SecondQuestion.h"

void main()
{
    const unsigned int nRows = 5;
    const unsigned int nCols = 5;

    int** aArr2D = new int* [nRows];
    for (int i = 0; i < nRows; i++)
    {
        *(aArr2D + i) = new int[nCols];
    }

    initialization_array_2D(aArr2D, nRows, nCols);

    int factorial(int x);

    print_array_2D(aArr2D, nRows, nCols);

    const unsigned int SIZE = 15;

    int* arr1D = array_1D(aArr2D, SIZE, nRows, nCols);

    print_array_1D(arr1D, SIZE);

    cin.get();
}
