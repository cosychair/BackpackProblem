/*
	Программа является курсовой работой студента группы 7302 Кириллова Даниила
	Вариант 3
	Задание: Реализовать решение задачи об ограниченном рюкзаке.
	Пусть имеется набор предметов, каждый из которых имеет два параметра — вес и ценность.
	Также имеется рюкзак определенной вместимости.
	Задача заключается в том, чтобы собрать рюкзак с максимальной ценностью предметов внутри,
	соблюдая при этом ограничение рюкзака на суммарный вес и ограничения на число экземпляров каждого предмета.
*/

#include "KnapsackFileInput.h"
#include "Knapsack.h"

int main() {
	cout << "Glad to see you." << endl
		<< "This is a coursework." << endl << endl
		<< "Author - Kirillov Daniil, gr. 7302, version 1.1." << endl << endl
		<< "Program solves the problem of Unbounded Knapsack." << endl;
	int knapsackSize = 0;//размер рюкзака
	try {
		List * things = readThingsInfoFromFile("resources/things.txt", knapsackSize);//создание списка вещей
		things->printToConsole();//Вывод списка в консоль
		Knapsack *sack = new Knapsack(knapsackSize);//создание рюкзака
		sack->fill(things);//Заполнение рюкзака
		sack->printContent();
		delete sack;//очистка памяти
		delete things;
	}
	catch (out_of_range  e) {
		cout << e.what();
	}
	catch (runtime_error e) {
		cout << e.what();
	}
}