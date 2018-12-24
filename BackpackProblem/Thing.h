#pragma once
#include <iostream>
#include <string>
using namespace std;
class Thing {
	int weight;//Вес вещи
	int value;//Ценность вещи
	size_t amount;//Количество вещей данного типа
	const string name;//Название вещи
public:
	Thing(const int weight = 0, const int value = 0, const size_t amount = 0, const string name = nullptr)
		:weight(weight), value(value), amount(amount), name(name) {}
	~Thing() {}
	void printThing();
	
	int getWeight() {
		return weight;
	};

	int getValue() {
		return value;
	};

	size_t getAmount() {
		return amount;
	}

	void setAmount(size_t amount) {
		this->amount = amount;
	}
};