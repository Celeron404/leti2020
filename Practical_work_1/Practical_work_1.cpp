#include "pch.h"
#include <iostream>

using namespace std;

void binaryPresentation(int);

int main()
{
	setlocale(0, "");
	cout << "Данная программа является решением первой практической работы" << endl
		<< "\"Типы данных и их внутреннее представление в памяти\"" << endl << endl;

	cout << "Задание 1: размер данных на компьютере" << endl
		<< "int: \t\t" << sizeof(int) << " байта." << endl
		<< "short int \t" << sizeof(short int) << " байта." << endl
		<< "long int \t" << sizeof(long int) << " байта." << endl
		<< "float \t\t" << sizeof(float) << " байта." << endl
		<< "double \t\t" << sizeof(double) << " байтов." << endl
		<< "long double \t" << sizeof(long double) << " байтов." << endl
		<< "char \t\t" << sizeof(char) << " байт." << endl
		<< "bool \t\t" << sizeof(bool) << " байт." << endl << endl;

	cout << "Задание 2:" << endl
		<< "Введите любое целое число диапазона int..." << endl;
	int input;
	cin >> input;
	cout << "Двоичное представление в памяти числа " << input << ": ";
	binaryPresentation(input);
	cout << endl;

	system("pause");
	return 0;
}

void binaryPresentation(int value) {/*
	for (int i = 1; i <= 32; i++) {
		putchar(value & 1 ? '1' : '0');
		value >>= 1;
		if (i % 8 == 0)
			putchar(' ');
		if (i % 31 == 0)
			putchar(' ');*/

	unsigned int order = 32; // Количество разрядов
	unsigned int mask = 1 << order - 1; // Маска побитового сравнения
	for (int i = 1; i <= order; i++)
	{
		putchar(value & mask ? '1' : '0');
		value <<= 1; // Побитовый сдвиг числа
		if (i % 8 == 0)
		{
			putchar(' ');
		}
		if (i % order - 1 == 0)
		{
			putchar(' ');
		}
	}

	}
