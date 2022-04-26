#pragma once
#include "pch.h"
//#include "Automat.h"
//#include "Slot.h"

using namespace std;

class Motor
{
private:
	int id;
public:
	Motor();
	Motor(int id);
	~Motor();
	void trigger();
};



