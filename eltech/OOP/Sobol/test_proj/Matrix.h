#pragma once
#include "Vector.h"

class Matrix
{
public:
	Matrix(int _row = 0, int _column = 0, int value = 0);
	Matrix(int _row, int _column, int **matrix);//matrix - ���������� ������, ������ ������ - ������, ������ - �������
	Matrix(int _size, const Vector& vector, bool rows = true);//��������� ������� "�� ��������" ��� "�� �������" - � �� �����, ��� ��� ���� � ������� ��� ����� ����������, ��� ��� ������ ��� �����
				//��� ����� ������ � ������� ������� ��� � ����������� ���������, ������������ � �������� , (���� rows == true)
				//��� � ����������� ���������, � ��������� ������
	Matrix(const Matrix& other);
	~Matrix(void);

	int Column() const;
	int Row() const;

	Vector& operator[](int i);
	Vector operator[](int i) const;
	Matrix& operator=(const Matrix& other);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix operator-() const;
	void operator+=(const Matrix& other);
	void operator-=(const Matrix& other);
	Matrix operator*(const Matrix& other) const;
	Matrix operator~() const;

private:
	int row;
	int column;
	Vector * data;

	Vector get_column(int i) const;
};

ostream& operator<<(ostream& out, const Matrix& matrix); 
