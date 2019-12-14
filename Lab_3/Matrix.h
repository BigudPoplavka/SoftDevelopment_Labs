#pragma once

#include <iostream>
#include <stdio.h>
#include <cstring>


class Matrix
{
private:
	int cols_;
	int rows_;
	double** elem_;


public:
	Matrix();                //empty constructor
								//overload constructors
	Matrix(int cols, int rows);
	Matrix(int cols);
	Matrix(int cols, int rows, double *elem);

	~Matrix();		//destructor

	//overloading operator increment / decrement
	Matrix & operator ++();				//prefix increment form
	Matrix & operator ++(int value);	//postfix increment form
	Matrix & operator --();				//prefix decrement form
	Matrix & operator --(int value);	//postfix decrement form

	//get / set
	int GetCols();		   
	int GetRows();
	int GetLegth();
	double GetElem();
	double GetAt(int i, int j);

	void SetCols(int& cols);		
	void SetRows(int& rows);
	void SetAt(int i, int j, double val);

	//voids
	void PtintMatrix();
};
