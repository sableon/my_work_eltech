#include "Matrix.h"

Matrix::Matrix(int _row, int _column, int value)
{
	if(_row < 0)
		_row = 0;
	if(_column < 0)
		_column = 0;
	if(_row * _column == 0)
	{
		data = 0;
		row = 0;
		column = 0;
	}
	else
	{
		row = _row;
		column = _column;
		data = new Vector[row];
		for(int i = 0; i < row; ++i)
			data[i] = Vector(column,value);
	}
}
Matrix::Matrix(int _row, int _column, int **matrix)
{
	if(_row < 0)
		_row = 0;
	if(_column < 0)
		_column = 0;
	if(_row * _column == 0)
	{
		data = 0;
		row = 0;
		column = 0;
	}
	else
	{
		row = _row;
		column = _column;
		data = new Vector[row];
		for(int i = 0; i < row; ++i)
			data[i] = Vector(column,matrix[i]);
	}
}

Matrix::Matrix(int size, const Vector& vector, bool rows)
{
	if(size < 0)
		size = 0;
	if(vector.Size() * size == 0)
	{
		row = 0;
		column = 0;
		data = 0;
	}
	else
	{
		if(rows)
		{
			row = size;
			column = vector.Size();
			data = new Vector[row];
			for(int i = 0; i < row; ++i)
				data[i] = vector;
		}
		else
		{
			column = size;
			row = vector.Size();
			data = new Vector[row];
			for(int i = 0; i < row; ++i)
				data[i] = Vector(column,vector[i]);
		}
	}
}
Matrix::Matrix(const Matrix& other)
{
	row = other.row;
	column = other.column;
	data = new Vector[row];
	for(int i = 0; i < row; ++i)
		data[i] = other.data[i];
}
Matrix::~Matrix(void)
{
	if(data != 0)
		for(int i = 0; i < row; ++i)
			data[i].~Vector();
}

int Matrix::Column() const
{
	return column;
}
int Matrix::Row() const
{
	return row;
}
Vector Matrix::get_column(int i) const
{
	Vector *res = new Vector(row);
	for(int j = 0; j < row; ++j)
		(*res)[j] = this->data[j][i];
	return *res;
}
Vector& Matrix::operator[](int i)
{
	if(i >= 0 && i < row)
	{
		return data[i];
	}
	Vector *empty = new Vector();
	return *empty;
}
Vector Matrix::operator[](int i) const
{
	if(i >= 0 && i < row)
	{
		return data[i];
	}
	Vector *empty = new Vector();
	return *empty;
}
Matrix& Matrix::operator=(const Matrix& other)
{
	this->row = other.row;
	this->column = other.column;
	if(this->data != 0)
		for(int i = 0; i < row; ++i)
			data[i].~Vector();
	data = new Vector[row];
	for(int i = 0; i < row; ++i)
		data[i] = other.data[i];
	return *this;
}
Matrix Matrix::operator+(const Matrix& other) const
{
	if(this->row != other.row || this->column != other.column)
		return Matrix();
	Matrix *res = new Matrix(*this);
	for(int i = 0; i < row; ++i)
		res->data[i] += other.data[i];
	return *res;
}
Matrix Matrix::operator-(const Matrix& other) const
{
	if(this->row != other.row || this->column != other.column)
		return Matrix();
	Matrix *res = new Matrix(*this);
	for(int i = 0; i < row; ++i)
		res->data[i] -= other.data[i];
	return *res;
}
Matrix Matrix::operator-() const
{
	Matrix *res = new Matrix(*this);
	for(int i = 0; i < row; ++i)
		res->data[i]  = -res->data[i];
	return *res;
}
void Matrix::operator+=(const Matrix& other)
{
	if(this->row != other.row || this->column != other.column)
		return ;
	for(int i = 0; i < row; ++i)
		this->data[i] += other.data[i];
}
void Matrix::operator-=(const Matrix& other)
{
	if(this->row != other.row || this->column != other.column)
		return ;
	for(int i = 0; i < row; ++i)
		this->data[i] -= other.data[i];
}
Matrix Matrix::operator*(const Matrix& other) const
{
	if(this->column != other.row)
		return Matrix();
	Matrix *res = new Matrix(this->row,other.column);
	for(int i = 0; i < this->row; ++i)
		for(int j = 0; j < other.column; ++j)
		{
			res->data[i][j] = (this->data[i]) * (other.get_column(j));
		}
	return *res;
}
Matrix Matrix::operator~() const
{
	if(this->row * this->column == 0)
		return Matrix();
	Matrix * res = new Matrix(column,row);
	for(int i = 0; i < column; ++i)
		for(int j = 0; j < row; ++j)
			res->data[i][j] = this->data[j][i];
	return *res;
}
ostream& operator<<(ostream& out, const Matrix& matrix)
{
	out << endl;
	for(int i = 0; i < matrix.Row(); ++i)
		out << matrix[i] << endl;
	out << endl;
	return out;
}