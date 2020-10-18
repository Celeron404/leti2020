﻿#include "pch.h"
#include <iostream>

using namespace std;

void toBinary(int);
void floatToBinary(int);
void solution1();
void solution2();
void solution3();
short choiseNextAction();
bool checkBuffer();

int main()
{
	setlocale(0, "");
	cout << "Данная программа является решением первой практической работы \n"
		<< "\"Типы данных и их внутреннее представление в памяти\" \n \n";

		short solution;
	while (true) {
		cout << "Введите номер задания (1-4), для завершения программы введите 42... \n";
		cin >> solution;
		switch (solution) {
		case 1:
			solution1();
		case 2:
			solution2();
		case 3:
			solution3();
		case 42:
			return 0;
		default:
			cout << "Введено некорректное значение! \n";
		}
	}
}

void solution1() { // Решение первого задания
	short action = 1;
	while (action == 1) {
		cout << "\n \tЗадание 1: размер данных на компьютере \n"
			<< "int: \t\t" << sizeof(int) << " байта. \n"
			<< "short int \t" << sizeof(short int) << " байта. \n"
			<< "long int \t" << sizeof(long int) << " байта. \n"
			<< "float \t\t" << sizeof(float) << " байта. \n"
			<< "double \t\t" << sizeof(double) << " байтов. \n"
			<< "long double \t" << sizeof(long double) << " байтов. \n"
			<< "char \t\t" << sizeof(char) << " байт. \n"
			<< "bool \t\t" << sizeof(bool) << " байт. \n \n";
		action = choiseNextAction();
	}
}

void solution2() { // Решение второго задания
	cout << "\n \tЗадание 2: двоичное представление в памяти (все разряды) числа типа int \n";
	float input;
	short action = 1;
	while (action == 1) {
		cout << "Введите любое целое число диапазона int... \n";
		cin >> input;

		if (static_cast<int>(input) != input) { // Проверка на целое число
			cout << "Необходимо ввести целое число! \n";
			continue;
		}

		cout << "Двоичное представление в памяти числа " << input << ": ";
		toBinary(int(input));

		choiseNextAction();
	}
}

void solution3() { // Решение третьего задания
	cout << "\tЗадание 3: двоичное представление в памяти (все разряды) числа типа float \n";
	union {
		float inputF;
		int inputL;
	};
	while (true) {
		cout << "Введите любое число диапазона float... \n";
		cin >> inputF;

		cout << "Двоичное представление в памяти числа " << inputF << ": ";
		floatToBinary(inputL);

		choiseNextAction();
	}
}

void solution4() {

}

short choiseNextAction() {
	cout << "\nДля повтора введите 1, для перехода к следующему заданию введите 2, для возврата в меню введите 3... \n";
	short answer;
	cin >> answer;
	switch (answer) {
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	case 3:
		return 3;
		break;
	default:
		cout << "\nВведено некорректное значение! \n";
	}
}

bool checkBuffer() {
	if (cin.fail()) {
		cout << "\nВведено некорректное значение! \n";
		cin.clear();
		while (cin.get() != '\n')
			cin.ignore(cin.rdbuf()->in_avail());
		return false;
	}
	else
		return true;
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
		if (i % 8 == 0 || i == 1)
			putchar(' '); // отделение друг от друга байтов, содержащих значение числа, а также знакового бита
	}
}

void floatToBinary(int value) {
	int mask = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i == 1 || i == 9)
			putchar(' '); // отделение друг от друга битов мантиссы и порядка, а также знакового бита
	}
}
