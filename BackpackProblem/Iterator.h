#pragma once
#include "Thing.h"
class Iterator {
public:
	virtual void next() = 0;
	virtual bool hasNext() = 0;
	virtual Thing* current() = 0;
};