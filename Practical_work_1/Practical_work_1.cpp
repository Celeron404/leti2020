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
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); //íàñòðîéêà êîäèðîâêè êîíñîëè

	cout << "Äàííàÿ ïðîãðàììà ÿâëÿåòñÿ ðåøåíèåì ïåðâîé ïðàêòè÷åñêîé ðàáîòû \n"
		<< "\"Òèïû äàííûõ è èõ âíóòðåííåå ïðåäñòàâëåíèå â ïàìÿòè\" \n \n";
	
	solution1();
	solution2();
	solution3();
	solution4();

	cout << "Çàâåðøåíèå ðàáîòû ïðîãðàììû. \n";
	system("pause");
	return 0;
}

// Ðåøåíèå ïåðâîãî çàäàíèÿ
void solution1() { 
	cout << "\tÇàäàíèå 1: ðàçìåð äàííûõ íà êîìïüþòåðå \n"
		<< "int: \t\t" << sizeof(int) << " áàéòà. \n"
		<< "short int \t" << sizeof(short int) << " áàéòà. \n"
		<< "long int \t" << sizeof(long int) << " áàéòà. \n"
		<< "float \t\t" << sizeof(float) << " áàéòà. \n"
		<< "double \t\t" << sizeof(double) << " áàéòîâ. \n"
		<< "long double \t" << sizeof(long double) << " áàéòîâ. \n"
		<< "char \t\t" << sizeof(char) << " áàéò. \n"
		<< "bool \t\t" << sizeof(bool) << " áàéò. \n";
}

// Ðåøåíèå âòîðîãî çàäàíèÿ
void solution2() { 
	cout << "\n\tÇàäàíèå 2: äâîè÷íîå ïðåäñòàâëåíèå â ïàìÿòè (âñå ðàçðÿäû) ÷èñëà òèïà int \n";
	int input;
	while (true) {
		cout << "Введите любое целое число диапазона int... \n";
		// Считывание числа с проверкой на принадлежность к целым числам.
		input = readInt();
		cout << "Äâîè÷íîå ïðåäñòàâëåíèå â ïàìÿòè ÷èñëà " << input << ": ";
		intToBinary(int(input));

		cout << "\nДля повтора введите 1, для перехода к следующему заданию введите любую другую цифру... \n";
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

// Ðåøåíèå òðåòüåãî çàäàíèÿ
void solution3() { 
	cout << "\n\tÇàäàíèå 3: äâîè÷íîå ïðåäñòàâëåíèå â ïàìÿòè (âñå ðàçðÿäû) ÷èñëà òèïà float \n";		
	union {
		float inputFloat;
		int inputInt;
	};
	while (true) {
		cout << "Введите любое число диапазона float... \n";
		cin >> inputFloat;
		cout << "Äâîè÷íîå ïðåäñòàâëåíèå â ïàìÿòè ÷èñëà " << inputFloat << ": ";
		floatToBinary(inputInt);

		cout << "\nДля повтора введите 1, для перехода к следующему заданию введите любую другую цифру... \n";\
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

void solution4() { // Ðåøåíèå ÷åòâ¸ðòîãî çàäàíèÿ
	cout << "\n\tÇàäàíèå 4: äâîè÷íîå ïðåäñòàâëåíèå â ïàìÿòè (âñå ðàçðÿäû) ÷èñëà òèïà double \n";
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
	int mask = 1 << 31; // Ìàñêà ïðåäñòàâëÿåò ñîáîé 2^32, òî åñòü 10...00, ãäå íóëåé 31.
	for (int i = 1; i <= 32; i++) {
		/*
		Ïîáèòîâîå ñðàâíåíèå ââåä¸ííîãî ÷èñëà ñ ìàñêîé.
		Åñëè ó ÷èñëà è ìàñêè åñòü õîòÿ áû îäíà îáùàÿ åäèíèöà (â äàííîì ñëó÷àå áÎëüøèé áèò ÷èñëà), òî âûâîäèòñÿ "1", èíà÷å "0".
		Äàëåå ïîáèòîâûé ñäâèã ââåä¸ííîãî ÷èñëà âëåâî è òàê 32 ðàçà (èìåííî ñòîëüêî áèò îïðåäåëÿåòñÿ ïîä int).
		Íàïðèìåð:
		0 1000000 00000000 00000000 00000000 - äâîè÷íîå ïðåäñòàâëåíèå â ïàìÿòè êîìïüþòåðà ââåä¸ííîãî ÷èñëà 2^31
		1 0000000 00000000 00000000 00000000 - ìàñêà (2^32)
		Âûâîä: 0
		Çàòåì ïîáèòîâûé ñäâèã ââåä¸ííîãî ÷èñëà âëåâî:
		1 0000000 00000000 00000000 00000000
		1 0000000 00000000 00000000 00000000 - ìàñêà (2^32)
		Âûâîä: 1
		Äàëåå ñëåäóþò íóëè, â âûâîäå: 0 1000000 00000000 00000000 00000000
		*/
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i % 8 == 0 || i == 1)
			putchar(' '); // îòäåëåíèå äðóã îò äðóãà áàéòîâ, ñîäåðæàùèõ çíà÷åíèå ÷èñëà, à òàêæå çíàêîâîãî áèòà
	}
}

void floatToBinary(int value) {
	int mask = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i == 1 || i == 9)
			putchar(' '); // îòäåëåíèå äðóã îò äðóãà áèòîâ ìàíòèññû è ïîðÿäêà, à òàêæå çíàêîâîãî áèòà
	}
}

void doubleToBinary(int firstPart, int secondPart) {
	int mask = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		putchar(firstPart & mask ? '1' : '0');
		firstPart <<= 1;
		if (i == 1 || i == 12)
			putchar(' '); // îòäåëåíèå äðóã îò äðóãà áèòîâ ìàíòèññû è ïîðÿäêà, à òàêæå çíàêîâîãî áèòà
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
		// Ïðîâåðêà íà öåëîå ÷èñëî
		if (static_cast<int>(input) != input) {
			cout << "Необходимо ввести целое число! Попробуйте ещё раз...\n";
			continue;
		}
		return int(input);
	}
}