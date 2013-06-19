#include "Vector.h"

Vector::Vector(int _size, int _value)
{
	if(_size <= 0)
	{
		size = 0;
		data = 0;
	}
	else
	{
		size = _size;
		data = new int[size];
		for(int i = 0; i < size; ++i)
			data[i] = _value;
	}
}
Vector::Vector(const Vector& other)
{
	this->size = other.size;
	this->data = new int[this->size];
	for(int i = 0; i < size; ++i)
		this->data[i] = other.data[i];
}

Vector::Vector(int _size, int * massive)
{
	if(_size <= 0)
	{
		this->size = 0;
		this->data = 0;
	}
	else
	{
		this->size = _size;
		this->data = new int[size];
		for(int i = 0; i < size; ++i)
			data[i] = massive[i];
	}
}

Vector::~Vector(void)
{
	if(data != 0)
		delete data;
}

int Vector::Size() const
{
	return size;
}
int& Vector::operator[](int i)
{
	if(i >=0 && i < size)
		return data[i];
	int* empty = new int(0);
	return *empty;
}
int Vector::operator[](int i) const
{
	if(i >=0 && i < size)
		return data[i];
	int* empty = new int(0);
	return *empty;
}
Vector& Vector::operator=(const Vector& other)
{
	this->size = other.size;
	if(this->data != 0)
		delete this->data;
	this->data = new int[this->size];
	for(int i = 0; i < size; ++i)
		this->data[i] = other.data[i];
	return *this;
}
Vector Vector::operator+(const Vector& other) const
{
	if(this->size != other.size)
		return *(new Vector());
	Vector *res = new Vector(other);
	for(int i = 0; i < size; ++i)
		res->data[i] += this->data[i];
	return *res;
}
void Vector::operator +=(const Vector& other)
{
	if(this->size != other.size)
		return;
	for(int i = 0; i < size; ++i)
		this->data[i] += other.data[i];
}
Vector Vector::operator-() const
{
	Vector* res = new Vector(*this);
	for(int i = 0; i < size; ++i)
		res->data[i] *= -1;
	return *res;
}
Vector Vector::operator-(const Vector& other) const
{
	if(this->size != other.size)
		return *(new Vector());
	Vector *res = new Vector(*this);
	for(int i = 0; i < size; ++i)
		res->data[i] -= other.data[i];
	return *res;
}
void Vector::operator -=(const Vector& other)
{
	if(this->size != other.size)
		return;
	for(int i = 0; i < size; ++i)
		this->data[i] -= other.data[i];
}
int Vector::operator*(const Vector& other) const
{
	if(this->size != other.size)
		return 0;
	int res = 0;
	for(int i = 0; i < size; ++i)
		res += this->data[i] * other.data[i];
	return res;
}
float Vector::operator()(void) const
{
	return sqrt( static_cast<float>((*this) * (*this)) );
}
ostream& operator<<(ostream& out, const Vector& vector)
{
	out << endl;
	for(int i = 0; i < vector.Size(); ++i)
		out << vector[i] << "\t";
	out << endl;
	return out;
}