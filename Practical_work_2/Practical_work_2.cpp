﻿#include "pch.h"
#include <iostream>
#include <ctime> // Нужно для рандома
#include <chrono> // Нужно для засечения времени
using namespace std;
using namespace std::chrono; // Нужно для засечения времени

void createAndPrintRandomArray(int[]);
void bubbleSort(int[]);
void shakerSort(int[]);
void combSort(int[]);
void insertSort(int[]);
void quickSort(int[], int, int);
void Merge(int[], int, int, int, int[]);
void InternalMergeSort(int[], int, int, int[]);
void MergeSort(int[], int, int);
int getMinArrayElement(int[]);
int getMaxArrayElement(int[]);
int binarySearch(int[], int, int, int);
void copyArray(int[], int[]);
void printArray(int[]);
bool choiseNextAction();
float stopSecondsTimer(time_point<steady_clock>);
long long stopNanoSecondsTimer(time_point<steady_clock>);

const int sizeOfArray = 100;
int main()
{
	srand((unsigned)time(NULL));
	time_point<steady_clock> startTimer = steady_clock::now();
	float stopTimeInSeconds = stopSecondsTimer(startTimer);
	long long stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);

	int count = 0;
	cout << "This program is solution of task \"Static One-Dimensional Massives\". \n\n";
	
	// РЕШЕНИЕ ПЕРВОГО ЗАДАНИЯ
	int mainArray[sizeOfArray];
	do {
		cout << "\n\tTask 1. Initial array:" << endl;
		createAndPrintRandomArray(mainArray);
	} while (choiseNextAction());

	do { // РЕШЕНИЕ ВТОРОГО ЗАДАНИЯ
		cout << "\n\tTask 2. Array sorting." << endl
			<< "\t\t1) Bubble sort" << endl
			<< "\t\t2) Shaker sort" << endl
			<< "\t\t3) Comb sort" << endl
			<< "\t\t4) Insert sort" << endl
			<< "\t\t5) Quick sort" << endl
			<< "\t\t6) Merge sort" << endl
			<< "Enter the number of sorting... \n>> ";
		int input;
		cin >> input;
		int copiedArray[sizeOfArray];
		copyArray(mainArray, copiedArray); // Копирование массива в другой массив для возможности в дальнейшем на том же массиве проверить другие типы сортировки.

		switch (input) {
		case 1: // РЕШЕНИЕ 2.1 ЗАДАНИЯ (bubble sort)
			startTimer = steady_clock::now(); // Старт отсчёта времени
			bubbleSort(copiedArray);
			stopTimeInSeconds = stopSecondsTimer(startTimer);

			cout << "\nBubble sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTimeInSeconds << " second(s). \n";
			break;
		case 2: // РЕШЕНИЕ 2.2 ЗАДАНИЯ (shaker sort)
			startTimer = steady_clock::now();
			shakerSort(copiedArray);
			stopTimeInSeconds = stopSecondsTimer(startTimer);

			cout << "\nShaker sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTimeInSeconds << " second(s). \n";
			break;
		case 3: // РЕШЕНИЕ 2.3 ЗАДАНИЯ (comb sort)
			startTimer = steady_clock::now();
			combSort(copiedArray);
			stopTimeInSeconds = stopSecondsTimer(startTimer);

			cout << "\nComb sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTimeInSeconds << " second(s). \n";
			break;
		case 4: // РЕШЕНИЕ 2.4 ЗАДАНИЯ (insert sort)
			startTimer = steady_clock::now();
			insertSort(copiedArray);
			stopTimeInSeconds = stopSecondsTimer(startTimer);

			cout << "\nInsert sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTimeInSeconds << " second(s). \n";
			break;
		case 5: // РЕШЕНИЕ 2.5 ЗАДАНИЯ (quick sort)
			startTimer = steady_clock::now();
			quickSort(copiedArray, sizeOfArray - 1, 0);
			stopTimeInSeconds = stopSecondsTimer(startTimer);

			cout << "\nQuick sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTimeInSeconds << " second(s). \n";
			break;
		case 6: // РЕШЕНИЕ ДОПОЛНИТЕЛЬНОГО ЗАДАНИЯ (merge sort)
			startTimer = steady_clock::now();
			MergeSort(copiedArray, 0, sizeOfArray - 1);
			stopTimeInSeconds = stopSecondsTimer(startTimer);

			cout << "\nMerge sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTimeInSeconds << " second(s). \n";
			break;
		}
	} while (choiseNextAction());

	int copiedArray[sizeOfArray]; // Создание отсортированного массива, с которым будет производиться работа в дальнейших заданиях
	copyArray(mainArray, copiedArray);
	quickSort(copiedArray, sizeOfArray - 1, 0);

	do { // РЕШЕНИЕ ТРЕТЬЕГО ЗАДАНИЯ
		cout << "\n\tTask 3. Searching min and max elements of sorted and unsorted arrays. \n";
		startTimer = steady_clock::now(); // Поиск в неотсортированном массиве
		int max = getMaxArrayElement(mainArray);
		int min = getMinArrayElement(mainArray);
		stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);
		
		cout << "Min element of array: " << min << endl
			<< "Max element of array: " << max << endl
			<< "Elements founds in unsorted array for " << stopTimeInNanoSeconds << " nanoseconds. \n";

		startTimer = steady_clock::now(); // Поиск в отсортированном массиве
		max = getMaxArrayElement(copiedArray);
		min = getMinArrayElement(copiedArray);
		stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);
		//cout << "Min: " << min << "\tMax: " << max << endl; // Отладка
		cout << "Elements founds in sorted array for " << stopTimeInNanoSeconds << " nanoseconds. \n";
	} while (choiseNextAction());

	do { // РЕШЕНИЕ ЧЕТВЁРТОГО ЗАДАНИЯ
		cout << "\n\tTask 4. Search average elements from array. \n";
		int averageElement = int(abs(getMaxArrayElement(copiedArray)) - abs(getMinArrayElement(copiedArray)));
		cout << "Average element: " << averageElement << endl;

		bool isExists = false; // Проверка на то, существует ли вообще в массиве подходящий средний элемент
		for (int i = 0; i < sizeOfArray; i++)
			if (copiedArray[i] == averageElement) {
				isExists = true;
				break;
			}
		if (isExists) {
			cout << "Index(es) of average elements: ";
			int count = 0;
			for (int i = 0; i < sizeOfArray; i++)
				if (copiedArray[i] == averageElement) {
					cout << i << " ";
					count++;
				}
			cout << "\nCount of average elements in array: " << count << endl;
		}
		else
			cout << "Element not found in array. \n";
	} while (choiseNextAction());
	
	do { // РЕШЕНИЕ ПЯТОГО ЗАДАНИЯ
		cout << "\n\tTask 5. The number of smaller elements than the one entered by the user. \n"
			<< "Enter the integer element...\n>> ";
		int input;
		cin >> input;
		int count = 0;
		for (int element : copiedArray)
			if (element < input)
				count++;
		cout << "The array has " << count << " element(s) less than you entered. \n";
	} while (choiseNextAction());

	do { // РЕШЕНИЕ ШЕСТОГО ЗАДАНИЯ
		cout << "\n\tTask 6. The number of larger elements than the one entered by the user. \n"
			<< "Enter the integer element...\n>> ";
		int input;
		cin >> input;
		int count = 0;
		for (int element : copiedArray)
			if (element > input)
				count++;
		cout << "The array has " << count << " element(s) larger than you entered. \n";
	} while (choiseNextAction());

	do { // РЕШЕНИЕ СЕДЬМОГО ЗАДАНИЯ
		cout << "\n\tTask 7. The searching of a user-entered element in the array (traditional and binary search). \n"
			<< "Enter the integer element...\n>> ";
		int input;
		cin >> input;

		startTimer = steady_clock::now();
		bool isExists = false;
		for (int element : copiedArray) // Поиск обычным перебором
			if (element == input) {
				isExists = true;
				break;
			}
		stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);
		if (isExists)
			cout << "The entered element is in the array. \n";
		else
			cout << "The entered element is not in the array. \n";
		cout << "The search has been completed for " << stopTimeInNanoSeconds << " nanoseconds. \n";

		startTimer = steady_clock::now();
		int searchedElement = binarySearch(copiedArray, input, 0, sizeOfArray - 1);
		stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);
		/* Отладка
		if (searchedElement != -1)
			cout << "Searched element (binary search): " << searchedElement << endl;
		else cout << "Element not searched. \n"; */
		cout << "The binary search has been completed for " << stopTimeInNanoSeconds << " nanoseconds. \n";
	} while (choiseNextAction());

	do { // РЕШЕНИЕ ВОСЬМОГО ЗАДАНИЯ
		cout << "\n\tTask 7. Switching array elements. \n"
			<< "Enter the first and second indexes of array elements...\n>> ";
		int input1, input2;
		cin >> input1 >> input2;
		startTimer = steady_clock::now();
		//if (((input1 && input2) >= 0) && ((input1 && input2) < sizeOfArray)) { // Ошибка компилятора о небезопасном условии. Разобраться, почему.
		if ((input1 >= 0) && (input2 >= 0) && (input1 < sizeOfArray) && (input2 < sizeOfArray)) {
			int t = copiedArray[input1];
			copiedArray[input1] = copiedArray[input2];
			copiedArray[input2] = t;
		}
		else {
			cout << "Wrong input! \n";
			continue;
		}
		stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);
		printArray(copiedArray); // Отладка
		cout << "The switching has been completed for " << stopTimeInNanoSeconds << " nanoseconds. \n";
	} while (choiseNextAction());

	cout << "Closing the program... \n";
	system("pause");
	return 0;
}

