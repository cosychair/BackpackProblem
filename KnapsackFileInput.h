#pragma once
#include "Thing.h"
#include "Queue.h"
#include <stdexcept>

//������� ��������� ������ �� �����
Queue * readThingsInfoFromFile(const char* const fileName, int & knapsackSize);
