#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	cout << "Данная программа является решением первой практической работы" << endl
		<< "\"Типы данных и их внутреннее представление в памяти\"" << endl << endl;

	cout << "Задание 1:" << endl
		<< "Под тип данных int на данном компьютере отводится " << sizeof(int) << " байта." << endl
		<< "Под тип данных short int на данном компьютере отводится " << sizeof(short int) << " байта." << endl
		<< "Под тип данных long int на данном компьютере отводится " << sizeof(long int) << " байтов." << endl
		<< "Под тип данных float на данном компьютере отводится " << sizeof(float) << " байта." << endl
		<< "Под тип данных double на данном компьютере отводится " << sizeof(double) << " байтов." << endl
		<< "Под тип данных long double на данном компьютере отводится " << sizeof(long double) << " байтов." << endl
		<< "Под тип данных char на данном компьютере отводится " << sizeof(char) << " байт." << endl
		<< "Под тип данных bool на данном компьютере отводится " << sizeof(bool) << " байт." << endl << endl;

	system("pause");
	return 0;
}