void createAndPrintRandomArray(int inputArray[]) {
	
	for (int i = 0; i < sizeOfArray; i++) {
		inputArray[i] = -99 + rand() % 199; // В массив пишутся случайные целые числа диапазона -99..99 включительно. При желании данную функцию можно расширить возможностью выбирать граничные значения.
		cout << inputArray[i] << "\t";

		if ((i+1) % 10 == 0) // Вывод по 10 элементов для удобочитаемости
			cout << endl;
	}
}

void bubbleSort(int inputArray[]) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < sizeOfArray - 1; i++) {
			if (inputArray[i] > inputArray[i + 1]) { // Соседние элементы массива меняются местами
				int t = inputArray[i];
				inputArray[i] = inputArray[i + 1];
				inputArray[i + 1] = t;
				swapped = true;
			}
		}
	} while (swapped == true); // Если за последний проход цикла никакие элементы не поменялись местами, цикл прерывается.
}

void shakerSort(int inputArray[]) {
	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < sizeOfArray - 1; i++)
			if (inputArray[i] > inputArray[i + 1]) {
				int t = inputArray[i];
				inputArray[i] = inputArray[i + 1];
				inputArray[i + 1] = t;
				swapped = true;
			}
		for (int i = sizeOfArray - 1; i > 0; i--)
			if (inputArray[i] < inputArray[i - 1]) {
				int t = inputArray[i];
				inputArray[i] = inputArray[i - 1];
				inputArray[i - 1] = t;
				swapped = true;
			}
	} while (swapped);
}

