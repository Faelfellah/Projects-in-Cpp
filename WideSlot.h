#pragma once
#include "Slot.h"
class WideSlot :public Slot
{
private:
	Motor *motor1;
	Motor *motor2;
public:
	WideSlot(int slotId, string productName, int price, int motor1Id, int motor2Id);
	~WideSlot();
	void drop();
};

