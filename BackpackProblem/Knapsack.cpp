#include "Knapsack.h"
#include <algorithm>

using namespace std;
void Knapsack::fill(List * possibleThings) {
	if (possibleThings->getSize() == 0) throw out_of_range("Error. List of things is empty.");
	size_t thingsAmount = 0;
	vector <Thing*> arrayOfThings;//создание массива из имеющегося списка, тк дальше буду нужны дискретные преобразоваия, нужны индексы
	for (Iterator *tmp = possibleThings->createIterator(); tmp->hasNext(); tmp->next()) {
		thingsAmount += tmp->current()->getAmount();
		for (int i = 0; i < tmp->current()->getAmount(); ++i)  //Туупа добавляем все посвторяющиеся элементы(можно красиво разбить и из линейной сложности сделать логарифмичесскую)
			arrayOfThings.push_back(tmp->current());
		arrayOfThings.back()->setAmount(1);//тк разбиваем, количество каждого = 1
	}
	vector <vector <int>>solutionsTable(thingsAmount, vector <int>(maxWeight, 0));
	int i = 0;

	for (size_t i = 1; i < thingsAmount; ++i)
		for (size_t w = 1; w < maxWeight; ++w) //вычисляем  ценности остльных столбцов
			if (arrayOfThings[i]->getWeight() <= w)//в зависимости от того, что больше берем значение из ряда выше, либо из столбца слева, прибавля стоимость
				solutionsTable[i][w] = max(arrayOfThings[i]->getValue() + solutionsTable[i - 1][w - arrayOfThings[i]->getWeight()], solutionsTable[i - 1][w]);
			else
				solutionsTable[i][w] = solutionsTable[i - 1][w];

	value = solutionsTable[thingsAmount - 1][maxWeight - 1];
	findThings(solutionsTable, arrayOfThings, thingsAmount - 1, maxWeight - 1);
}

void Knapsack::printContent() {
	cout << endl << "Total weight of filled knapsack is " << weight << "." << endl
		 << "Total value of filled knapsack is " << value << "." << endl;
	things->printToConsole();
}

void Knapsack::findThings(const vector<vector<int>> solutionsTable, const vector<Thing*> arrayOfThings, size_t k, int s){
	if (solutionsTable[k][s] == 0)//Выход из рекурсии
		return;
	if (solutionsTable[k - 1][s] == solutionsTable[k][s])//не берем элемент
		findThings(solutionsTable, arrayOfThings, k - 1, s);
	else {
		findThings(solutionsTable, arrayOfThings, k - 1, s - arrayOfThings[k]->getWeight());//йес, попався
		if (!things->isEmpty() && things->back() == arrayOfThings[k]) {//проверка на совпадения
			arrayOfThings[k]->setAmount(arrayOfThings[k]->getAmount() + 1);
			things->popBack();
		}
		things->pushBack(arrayOfThings[k]);//Добавление элемента
		weight += arrayOfThings[k]->getWeight();
	}
}
