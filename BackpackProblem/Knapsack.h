#pragma once
#include "Thing.h"
#include "List.h"
#include <vector>
using namespace std;

class Knapsack {
private:
	const int maxWeight;//Максимальный вес рюкзака
	int weight;// вес рюкзака
	int value;//Ценность рюкзака
	List * things;
	void findThings(const vector <vector <int>>solutionsTable, const vector <Thing*> arrayOfThings, size_t k, int s);//функция для восстановления добавленных по ценности предметов
public:
	Knapsack(int maxWeight = 0) : maxWeight(maxWeight), weight(0), value(0), things(new List()){}
	~Knapsack() {}
	//void put(Thing);//Положить вещь в рюкзак
	//void remove(Thing);//Убрать вещь из рюкзака
	void fill(List * possibleThings);//Заполнение предметами дающими наибольшую итоговую стоимость рюкзака, используется динамическое программирование
	void printContent();//Вывод в консоль содержимого рюкзака
	//ниже функции для тестов!
	int getValue() {
		return value;
	}
	
	int getWeight() {
		return weight;
	}

	List * getList() {
		return things;
	}
};