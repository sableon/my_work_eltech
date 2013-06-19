
#include "DateTime.h"
#include <iostream>
using namespace std;
#include "Matrix.h"


int main(int argc, char *argv[])
{

	Vector a(2);
	a[0] = 3;
	a[1] = 4;
	Vector b;
	b = a;
	Vector c(2,5);
	c = b + a;
	b += c;

	Matrix Am(4,a);


	//cout << a() <<endl;
	//cout << a << b << c << endl;
	cout << Am << ~Am << endl;
	Matrix At = ~Am;
	Matrix B(5,5,5);
	cout << B << endl;
	B = At * Am;
	cout << B << endl;

	system("pause");
}
