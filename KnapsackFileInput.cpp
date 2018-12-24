#include "KnapsackFileInput.h"
#include <fstream>
#include <cstdlib>
#include <sstream>

Thing* readThing(ifstream& inFile) {
	string str, name;
	try {
		getline(inFile, str);//Считывание строки в буффер
		stringstream strStream;//Создание потока для выделения строки из всего текста
		strStream << str;
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str, '*');//Считывание названия вещи
		name = str;//Название вещи
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str, '*');//Считывание веса вещи 
		int weight = stoi(str);//Вес вещи
		if (weight < 0)throw runtime_error("Error. Weight must be positive. Line ");
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str, '*');//Считывание ценности вещи
		int value = stoi(str);//Ценность вещи
		if (value < 0)throw runtime_error("Error. Value must be positive. Line ");
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str);//Считывание количества вещи
		int amount = stoi(str);//Количество вещей данного типа
		if (amount < 0)throw runtime_error("Error. Amount must be positive. Line ");

		return new Thing(weight, value, amount, name);
	}
	catch (invalid_argument e) {
		throw out_of_range("Error. Subject construction error. Line ");
	}
}

Queue * readThingsInfoFromFile(const char* const fileName, int & knapsackSize) {
	Queue * things = new Queue();
	ifstream inFile(fileName, ios::in);
	if (inFile.is_open()) {
		string tmp;//временный "буфер" для обработки ошибок при чтении
		getline(inFile,tmp);//Чтение количества вещей
		int amountOfThings;
		try {
			amountOfThings = stoi(tmp);
			if (amountOfThings <= 0) throw runtime_error("Error. Amount of things must be positive.");
			getline(inFile, tmp);//Чтение размера рюкзака
			knapsackSize = stoi(tmp);
			if (knapsackSize <= 0) throw runtime_error("Error. Knapsack`s size must be positive.");
		}
		catch (invalid_argument e) {
			throw out_of_range("Error. Amount of things and knapsack`s size must exist.");
		}
		int i = 0;
		try {
			while (!inFile.eof() && amountOfThings > i++)
				things->pushBack(readThing(inFile));//Считывание информации о вещах, добавление ее в список
		}
		catch (out_of_range e) {
			string exptn = e.what();
			exptn += (i + '0');// Формирование строки для вывода ошибки
			throw  out_of_range(exptn);
		}
		catch (runtime_error e) {
			string exptn = e.what();
			exptn += (i + '0');// Формирование строки для вывода ошибки
			throw  runtime_error(exptn);
		}
		//if (i < amountOfThings)throw runtime_error("Warning. Amount of things is higher than list of ones.");
	}
	else
		throw runtime_error("Error. Can`t open the input file.");
	inFile.close();
	return things;
}