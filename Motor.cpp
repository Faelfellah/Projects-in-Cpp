#include "pch.h"
#include "Motor.h"
#include <iostream>
using namespace std;
Motor::Motor()
{
	
};
Motor::Motor(int id)
{
	this->id = id;
};


Motor::~Motor()
{

};

void Motor::trigger()
{
	cout << "Motor <" << this->id << "> aktiviert " << endl;
};
