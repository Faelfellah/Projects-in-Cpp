#include "pch.h"
#include "Slot.h"
#include <iostream>
//#include "Motor.h"
using namespace std;
Slot::Slot()
{
};


Slot::Slot(int slotId, string productName, int price, int motor1Id, int  motor2Id)
{
	this->id = slotId;
	this->productName = productName;
	this->price = price;
	this->motor1 = new Motor(motor1Id);
	if (motor2Id != 0) {
		this->motor2 = new Motor(motor2Id);
	}
	else {
		this->motor2 = nullptr;

	}
}

Slot::~Slot()
{
}
int Slot::getId() {
	return this->id;
};
void Slot::drop()
{
}