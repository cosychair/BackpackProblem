#include "KnapsackFileInput.h"
#include <fstream>
#include <cstdlib>
#include <sstream>

Thing* readThing(ifstream& inFile) {
	string str, name;
	try {
		getline(inFile, str);//���������� ������ � ������
		stringstream strStream;//�������� ������ ��� ��������� ������ �� ����� ������
		strStream << str;
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str, '*');//���������� �������� ����
		name = str;//�������� ����
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str, '*');//���������� ���� ���� 
		int weight = stoi(str);//��� ����
		if (weight < 0)throw runtime_error("Error. Weight must be positive. Line ");
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str, '*');//���������� �������� ����
		int value = stoi(str);//�������� ����
		if (value < 0)throw runtime_error("Error. Value must be positive. Line ");
		if (strStream.eof())throw runtime_error("Error. Not trully complete line. Line ");
		getline(strStream, str);//���������� ���������� ����
		int amount = stoi(str);//���������� ����� ������� ����
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
		string tmp;//��������� "�����" ��� ��������� ������ ��� ������
		getline(inFile,tmp);//������ ���������� �����
		int amountOfThings;
		try {
			amountOfThings = stoi(tmp);
			if (amountOfThings <= 0) throw runtime_error("Error. Amount of things must be positive.");
			getline(inFile, tmp);//������ ������� �������
			knapsackSize = stoi(tmp);
			if (knapsackSize <= 0) throw runtime_error("Error. Knapsack`s size must be positive.");
		}
		catch (invalid_argument e) {
			throw out_of_range("Error. Amount of things and knapsack`s size must exist.");
		}
		int i = 0;
		try {
			while (!inFile.eof() && amountOfThings > i++)
				things->pushBack(readThing(inFile));//���������� ���������� � �����, ���������� �� � ������
		}
		catch (out_of_range e) {
			string exptn = e.what();
			exptn += (i + '0');// ������������ ������ ��� ������ ������
			throw  out_of_range(exptn);
		}
		catch (runtime_error e) {
			string exptn = e.what();
			exptn += (i + '0');// ������������ ������ ��� ������ ������
			throw  runtime_error(exptn);
		}
		//if (i < amountOfThings)throw runtime_error("Warning. Amount of things is higher than list of ones.");
	}
	else
		throw runtime_error("Error. Can`t open the input file.");
	inFile.close();
	return things;
}