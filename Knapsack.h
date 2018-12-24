#pragma once
#include "Queue.h"

class Knapsack {
	int maxWeight;//Максимальный вес рюкзака
	int weight;// вес рюкзака
	int value;//Ценность рюкзака
	Queue * things;
public:
	Knapsack(int maxWeight = 0) : maxWeight(maxWeight), weight(0), value(0), things(new Queue()) {}
	~Knapsack() {
		delete things;
	}
	//void put(Thing);//Положить вещь в рюкзак
	//void remove(Thing);//Убрать вещь из рюкзака
	void fill(Queue * possibleThings);//Заполнение предметами дающими наибольшую итоговую стоимость рюкзака, используется динамическое программирование
	void printContent();//Вывод в консоль содержимого рюкзака
};