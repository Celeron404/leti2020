#include <iostream>
#include <ctime> // Нужно для рандома
#include <chrono> // Нужно для засечения времени
#include <Windows.h> // Нужно для получения координат консоли и их изменения
#include <iomanip> // нужно для std::setw
using namespace std::chrono; // Нужно для засечения времени
using namespace std;

void practicalWork1();
void practicalWork2();
void practicalWork3();

void intToBinary(int);
void floatToBinary(int);
void doubleToBinary(int, int);
int readInt();

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

void snakeAnimation(int[], int, short cellSize = 4, short delay = 100);
void spiralAnimation(int[], int, short cellSize = 4, short delay = 100);

int main()
{
	while (true) {
		system("CLS");
		cout << "Practical works: \n"
			<< "\t1) Data types and their internal representation in computer memory \n"
			<< "\t2) Static One-Dimensional Massives \n"
			<< "\t3) Arythmetics of pointers. Matrixes \n\n"
			<< "Enter the number of practical work or enter 0 for close the program... \n>> ";
		int input;
		cin >> input;
		switch (input) {
		case 1:
			system("CLS");
			practicalWork1();
			break;
		case 2:
			system("CLS");
			practicalWork2();
			break;
		case 3:
			system("CLS");
			practicalWork3();
			break;
		default:
			goto Exit;
		}
	}
Exit:
	cout << "\nClosing the program... \n";
	system("pause");
	return 0;
}

void practicalWork1() {
	cout << "Solution of task \"Data types and their internal representation in computer memory\". \n\n";

	do {
		cout << "\tTask 1. Size of data types. \n"
			<< "int: \t\t" << sizeof(int) << " bytes. \n"
			<< "short int \t" << sizeof(short int) << " bytes. \n"
			<< "long int \t" << sizeof(long int) << " bytes. \n"
			<< "float \t\t" << sizeof(float) << " bytes. \n"
			<< "double \t\t" << sizeof(double) << " bytes. \n"
			<< "long double \t" << sizeof(long double) << " bytes. \n"
			<< "char \t\t" << sizeof(char) << " bytes. \n"
			<< "bool \t\t" << sizeof(bool) << " bytes. \n";
	} while (choiseNextAction());

	system("CLS");
	cout << "\tTask 2. Binary representation of integer number. \n\n";
	int input;
	do {
		cout << "Enter the integer number... \n>> ";
		// Считывание числа с проверкой на принадлежность к целым числам.
		input = readInt();
		cout << "Binary representation of number " << input << ": ";
		intToBinary(int(input));
	} while (choiseNextAction());

	system("CLS");
	cout << "\tTask 3. Binary representation of float number. \n";
	union {
		float inputFloat;
		int inputInt1;
	};
	do {
		cout << "Enter the float number... \n>> ";
		cin >> inputFloat;
		cout << "Binary representation of number " << inputFloat << ": ";
		floatToBinary(inputInt1);
	} while (choiseNextAction());

	system("CLS");
	cout << "\tTask 4. Binary representation of double number. \n";
	union {
		double inputDouble;
		int inputInt2[2] = { NULL, NULL };
	};
	do {
		cout << "Enter the double number... \n>> ";
		cin >> inputDouble;
		cout << "Binary representation of number " << inputDouble << ":\n";
		doubleToBinary(inputInt2[1], inputInt2[0]);
	} while (choiseNextAction());
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
	double input;
	while (true) {
		cin >> input;
		// Проверка на целое число
		if (static_cast<int>(input) != input) {
			cout << "Need enter the integer number! Try again...\n";
			continue;
		}
		return int(input);
	}
}

const int sizeOfArray = 100;
void practicalWork2() {
	srand((unsigned)time(NULL));
	time_point<steady_clock> startTimer = steady_clock::now();
	float stopTimeInSeconds = stopSecondsTimer(startTimer);
	long long stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);

	int count = 0;
	cout << "Solution of task \"Static One-Dimensional Massives\". \n\n";

	// РЕШЕНИЕ ПЕРВОГО ЗАДАНИЯ
	int mainArray[sizeOfArray];
	do {
		cout << "\tTask 1. Initial array:" << endl;
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
		cout << "\n\tTask 8. Switching array elements. \n"
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
			cout << "Wrong input! Try again...\n\n>> ";
			continue;
		}
		stopTimeInNanoSeconds = stopNanoSecondsTimer(startTimer);
		printArray(copiedArray); // Отладка
		cout << "The switching has been completed for " << stopTimeInNanoSeconds << " nanoseconds. \n";
	} while (choiseNextAction());
}