void combSort(int inputArray[]) {
	int swap;
	float k = 1.247F, sortingRange = sizeOfArray - 1;

	while (sortingRange >= 1)
	{
		for (int i = 0; i + sortingRange < sizeOfArray; i++)
		{
			if (inputArray[i] > inputArray[int(i + sortingRange)])
			{
				swap = inputArray[int(i + sortingRange)];
				inputArray[int(i + sortingRange)] = inputArray[i];
				inputArray[i] = swap;
			}
		}
		sortingRange /= k;
	}

	bool swapped;
	do {
		swapped = false;
		for (int i = 0; i < sizeOfArray - 1; i++) {
			if (inputArray[i] > inputArray[i + 1]) { // Соседние элементы массива меняются местами
				int t = inputArray[i];
				inputArray[i] = inputArray[i + 1];
				inputArray[i + 1] = t;
				swapped = true;
			}
		}
	} while (swapped == true); // Если за последний проход цикла никакие элементы не поменялись местами, цикл прерывается.

}

void insertSort(int inputArray[]) {
	int extractedElement, currentPosition;
	for (int i = 1; i < sizeOfArray; i++)
	{ 
		extractedElement = inputArray[i];
		currentPosition = i;
		while ((currentPosition >= 1) && (extractedElement < inputArray[currentPosition - 1]))
		{
			inputArray[currentPosition] = inputArray[currentPosition - 1];
			currentPosition--;
		}
		inputArray[currentPosition] = extractedElement;
	}
}

