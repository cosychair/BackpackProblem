#pragma once
#include "Thing.h"
#include "List.h"
#include <stdexcept>
using namespace std;
//Функция получения данных из файла
List * readThingsInfoFromFile(const char* const fileName, int & knapsackSize);
