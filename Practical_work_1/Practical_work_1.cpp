#include "pch.h"
#include <iostream>
using namespace std;

void solution1();
void solution2();
void solution3();
void solution4();
void additionalSolution();
void intToBinary(int);
void floatToBinary(int);
void doubleToBinary(int, int);
int readInt();
void intToBinary(int, short[]);
bool arrayContains(int, short[]);

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251"); //��������� ��������� �������

	cout << "������ ��������� �������� �������� ������ ������������ ������ \n"
		<< "\"���� ������ � �� ���������� ������������� � ������\" \n \n";
	
	solution1();
	solution2();
	solution3();
	solution4();
	additionalSolution();

	cout << "���������� ������ ���������. \n";
	system("pause");
	return 0;
}

// ������� ������� �������
void solution1() { 
	cout << "\t������� 1: ������ ������ �� ���������� \n"
		<< "int: \t\t" << sizeof(int) << " �����. \n"
		<< "short int \t" << sizeof(short int) << " �����. \n"
		<< "long int \t" << sizeof(long int) << " �����. \n"
		<< "float \t\t" << sizeof(float) << " �����. \n"
		<< "double \t\t" << sizeof(double) << " ������. \n"
		<< "long double \t" << sizeof(long double) << " ������. \n"
		<< "char \t\t" << sizeof(char) << " ����. \n"
		<< "bool \t\t" << sizeof(bool) << " ����. \n";
}

