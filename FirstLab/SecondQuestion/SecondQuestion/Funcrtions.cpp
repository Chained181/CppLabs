#include <iostream>

using namespace std;

#include "Header.h"

void initialization_array_2D(int** arr, int nRows, int nCols)
{

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {

            *(*(arr + i) + j) = factorial(j + i);
        }
    }

}

int factorial(int x)
{
    if (x < 0)
        return 0;
    if (x == 0)
        return 1;
    return x * factorial(x - 1);
}

void print_array_2D(int** arr, int nRows, int nCols)
{
    cout << "2D array" << endl;

    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int* array_1D(int** arr, int SIZE, int N, int M)
{
    int size = M * (N / 2);

    int* arr1D = new int[size];
    int index = 0;

    for (int i = 0; i < N; i +=2) {
        for (int j = 0; j < M; j ++) {
            arr1D[index++] = arr[i][j];
        }
         
    }
        

    return arr1D;
}

void print_array_1D(int* arr1D, unsigned int SIZE)
{
    cout << endl << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << arr1D[i] << " ";
    }

}