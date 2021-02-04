#pragma once
#include "MyVector.h"

MyVector::MyVector(int dim)
{

	this->dimensiune = dim;
	element = new int[this->dimensiune];
	for (int i = 0; i < dimensiune; i++)
	{
		element[i] = 0;
	}
}

MyVector::~MyVector()
{
	cout << "am apelat destructorul";
	delete[] element;
}

MyVector::MyVector(const MyVector& vector)
{
	this->dimensiune = vector.dimensiune;
	this->element = new int[this->dimensiune];
	for (int i = 0; i < this->dimensiune; i++)
		this->element[i] = vector.element[i];
	cout << "se apeleaza constructorul de copiere";
}

double MyVector::Norma()
{
	int suma = 0;
	for (int i = 0; i < this->dimensiune; i++)
	{
		suma = this->element[i] * this->element[i];
	}
	return sqrt(suma);
}

MyVector& MyVector::operator+(const MyVector& vector)
{
	MyVector rezultat;
	rezultat.dimensiune = this->dimensiune;
	rezultat.element = new int[rezultat.dimensiune];
	if (this->dimensiune == vector.dimensiune)
		for (int i = 0; i < dimensiune; i++)
		{
			rezultat.element[i] = this->element[i] + vector.element[i];
		}
	return rezultat;
}

MyVector MyVector::operator-(const MyVector& vector)
{
	MyVector rezultat;
	rezultat.dimensiune = this->dimensiune;
	rezultat.element = new int[rezultat.dimensiune];
	if (this->dimensiune == vector.dimensiune)
		for (int i = 0; i < dimensiune; i++)
		{
			rezultat.element[i] = this->element[i] - vector.element[i];
		}
	return rezultat;
}

int MyVector::operator*(const MyVector& vector)
{
	int produs = 0;
	if (this->dimensiune == vector.dimensiune)
		for (int i = 0; i < dimensiune; i++)
		{
			produs = produs + (this->element[i] * vector.element[i]);
		}
	return produs;
}


MyVector& MyVector::operator=(const MyVector& vector)
{
	this->dimensiune = vector.dimensiune;
	this->element = new int[this->dimensiune];
	for (int i = 0; i < this->dimensiune; i++)
		this->element[i] = vector.element[i];
	return (*this);
}
void Sortare(int v[50], int n)
{
	int aux = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] > v[j])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
}

bool MyVector::operator==(const MyVector& vector) const
{
	Sortare(vector.element, vector.dimensiune);
	Sortare(this->element, this->dimensiune);
	int ok = 0;
	for (int i = 0; i < vector.dimensiune && ok == 0; i++)
	{
		if (this->element[i] != vector.element[i])
			ok = 1;
	}
	if (ok == 0)
		return true;
	return false;
}

int MyVector::operator!()
{
	int max = 0;
	for (int i = 0; i < this->dimensiune; i++)
	{
		if (this->element[i] > max)
			max = this->element[i];
	}
	return max;
}

ostream& operator<<(ostream& flux, const MyVector& obiect)
{
	flux << "dimensiune este: " << obiect.dimensiune << "\n";
	cout << "Elementele vectorului sunt ";
	for (int i = 0; i < obiect.dimensiune; i++)
		flux << obiect.element[i];
	return flux;
}

istream& operator>>(istream& flux, MyVector& obiect)
{
	flux >> obiect.dimensiune;
	obiect.element = new int[obiect.dimensiune];
	for (int i = 0; i < obiect.dimensiune; i++)
		flux >> obiect.element[i];
	return flux;
}
