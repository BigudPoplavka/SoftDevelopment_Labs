#include "Matrix.h"

Matrix::Matrix() {}                 //empty constructor
									//overload constructors
Matrix::Matrix(int cols, int rows)
{
	cols_ = cols;
	rows_ = rows;

	elem_ = new double*[rows_];

	for (int i = 0; i < rows_; i++)
		elem_[i] = new double[cols_];

	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
			elem_[i][j] = i * j;
		printf("\n");
	}
}

Matrix::Matrix(int cols)
{
	cols_ = cols;

	elem_ = new double*[cols_];
	//a x a
	for (int i = 0; i < cols_; i++)
		elem_[i] = new double[cols_];
}

Matrix::Matrix(int cols, int rows, double *elem)
{

	*this = Matrix(cols, rows);  //copy matrix

	elem_ = new double*[rows_];
	//ToDo...a x b
	for (int i = 0; i < rows_; i++)
		elem_[i] = new double[cols_];
}

Matrix::~Matrix()       //destructor
{
	for (int i = 0; i < rows_; i++)
		delete[] elem_[i];
	delete[] elem_;
}

//overloading operator increment / decrement 
Matrix & Matrix::operator ++()          
{
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			++(this->elem_[i][j]);
	return *this;
}

Matrix & Matrix::operator ++(int value)       
{
	Matrix temp = (*this);    

	for (int i = 0; i < rows_; i++)
			for (int j = 0; j < cols_; j++)
				this->elem_[i][j]++;
	return temp;
}

Matrix & Matrix::operator --()          
{
	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			--(this->elem_[i][j]);
	return *this;
}

Matrix & Matrix::operator --(int value)          
{
	Matrix temp = (*this);

	for (int i = 0; i < rows_; i++)
		for (int j = 0; j < cols_; j++)
			this->elem_[i][j]--;	
	return temp;
}


//get / set 
int Matrix::GetCols() { return cols_; }
int Matrix::GetRows() { return rows_; }
int Matrix::GetLegth() { return cols_ * rows_; }
double Matrix::GetElem() { return **elem_; }
double Matrix::GetAt(int i, int j)
{
	return elem_[i][j];
}
   
void Matrix::SetCols(int& cols) { cols_ = cols; }
void Matrix::SetRows(int& rows) { rows_ = rows; }

void Matrix::SetAt(int i, int j, double val)
{
	elem_[i][j] = val;
}

//voids
void Matrix::PtintMatrix()
{
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
			std::cout << elem_[i][j] << " ";
		printf("\n");
	}

	std::cout << "Rows: " << rows_ << std::endl;
	std::cout << "Cols: " << cols_ << std::endl;
}