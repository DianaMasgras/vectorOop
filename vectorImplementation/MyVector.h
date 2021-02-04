#pragma once
#include <iostream>
using namespace std;

class MyVector
{
private:
	int dimensiune;
	int* element;
public:
	MyVector(int dim = 1);
	~MyVector();
	MyVector(const MyVector& vector);
	friend ostream& operator<<(ostream& flux, const MyVector& obiect);
	friend istream& operator>>(istream& flux, MyVector& obiect);
	double Norma();
	MyVector& operator+(const MyVector& vector);
	MyVector& operator=(const MyVector& vector);
	MyVector operator-(const MyVector& vector);
	int operator*(const MyVector& vector);
	bool operator==(const MyVector& vector)const;
	int operator!();

};

