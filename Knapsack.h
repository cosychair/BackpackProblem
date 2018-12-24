#pragma once
#include "Queue.h"

class Knapsack {
	int maxWeight;//������������ ��� �������
	int weight;// ��� �������
	int value;//�������� �������
	Queue * things;
public:
	Knapsack(int maxWeight = 0) : maxWeight(maxWeight), weight(0), value(0), things(new Queue()) {}
	~Knapsack() {
		delete things;
	}
	//void put(Thing);//�������� ���� � ������
	//void remove(Thing);//������ ���� �� �������
	void fill(Queue * possibleThings);//���������� ���������� ������� ���������� �������� ��������� �������, ������������ ������������ ����������������
	void printContent();//����� � ������� ����������� �������
};