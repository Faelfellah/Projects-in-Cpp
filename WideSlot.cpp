#include "pch.h"
#include "WideSlot.h"
#include <iostream>
using namespace std;
WideSlot::WideSlot(int slotId, string productName, int price, int motor1Id, int motor2Id) :Slot(slotId, productName, price, motor1Id, motor2Id)
{
	this->motor1 = new Motor(motor1Id);
	this->motor2 = new Motor(motor2Id);
}

WideSlot::~WideSlot()
{
}

void WideSlot::drop()
{
	motor1->trigger();
	motor2->trigger();
	cout << this->productName << " aus Fach " << this->id << " ausgeworfen" << endl;
}
