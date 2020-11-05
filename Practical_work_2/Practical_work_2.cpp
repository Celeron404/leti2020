#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

void createAndPrintRandomArray(int[]);
void bubbleSort(int[]);
bool choiseNextAction();
void printArray(int[]);

const int sizeOfArray = 100;
int mainArray[sizeOfArray];
int main()
{
	srand((unsigned)time(NULL));

	cout << "This program is solution of task \"Static One-Dimensional Massives\". \n\n";
	do {
		createAndPrintRandomArray(mainArray);
	} while (choiseNextAction());

	do {
		bubbleSort(mainArray);
		cout << "Bubble sorted array: \n";
		printArray(mainArray);
	} while (choiseNextAction());

	system("pause");
	return 0;
}

void createAndPrintRandomArray(int inputArray[]) {
	cout << "Initial array:" << endl;
	
	for (int i = 0; i < sizeOfArray; i++) {
		inputArray[i] = -99 + rand() % 199; // В массив пишутся случайные целые числа диапазона -99..99 включительно. При желании данную функцию можно расширить возможностью выбирать граничные значения.
		cout << inputArray[i] << "\t";

		if ((i+1) % 10 == 0) // Вывод по 10 элементов для удобочитаемости
			cout << endl;
	}
	cout << endl;
}

void bubbleSort(int inputArray[]) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < sizeOfArray; i++)
			if (inputArray[i] > inputArray[i + 1]) { // Соседние элементы массива меняются местами
				int t = inputArray[i];
				inputArray[i] = inputArray[i + 1];
				inputArray[i + 1] = t;
				swapped = true;
			}
	} while (swapped); // Если за последний проход цикла никакие элементы не поменялись местами, цикл прерывается.
}

void printArray(int inputArray[]) {
	for (int i = 0; i < sizeOfArray; i++) {
		cout << inputArray[i] << "\t";
		if ((i + 1) % 10 == 0) // Вывод по 10 элементов для удобочитаемости
			cout << endl;
	}
	cout << endl;
}

bool choiseNextAction() {
	cout << "For repeat enter 1, for continue enter 2 or other integer number..." << "\n>> ";
	int input;
	cin >> input;
	if (input == 1)
		return true;
	else return false;
}