void createAndPrintRandomArray(int inputArray[]) {

	for (int i = 0; i < sizeOfArray; i++) {
		inputArray[i] = -99 + rand() % 199; // В массив пишутся случайные целые числа диапазона -99..99 включительно. При желании данную функцию можно расширить возможностью выбирать граничные значения.
		cout << inputArray[i] << "\t";

		if ((i + 1) % 10 == 0) // Вывод по 10 элементов для удобочитаемости
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
	cout << "\nDo you want to repeat (y/n)?" << "\n>> ";
	char input;
	while (true) {
		cin >> input;
		if (input == 'y' || input == 'Y')
			return true;
		else if (input == 'n' || input == 'N')
			return false;
		else
			cout << "Wrong input! Try again...\n>> ";
	}
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

void practicalWork3() {
	int order;
	system("CLS");
	cout << "Solution of task \"Arythmetics of pointers. Matrixes\". \n\n"
		<< "Task 1. Visualisation of filling the matrix. \n"
		<< "Enter the order of matrix... \n>> ";
	bool inputIsCorrected = true;
	do {
		cin >> order;
		if (order > 0)
			inputIsCorrected = false;
		else {
			cout << "Wrong input! Try again...\n>> ";
		}
	} while (inputIsCorrected);

	srand((unsigned)time(NULL));
	int *ptrarray = new int[order*order]; // Объявление динамического одномерного массива размерности двумерного

	for (int i = 0; i < order; i++)
		for (int j = 0; j < order; j++) // В массив пишутся случайные числа от 1 до N*N, где N - порядок матрицы. 
			*(ptrarray + i * order + j) = 1 + rand() % (order * order);
	cout << endl;
	do {
		inputIsCorrected = true;
		cout << "Enter the type of animation:"
			<< "\n\t1) Snake animation"
			<< "\n\t2) Spiral animation\n>> ";
		do {
			int input;
			cin >> input;
			switch (input) {
			case 1:
				snakeAnimation(ptrarray, order);
				inputIsCorrected = false;
				break;
			case 2:
				spiralAnimation(ptrarray, order);
				inputIsCorrected = false;
				break;
			default:
				cout << "Wrong input! Try again...\n\n>> ";
			}
		} while (inputIsCorrected);

	} while (choiseNextAction());
}

void snakeAnimation(int arr[], int order, short cellSize, short delay) {
	/* Функция принимает на вход:
	1) Указатель на первый элемент массива-матрицы (квадратной) (required)
	2) Порядок матрицы (required)
	3) Размер текстовой ячейки, определяемой под одно число матрицы (минимально это количество цифр в максимальном числе + 1) (опционально)
	4) Скорость вывода элементов матрицы, в миллисекундах (опционально)
	*/
	cout << "\nTry to \"snake\" animation: \n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Нужно для получения данных курсора консоли
	CONSOLE_SCREEN_BUFFER_INFO bi;

	int column = 0;
	
	while (column < order) {
		for (int row = 0; row < order; row++) { // Вывод вниз
			GetConsoleScreenBufferInfo(hConsole, &bi); // Получение координат курсора
			bi.dwCursorPosition.Y += 1; // Вычисление новых координат курсора
			bi.dwCursorPosition.X -= cellSize;
			SetConsoleCursorPosition(hConsole, bi.dwCursorPosition); // Установка положения курсора
			cout << setw(cellSize) << *(arr + row * order + column);
			Sleep(delay); // Задержка
		}
		column++;
		if (column < order) {
			for (int row = order - 1; row >= 0; row--) { // Вывод вверх
				cout << setw(cellSize) << *(arr + row * order + column);
				Sleep(delay);
				GetConsoleScreenBufferInfo(hConsole, &bi);
				bi.dwCursorPosition.Y -= 1;
				bi.dwCursorPosition.X -= cellSize;
				SetConsoleCursorPosition(hConsole, bi.dwCursorPosition);
			}
			column++;
			GetConsoleScreenBufferInfo(hConsole, &bi);
			bi.dwCursorPosition.X += (cellSize * 2);
			SetConsoleCursorPosition(hConsole, bi.dwCursorPosition);
		}
		else break;
	}
	if (order % 2 == 0)
		for (int i = 0; i < order + 1; i++)
			cout << endl;
}

void spiralAnimation(int arr[], int order, short cellSize, short delay) {
	cout << "\n\nTry to spiral animation: \n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Нужно для получения данных курсора консоли
	CONSOLE_SCREEN_BUFFER_INFO bi;

	int length = order; // Длина текущего вывода
	for (int i = 0; i < length; i++) { // Вывод вправо
		cout << setw(cellSize) << *(arr + (order - length) * order + i);
		Sleep(delay);
	}
	length--;
	int upperRightBorder = order - 1;
	int lowerLeftBorder = 0;
	while (length > 0)
	{
		for (int i = 0, t = lowerLeftBorder + 1; i < length; i++, t++) { // Вывод вниз
			GetConsoleScreenBufferInfo(hConsole, &bi);
			bi.dwCursorPosition.Y += 1;
			bi.dwCursorPosition.X -= (cellSize);
			SetConsoleCursorPosition(hConsole, bi.dwCursorPosition);
			cout << setw(cellSize) << *(arr + t * order + upperRightBorder);
			Sleep(delay);
		}

		if (!(length > 0))
			break;
		for (int i = 0, t = upperRightBorder - 1; i < length; i++, t--) { // Вывод влево
			GetConsoleScreenBufferInfo(hConsole, &bi);
			bi.dwCursorPosition.X -= (cellSize * 2);
			SetConsoleCursorPosition(hConsole, bi.dwCursorPosition);
			cout << setw(cellSize) << *(arr + upperRightBorder * order + t);
			Sleep(delay);
		}
		length--;
		upperRightBorder--;

		if (!(length > 0))
			break;
		for (int i = 0, t = upperRightBorder; i < length; i++, t--) { // Вывод вверх
			GetConsoleScreenBufferInfo(hConsole, &bi);
			bi.dwCursorPosition.Y -= 1;
			bi.dwCursorPosition.X -= (cellSize);
			SetConsoleCursorPosition(hConsole, bi.dwCursorPosition);
			cout << setw(cellSize) << *(arr + t * order + lowerLeftBorder);
			Sleep(delay);
		}
		lowerLeftBorder++;

		if (!(length > 0))
			break;
		for (int i = 0, t = lowerLeftBorder; i < length; i++, t++) { // Вывод вправо
			cout << setw(cellSize) << *(arr + lowerLeftBorder * order + t);
			Sleep(delay);
		}
		length--;
	}

	for (int i = 0; i <= (order / 2); i++)
		cout << endl;
}