void quickSort(int inputArray[], int  end, int begin) {
	int middleElement;
	int f = begin;
	int l = end;
	middleElement = inputArray[(f + l) / 2]; // Определяется опорный элемент
	while (f < l) { // Массив сортируется так, что по окончании цикла будет представлять собой две части: элементы меньше либо равные опорному (левая), элементы больше либо равные опорному (правая)
		while (inputArray[f] < middleElement) f++;
		while (inputArray[l] > middleElement) l--;
		if (f <= l)
		{
			int swap = inputArray[f];
			inputArray[f] = inputArray[l];
			inputArray[l] = swap;
			f++;
			l--;
		}
	}
	if (begin < l) quickSort(inputArray, l, begin); // Где l - правая граница левой части разделённого пополам массива
	if (f < end) quickSort(inputArray, end, f); // Где f - левая граница правой части разделённого пополам массива
}

void Merge(int array[], int first, int middle, int last, int temp[])
{
	int idx = first;
	int begin1 = first, end1 = middle;
	int begin2 = middle + 1, end2 = last;

	for (; begin1 <= end1 && begin2 <= end2; )
	{
		if (array[begin1] < array[begin2])
			temp[idx++] = array[begin1++];
		else
			temp[idx++] = array[begin2++];
	}

	for (; begin1 <= end1; )
		temp[idx++] = array[begin1++];

	for (; begin2 <= end2; )
		temp[idx++] = array[begin2++];


	for (idx = first; idx <= last; idx++)
		array[idx] = temp[idx];
}

void InternalMergeSort(int array[], int first, int last, int buffer[])
{
	if (first < last)
	{
		int m = (first + last) / 2;
		InternalMergeSort(array, first, m, buffer);
		InternalMergeSort(array, m + 1, last, buffer);
		Merge(array, first, m, last, buffer);
	}
}

void MergeSort(int array[], int first, int last)
{
	int *buffer = new int[sizeOfArray];
	InternalMergeSort(array, 0, sizeOfArray - 1, buffer);
	delete[] buffer;
}

int getMinArrayElement(int inputArray[]) {
	int minElement = INT_MAX;
	for (int i = 0; i < sizeOfArray; i++)
		if (inputArray[i] < minElement)
			minElement = inputArray[i];
	return minElement;
}

int getMaxArrayElement(int inputArray[]) {
	int maxElement = INT_MIN;
	for (int i = 0; i < sizeOfArray; i++)
		if (inputArray[i] > maxElement)
			maxElement = inputArray[i];
	return maxElement;
}

int binarySearch(int inputArray[], int inputElement, int lowPos, int highPos) {
	while (lowPos <= highPos) {
		int mid = lowPos + (highPos - lowPos) / 2;

		if (inputArray[mid] == inputElement)
			return mid;

		if (inputArray[mid] < inputElement)
			lowPos = mid + 1;

		else
			highPos = mid - 1;
	}
	return -1;
}

void copyArray(int originalArray[], int resultArray[]) {
	for (int i = 0; i < sizeOfArray; i++)
		resultArray[i] = originalArray[i];
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
	cout << "\nFor repeat enter 1, for continue enter 2 or other integer number..." << "\n>> ";
	int input;
	cin >> input;
	if (input == 1)
		return true;
	else return false;
}

float stopSecondsTimer(time_point<steady_clock> startTimer) {
	using fseconds = duration<float>; // Определение кастомного интервала времени для отображение дробных секунд в таймере.
	time_point<steady_clock> endTimer = steady_clock::now(); // Остановка времени
	fseconds sortingTime = duration_cast<fseconds>(endTimer - startTimer); // Вычисление разницы между финальным и стартовым временем
	return sortingTime.count();
}

long long stopNanoSecondsTimer(time_point<steady_clock> startTimer) {
	time_point<steady_clock> endTimer = steady_clock::now();
	nanoseconds sortingTime = duration_cast<nanoseconds>(endTimer - startTimer);
	return sortingTime.count();
}