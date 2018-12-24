#pragma once
#include <iostream>
#include <string>
using namespace std;
class Thing {
	int weight;//��� ����
	int value;//�������� ����
	size_t amount;//���������� ����� ������� ����
	const string name;//�������� ����
public:
	Thing(const int weight = 0, const int value = 0, const size_t amount = 0, const string name = nullptr)
		:weight(weight), value(value), amount(amount), name(name) {}
	~Thing() {}
	void printThing();
};