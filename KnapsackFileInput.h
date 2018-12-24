#pragma once
#include "Thing.h"
#include "Queue.h"
#include <stdexcept>

//Функция получения данных из файла
Queue * readThingsInfoFromFile(const char* const fileName, int & knapsackSize);
