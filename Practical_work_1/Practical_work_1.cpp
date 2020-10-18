﻿#include "pch.h"
#include <iostream>

using namespace std;

void toBinary(int);

int main()
{
	setlocale(0, "");
	cout << "Данная программа является решением первой практической работы \n"
		<< "\"Типы данных и их внутреннее представление в памяти\" \n \n";

	cout << "\tЗадание 1: размер данных на компьютере \n"//												Решение первого задания
		<< "int: \t\t" << sizeof(int) << " байта. \n"
		<< "short int \t" << sizeof(short int) << " байта. \n"
		<< "long int \t" << sizeof(long int) << " байта. \n"
		<< "float \t\t" << sizeof(float) << " байта. \n"
		<< "double \t\t" << sizeof(double) << " байтов. \n"
		<< "long double \t" << sizeof(long double) << " байтов. \n"
		<< "char \t\t" << sizeof(char) << " байт. \n"
		<< "bool \t\t" << sizeof(bool) << " байт. \n \n";

	cout << "\tЗадание 2: двоичное представление в памяти (все разряды) числа типа int \n";//			Решение второго задания
	while (true) {
		cout << "Введите любое целое число диапазона int... \n";
		double input;
		cin >> input;


		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Ошибка! Введены некорректные данные. \n";
			continue;
		} else
		if (static_cast<int>(input) != input) { // Проверка на целое число
			cout << "Необходимо ввести целое число! \n";
			continue;
		}
		
		cout << "Двоичное представление в памяти числа " << input << ": ";
		toBinary(input);

		cout << "\nДля повтора введите 1, иначе произойдёт переход к следующему заданию... \n";
		int answer;
		cin >> answer;
		if (answer != 1)
			break;
	}

	system("pause");
	return 0;
}

void toBinary(int value) {
	int mask = 1 << 31; // Маска представляет собой 2^32, то есть 10...00, где нулей 31.
	for (int i = 1; i <= 32; i++) {
		/*
		Побитовое сравнение введённого числа с маской.
		Если у числа и маски есть хотя бы одна общая единица (в данном случае бОльший бит числа), то выводится "1", иначе "0".
		Далее побитовый сдвиг введённого числа влево и так 32 раза (именно столько бит определяется под int).
		Например:
		0 1000000 00000000 00000000 00000000 - двоичное представление в памяти компьютера введённого числа 2^31
		1 0000000 00000000 00000000 00000000 - маска (2^32)
		Вывод: 0
		Затем побитовый сдвиг введённого числа влево:
		1 0000000 00000000 00000000 00000000
		1 0000000 00000000 00000000 00000000 - маска (2^32)
		Вывод: 1
		Далее следуют нули, в выводе: 0 1000000 00000000 00000000 00000000
		*/
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i % 8 == 0)
			putchar(' '); // отделение друг от друга байтов, содержащих значение числа
		if (i == 1)
			putchar(' '); // отделение знакового бита
	}
}

//void toBinary()