// ������� ������� �������
void solution2() { 
	cout << "\n\t������� 2: �������� ������������� � ������ (��� �������) ����� ���� int \n";
	int input;
	while (true) {
		cout << "������� ����� ����� ����� ��������� int... \n>> ";
		// ���������� ����� � ��������� �� �������������� � ����� ������.
		input = readInt();
		cout << "�������� ������������� � ������ ����� " << input << ": ";
		intToBinary(input);

		cout << "\n��� ������� ������� 1, ��� �������� � ���������� ������� ������� ����� ������ �����... \n>> ";
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

// ������� �������� �������
void solution3() { 
	cout << "\n\t������� 3: �������� ������������� � ������ (��� �������) ����� ���� float \n";		
	union {
		float inputFloat;
		int inputInt;
	};
	while (true) {
		cout << "������� ����� ����� ��������� float... \n>> ";
		cin >> inputFloat;
		cout << "�������� ������������� � ������ ����� " << inputFloat << ": ";
		floatToBinary(inputInt);

		cout << "\n��� ������� ������� 1, ��� �������� � ���������� ������� ������� ����� ������ �����... \n>> ";\
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

void solution4() { // ������� ��������� �������
	cout << "\n\t������� 4: �������� ������������� � ������ (��� �������) ����� ���� double \n";
	union {
		double inputDouble;
		int inputInt[2] = { NULL, NULL };
	};
	while (true) {
		cout << "������� ����� ����� ��������� double... \n>> ";
		cin >> inputDouble;
		cout << "�������� ������������� � ������ ����� " << inputDouble << ":\n";
		doubleToBinary(inputInt[1], inputInt[0]);

		cout << "\n��� ������� ������� 1, ��� �������� � ��������������� ������� ������� ����� ������ �����... \n>> ";
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

void additionalSolution() { // ������� ��������������� �������
	cout << "\n\t�������������� �������: ����������� ������������� ��� ����, ����� �����, \n"
		<< "������ ������� �������� ������������� � ����������, ��� ���� ���������� ����� ������. \n";

	int input;
	while (true) {
		short notInvertedBits[64]; // ������, � ������� ������������ ��� ����, ������� ����� �� ����� �������������.
		cout << "������� ����� ����� ����� ��������� int... \n>> ";
		// ���������� ����� � ��������� �� �������������� � ����� ������.
		input = readInt();
		
		cout << "������� ����� ����, ������� �� ����� ������������� (�� 1 �� 64). \n"
			<< "��� ��������� ����� ������� 0... \n>> ";
		short inputCounter = 1;
		while (inputCounter <= 64) {
			short input;
			cin >> input;
			if (input != 0)
				if ((input >= 1) && (input <= 64)) {
					notInvertedBits[inputCounter - 1] = input; // �������� ����� ������������ � ������ ������������ 64.
					inputCounter++;
				}
				else
					cout << "������� ������������ ��������! \n";
			else break;
		};

		cout << "�������� ������������� � ������ ����� " << input << ": ";
		intToBinary(input);
		cout << "��������������� ������������� ����� (����� ��������� ����� �����) " << input << ": ";
		intToBinary(input, notInvertedBits);

		cout << "\n��� ������� ������� 1, ��� �������� � ���������� ���� ������� ����� ������ �����... \n>> ";
		short answer;
		cin >> answer;
		if (answer != 1)
			break;
	}
}

void intToBinary(int value) {
	int mask = 1 << 31; // ����� ������������ ����� 2^32, �� ���� 10...00, ��� ����� 31.
	for (int i = 1; i <= 32; i++) {
		/*
		��������� ��������� ��������� ����� � ������.
		���� � ����� � ����� ���� ���� �� ���� ����� ������� (� ������ ������ ������� ��� �����), �� ��������� "1", ����� "0".
		����� ��������� ����� ��������� ����� ����� � ��� 32 ���� (������ ������� ��� ������������ ��� int).
		��������:
		0 1000000 00000000 00000000 00000000 - �������� ������������� � ������ ���������� ��������� ����� 2^31
		1 0000000 00000000 00000000 00000000 - ����� (2^32)
		�����: 0
		����� ��������� ����� ��������� ����� �����:
		1 0000000 00000000 00000000 00000000
		1 0000000 00000000 00000000 00000000 - ����� (2^32)
		�����: 1
		����� ������� ����, � ������: 0 1000000 00000000 00000000 00000000
		*/
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i % 8 == 0 || i == 1)
			putchar(' '); // ��������� ���� �� ����� ������, ���������� �������� �����, � ����� ��������� ����
	}
}

void floatToBinary(int value) {
	int mask = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		putchar(value & mask ? '1' : '0');
		value <<= 1;
		if (i == 1 || i == 9)
			putchar(' '); // ��������� ���� �� ����� ����� �������� � �������, � ����� ��������� ����
	}
}

void doubleToBinary(int firstPart, int secondPart) {
	int mask = 1 << 31;
	for (int i = 1; i <= 32; i++) {
		putchar(firstPart & mask ? '1' : '0');
		firstPart <<= 1;
		if (i == 1 || i == 12)
			putchar(' '); // ��������� ���� �� ����� ����� �������� � �������, � ����� ��������� ����
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
		// �������� �� ����� �����
		if (static_cast<int>(input) != input) {
			cout << "���������� ������ ����� ����� ��������� int! ���������� ��� ���...\n";
			continue;
		}
		return int(input);
	}
}

void intToBinary(int value, short notInvertedBits[]) {
	int mask = 1 << 31; // ����� ������������ ����� 2^32, �� ���� 10...00, ��� ����� 31.
	for (int i = 1; i <= 32; i++) {
		if (!arrayContains(i, notInvertedBits))
			putchar(value & mask ? '0' : '1'); // ��� ������������� ���� ����� �� ���� �������, ��� ��� �� ������ �����������.
		else
		{
			putchar(value & mask ? '1' : '0'); // ����� ��� �� �������������
		}
		value <<= 1;
		if (i % 8 == 0 || i == 1)
			putchar(' '); // ��������� ���� �� ����� ������, ���������� �������� �����, � ����� ��������� ����
	}
}

// ���� ���������� � ������� �������� ��������� � ����� ��������� �������, ������������ true, ����� false.
bool arrayContains(int i, short notInvertedBits[]) {
	for (short element : notInvertedBits) {
		if (element != 0) && (element = i)
			return true;
	}
	return false;
}