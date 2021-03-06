#include <iostream>
using namespace std;
#pragma once

//Преобразование: 2D → 1D.Двумерный массив 5х5 целых чисел необходимо выложить
//в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
//четных строках.
//Инициализация : заполнить массив факториалами : x[i][j] = (i + j)!.
//Вывод на экран : на каждый элемент массива отвести 8 позиций.


void initialization_array_2D(int** arr, int nRows, int nCols);
int factorial(int x);
void print_array_2D(int** arr, int nRows, int nCols);
int* array_1D(int** arr, int SIZE, int N, int M);
void print_array_1D(int* arr1D, unsigned int SIZE);
void FreeArray1D(int* array_1D, int SIZE) {
    for (int i = 0; i < SIZE; i++){ 
        delete[] &array_1D[i]; 
    }
    delete[] array_1D;
    cout<<"Matrix deleted" << endl;
}
void FreeArray2D(int** aArr2D, int nRows) {
    for (int i = 0; i < nRows; i++)
        delete[] aArr2D[i];

    delete[] aArr2D;
    cout <<"Matrix deleted" << endl;
}



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
    FreeArray1D(arr1D, SIZE);
    FreeArray2D(aArr2D, nRows);
    print_array_2D(aArr2D, nRows, nCols);
    cin.get();
}


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

    for (int i = 0; i < N; i += 2) {
        for (int j = 0; j < M; j++) {
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
