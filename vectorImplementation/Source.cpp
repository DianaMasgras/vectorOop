#include"MyVector.h"
#include <iostream>
using namespace std;

int main()
{

	MyVector a(3), b(4);

	cin >> a;
	cin >> b;
	cout << a;
	cout << b;
	if (a == b)
		cout << "vectorii sunt egali";
	else
		cout << "vectorii nu sunt la fel";
	//cout <<"inmultirea este:"<< a * b;


		//cout << "maximul este:" << !a;
		/*cout << "Adunare este: ";
		cout << a + b; */



		/*
		if (a.Norma() > b.Norma())
			cout << "vectorul a are norma mai mare";
		else
		{
			if (a.Norma() == b.Norma())
				cout << "Normele sunt egele";
			else
				cout << "vectorul b are norma mai mare";
		}



		int n;
		cout << "cati vectori dorest? : ";
		cin >> n;
		MyVector vect[9];
		for (int i = 0; i < n; i++)
		{
			cin >> vect[i];
			cout << vect[i];
		}
		double maxim = 0;
		int pozMax = -1;
		for (int j = 0; j < n; j++)
		{
			if (vect[j].Norma() > maxim)
			{
				maxim = vect[j].Norma();
				pozMax = j;
			}
		}
		cout << "Vectorul cu norma maxima este: ";
		cout << vect[pozMax];
		*/


}