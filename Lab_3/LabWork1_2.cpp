#include "pch.h"
#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>

//	EXE 2
/* Преобразование: 2D → 1D. Двумерный массив 5х3 вещественных чисел необходимо
выложить в один ряд по элементам по столбцам сверху вниз.
Инициализация: заполнить массив числами x[i][j] = sin(i – j) + cos(i + j).
Вывод на экран : на каждый элемент массива отвести 10 позиций.
*/

void OutputArray(double* arr, size_t arr_size)
{
	for (int i = 0; i < arr_size; i++) std::cout << 
    " | " << arr[i] ;
}


void InitializeArray(double** arr, size_t size_i, size_t size_j)
{
   
    for(int i = 0; i < size_i; i++)
        arr[i] = new double[size_j]; //one cell = new array

	for(int i = 0; i < size_i; i++)
        for(int j = 0; j < size_j; j++){
            arr[i][j] = sin(i - j) + cos(i + j);
            if(j < 2) std::cout << "|" << std::setw(10) << arr[i][j];
            else if(j == 2) std::cout << "|" << std::setw(10) << arr[i][j] << std::endl;
        }
}


double* Array_ToOneD(double** arr2D, double* arr1D, size_t size_i, size_t size_j)
{
    std::cout << " " << std:: endl;
    int count_step = 0;
    arr1D = new double[size_i * size_j];

    for(int i = 0; i < size_j; i++)
        for(int j = 0; j < size_i; j++)
        {
            *(arr1D + count_step++) = arr2D[j][i];
             count_step++;
        }

	return arr1D;
}


int main()
{
	int x = 5;
	int y = 3;
    
    double* arr = new double[x * y];
	double** d_arr = new double*[x];
	for(int i = 0; i < x; i++)
		d_arr[i] = new double[y];

		InitializeArray(d_arr, 5, 3);
		OutputArray(Array_ToOneD(d_arr, arr, 5, 3), x * y);

    //memory cleaning
	for(int i = 0; i < x; i++)
        delete[] d_arr[i];
    delete[] d_arr;
}
