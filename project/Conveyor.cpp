// Лабораторная работа №1 по дисциплине МРЗвИС
// Выполнена студентом группы 821701
// БГУИР Залесским Алексанром Андреевичем и Киселёвым Никитой Владимировичем
// Реализация класса

#include "Conveyor.h"
using namespace std;



void Conveyor::additional(bool value[12], int index) {
	int temp1[12], temp2[12];
	bool tempo[12];
	for (int i = 0; i < 12; i++) {
		temp1[i] = vect[index].arr[i];
		temp2[i] = value[i];
	}
	for (int i = 11; i >= 0; i--) {
		temp1[i] += temp2[i];
		if (temp1[i] == 2) {
			temp1[i - 1] += 1;
			temp1[i] = 0;
		}
		if (temp1[i] == 3) {
			temp1[i - 1] += 1;
			temp1[i] = 1;
		}
	}
	for (int i = 0; i < 12; i++) { tempo[i] = temp1[i]; }
	push(tempo);
}

void Conveyor::setVectValue() {
	bool temp[12];
	for (int i = 0; i < 12; i++) temp[i] = 0;
	for (int i = 5; i >= 0; i--) {
		if (secondNumber[5]) temp[i + 6] = firstNumber[i];
		else temp[i + 6] = 0;
	}
	push(temp);					
	push(temp);					
	push(temp);					
	for (int i = 0; i < 12; i++) temp[i] = 0;
	for (int i = 5; i >= 0; i--) {
		if (secondNumber[4]) temp[i + 6] = firstNumber[i];
		else temp[i + 6] = 0;
	}
	push(temp);					
	rightShift(temp);
	push(temp);					
	additional(temp, 2);		
	for (int i = 0; i < 12; i++) temp[i] = 0;
	for (int i = 5; i >= 0; i--) {
		if (secondNumber[3]) temp[i + 6] = firstNumber[i];
		else temp[i + 6] = 0;
	}
	push(temp);					
	rightShift(temp);
	rightShift(temp);
	push(temp);					
	additional(temp, 5);		
	for (int i = 0; i < 12; i++) temp[i] = 0;
	for (int i = 5; i >= 0; i--) {
		if (secondNumber[2]) temp[i + 6] = firstNumber[i];
		else temp[i + 6] = 0;
	}
	push(temp);					
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	push(temp);					
	additional(temp, 8);		
	for (int i = 0; i < 12; i++) temp[i] = 0;
	for (int i = 5; i >= 0; i--) {
		if (secondNumber[1]) temp[i + 6] = firstNumber[i];
		else temp[i + 6] = 0;
	}
	push(temp);					
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	push(temp);					
	additional(temp, 11);		
	for (int i = 0; i < 12; i++) temp[i] = 0;
	for (int i = 5; i >= 0; i--) {
		if (secondNumber[0]) temp[i + 6] = firstNumber[i];
		else temp[i + 6] = 0;
	}
	push(temp);					
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	rightShift(temp);
	push(temp);					
	additional(temp, 14);		
}


void Conveyor::showVector(int index) {
	for (int i = 0; i < 12; i++) {
		cout << vect[index].arr[i];
		if (i == 5) cout << " ";
	}
}


void Conveyor::push(bool ar[12]) {
	container cont;
	for (int i = 0; i < 12; i++) {
		cont.arr[i] = ar[i];
	}
	vect.push_back(cont);
}


void Conveyor::rightShift(bool mas[12]) {
	for (int i = 0; i < 11; i++) {
		bool temp = mas[i];
		mas[i] = mas[i + 1];
		mas[i + 1] = temp;
	}
}

void Conveyor::showInitialCondition() {
	cout << "\n\nПервый множитель: " << setw(2) << firstN << " = ";
	showFirst();
	cout << endl;
	cout << "Второй множитель: " << setw(2) << secondN << " = ";
	showSecond();
	cout << endl;
}


void Conveyor::showFirst() {
	for (int i = 0; i < 6; i++) {
		cout << firstNumber[i];
	}
}


void Conveyor::showSecond() {
	for (int i = 0; i < 6; i++) {
		cout << secondNumber[i];
	}
}

void Conveyor::showTable(int counter) {
	switch (counter) {
	default: cout << "     -----               |               -----             |                 -----             |" << endl;
		break;
	}
}

void Conveyor::setResult() {
	for (int i = 11, j = 0; i >= 0; i--, j++) {
		Result += vect[17].arr[i] * pow(2, j);
	}
}

void Conveyor::showResult(int numOfpair) {
	cout << numOfpair + 1 << " пара: " << setw(2) << firstN << " * " << setw(2) << secondN << " = " << setw(3) << Result << " = ";
	for (int i = 0; i < 12; i++) {
		cout << vect[17].arr[i];
		if (i == 5)cout << " ";
	}
	cout << endl;
}