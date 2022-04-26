#include "pch.h"
#include "SmallSlot.h"
#include <iostream>
using namespace std;
SmallSlot::SmallSlot(int slotId, string productName, int price, int motor1Id, int motor2Id) :Slot(slotId, productName, price, motor1Id, motor2Id){
	
	this->motor1 = new Motor(motor1Id);
}


SmallSlot::~SmallSlot()
{
}
void SmallSlot::drop() {
	this->motor1->trigger();
	cout << this->productName << " aus Fach " << this->id << " ausgeworfen" << endl;
}