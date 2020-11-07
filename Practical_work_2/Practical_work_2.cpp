#include "pch.h"
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
int getMinArrayElement(int[]);
int getMaxArrayElement(int[]);
void copyArray(int[], int[]);
void printArray(int[]);
bool choiseNextAction();
float stopTimer(time_point<steady_clock>);

const int sizeOfArray = 100;
int main()
{
	srand((unsigned)time(NULL));
	time_point<steady_clock> startTimer = steady_clock::now();
	float stopTime = stopTimer(startTimer);

	int count = 0;
	cout << "This program is solution of task \"Static One-Dimensional Massives\". \n\n";
	
	// РЕШЕНИЕ ПЕРВОГО ЗАДАНИЯ
	int mainArray[sizeOfArray];
	do {
		createAndPrintRandomArray(mainArray);
	} while (choiseNextAction());

	// РЕШЕНИЕ ВТОРОГО ЗАДАНИЯ
	do {
		cout << "\n\tTask 2. Array sorting." << endl
			<< "\t\t1) Bubble sort" << endl
			<< "\t\t2) Shaker sort" << endl
			<< "\t\t3) Comb sort" << endl
			<< "\t\t4) Insert sort" << endl
			<< "\t\t5) Quick sort" << endl
			<< "Enter the number of sorting... \n>> ";
		int input;
		cin >> input;
		int copiedArray[sizeOfArray];
		copyArray(mainArray, copiedArray); // Копирование массива в другой массив для возможности в дальнейшем на том же массиве проверить другие типы сортировки.

		switch (input) {
		case 1: // РЕШЕНИЕ 2.1 ЗАДАНИЯ (bubble sort)
			startTimer = steady_clock::now(); // Старт отсчёта времени
			bubbleSort(copiedArray);
			stopTime = stopTimer(startTimer);
			//endTimer = steady_clock::now(); // Окончание отсчёта времени
			//sortingTime = duration_cast<fseconds>(endTimer - startTimer);

			cout << "\nBubble sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTime << " second(s). \n";
			break;
		case 2: // РЕШЕНИЕ 2.2 ЗАДАНИЯ (shaker sort)
			startTimer = steady_clock::now();
			shakerSort(copiedArray);
			stopTime = stopTimer(startTimer);
			//endTimer = steady_clock::now();
			//sortingTime = duration_cast<fseconds>(endTimer - startTimer);

			cout << "\nShaker sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTime << " second(s). \n";
			break;
		case 3: // РЕШЕНИЕ 2.3 ЗАДАНИЯ (comb sort)
			startTimer = steady_clock::now();
			combSort(copiedArray);
			stopTime = stopTimer(startTimer);

			cout << "\nComb sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTime << " second(s). \n";
			break;
		case 4: // РЕШЕНИЕ 2.4 ЗАДАНИЯ (insert sort)
			startTimer = steady_clock::now();
			insertSort(copiedArray);
			stopTime = stopTimer(startTimer);

			cout << "\nInsert sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTime << " second(s). \n";
			break;
		case 5: // РЕШЕНИЕ 2.5 ЗАДАНИЯ (quick sort)
			startTimer = steady_clock::now();
			quickSort(copiedArray, sizeOfArray - 1, 0);
			stopTime = stopTimer(startTimer);

			cout << "\nQuick sorted array: \n";
			printArray(copiedArray);
			cout << "Array sorted in " << fixed << stopTime << " second(s). \n";
			break;
		}
	} while (choiseNextAction());

	// РЕШЕНИЕ ТРЕТЬЕГО ЗАДАНИЯ
	do {
		cout << "\n\tTask 3. Searching min and max elements of sorted and unsorted arrays." << endl;
		int copiedArray[sizeOfArray];
		copyArray(mainArray, copiedArray);
		quickSort(copiedArray, sizeOfArray - 1, 0);

		startTimer = steady_clock::now(); // Поиск в неотсортированном массиве
		int max = getMaxArrayElement(mainArray);
		int min = getMinArrayElement(mainArray);
		stopTime = stopTimer(startTimer);
		
		cout << "Min element of array: " << min << endl
			<< "Max element of array: " << max << endl
			<< "Elements founds in unsorted array for " << stopTime << " second(s)." << endl;

		startTimer = steady_clock::now(); // Поиск в отсортированном массиве
		max = getMaxArrayElement(copiedArray);
		min = getMinArrayElement(copiedArray);
		stopTime = stopTimer(startTimer);
		cout << "Elements founds in sorted array for " << stopTime << " second(s)." << endl;
		
		startTimer = steady_clock::now(); // Вывод минимального и максимального элементов отсортированного массива без поиска
		max = copiedArray[sizeOfArray-1];
		min = copiedArray[0];
		stopTime = stopTimer(startTimer);
		cout << "Elements founds in sorted array for " << stopTime << " second(s) without traditional searching." << endl;
	} while (choiseNextAction());

	/*do {

	} while (choiseNextAction());
	*/
	system("pause");
	return 0;
}

void createAndPrintRandomArray(int inputArray[]) {
	cout << "\n\tTask 1. Initial array:" << endl;
	
	for (int i = 0; i < sizeOfArray; i++) {
		inputArray[i] = -99 + rand() % 199; // В массив пишутся случайные целые числа диапазона -99..99 включительно. При желании данную функцию можно расширить возможностью выбирать граничные значения.
		cout << inputArray[i] << "\t";

		if ((i+1) % 10 == 0) // Вывод по 10 элементов для удобочитаемости
			cout << endl << endl;
	}
	cout << endl;
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
	float k = 1.247, sortingRange = sizeOfArray - 1;

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
	cout << "For repeat enter 1, for continue enter 2 or other integer number..." << "\n>> ";
	int input;
	cin >> input;
	if (input == 1)
		return true;
	else return false;
}

float stopTimer(time_point<steady_clock> startTimer) {
	using fseconds = duration<float>; // Определение кастомного интервала времени для отображение дробных секунд в таймере.
	time_point<steady_clock> endTimer = steady_clock::now(); // Остановка времени
	fseconds sortingTime = duration_cast<fseconds>(endTimer - startTimer); // Вычисление разницы между финальным и стартовым временем
	return sortingTime.count();
}