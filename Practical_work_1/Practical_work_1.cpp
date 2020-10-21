#include "pch.h"
#include <iostream>
using namespace std;

void solution1();
void solution2();
void solution3();
void solution4();
void intToBinary(int);
void floatToBinary(int);
void doubleToBinary(int, int);
int readInt();

int main()
{
	setlocale(0, "");
	cout << "Данная программа является решением первой практической работы \n"
		<< "\"Типы данных и их внутреннее представление в памяти\" \n \n";
	
	solution1();
	solution2();
	solution3();
	solution4();

	cout << "Завершение работы программы. \n";
	system("pause");
	return 0;
}

// Решение первого задания
void solution1() { 
	cout << "\tЗадание 1: размер данных на компьютере \n"
		<< "int: \t\t" << sizeof(int) << " байта. \n"
		<< "short int \t" << sizeof(short int) << " байта. \n"
		<< "long int \t" << sizeof(long int) << " байта. \n"
		<< "float \t\t" << sizeof(float) << " байта. \n"
		<< "double \t\t" << sizeof(double) << " байтов. \n"
		<< "long double \t" << sizeof(long double) << " байтов. \n"
		<< "char \t\t" << sizeof(char) << " байт. \n"
		<< "bool \t\t" << sizeof(bool) << " байт. \n";
}

// Решение второго задания
void solution2() { 
	cout << "\n\tЗадание 2: двоичное представление в памяти (все разряды) числа типа int \n";
	int input;
	while (true) {
		cout << "Введите любое целое число диапазона int... \n";
		// Считывание числа с проверкой на принадлежность к целым числам.
		input = readInt();
		cout << "Двоичное представление в памяти числа " << input << ": ";
		intToBinary(int(input));

		cout << "\nДля повтора введите 1, для перехода к следующему заданию введите любую другую цифру... \n";
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

// Решение третьего задания
void solution3() { 
	cout << "\n\tЗадание 3: двоичное представление в памяти (все разряды) числа типа float \n";		
	union {
		float inputFloat;
		int inputInt;
	};
	while (true) {
		cout << "Введите любое число диапазона float... \n";
		cin >> inputFloat;
		cout << "Двоичное представление в памяти числа " << inputFloat << ": ";
		floatToBinary(inputInt);

		cout << "\nДля повтора введите 1, для перехода к следующему заданию введите любую другую цифру... \n";\
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

void solution4() { // Решение четвёртого задания
	cout << "\n\tЗадание 4: двоичное представление в памяти (все разряды) числа типа double \n";
	union {
		double inputDouble;
		int inputInt[2] = { NULL, NULL };
	};
	while (true) {
		cout << "Введите любое число диапазона double... \n";
		cin >> inputDouble;
		cout << "Двоичное представление в памяти числа " << inputDouble << ": ";
		doubleToBinary(inputInt[1], inputInt[0]);

		cout << "\nДля повтора введите 1, для завершения работы программы введите любую другую цифру... \n";\
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

void intToBinary(int value) {
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

void doubleToBinary(int firstPart, int secondPart) {
	int mask = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		putchar(firstPart & mask ? '1' : '0');
		firstPart <<= 1;
		if (i == 1 || i == 12)
			putchar(' '); // отделение друг от друга битов мантиссы и порядка, а также знакового бита
	}
	for (int i = 1; i <= 32; i++) {
		putchar(secondPart & mask ? '1' : '0');
		secondPart <<= 1;
	}
}

int readInt() {
	float input;
	while (true) {
		cin >> input;
		// Проверка на целое число
		if (static_cast<int>(input) != input) {
			cout << "Необходимо ввести целое число! Попробуйте ещё раз...\n";
			continue;
		}
		return int(input);
	}
}