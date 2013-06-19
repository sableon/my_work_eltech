#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(int _size = 0, int _value = 0);
	Vector(int _size, int * massive);
	Vector(const Vector& other);
	~Vector(void);

	int Size() const;
	int& operator[](int i);
	int operator[](int i) const;
	Vector& operator=(const Vector& other);
	Vector operator+(const Vector& other) const;
	void operator +=(const Vector& other);
	Vector operator-() const;
	Vector operator-(const Vector& other) const;
	void operator -=(const Vector& other);
	int operator*(const Vector& other) const;
	float operator()(void) const;

private:
	int size;
	int * data;
};

ostream& operator<<(ostream& out, const Vector& vector);
