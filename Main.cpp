/*
	��������� �������� �������� ������� �������� ������ 7302 ��������� �������
	������� 3
	�������: ����������� ������� ������ �� ������������ �������.
	����� ������� ����� ���������, ������ �� ������� ����� ��� ��������� � ��� � ��������.
	����� ������� ������ ������������ �����������.
	������ ����������� � ���, ����� ������� ������ � ������������ ��������� ��������� ������,
	�������� ��� ���� ����������� ������� �� ��������� ��� � ����������� �� ����� ����������� ������� ��������.
*/

#include "KnapsackFileInput.h"
#include "Knapsack.h"

int main() {
	cout << "Glad to see you." << endl
		<< "This is a coursework." << endl << endl
		<< "Author - Kirillov Daniil, gr. 7302, version 1.1." << endl << endl
		<< "Program solves the problem of Unbounded Knapsack." << endl;
	int knapsackSize = 0;//������ �������
	try {
		Queue * things = readThingsInfoFromFile("resour�es/things.txt", knapsackSize);//�������� ������ �����
		//things->printToConsole();//����� ������ � �������
		Knapsack *sack = new Knapsack(knapsackSize);//�������� �������
		sack->fill(things);//���������� �������
		delete things;//������� ������
		delete sack;
	}
	catch (out_of_range  e) {
		cout << e.what();
	}
	catch (runtime_error e) {
		cout << e.what();
	}
}