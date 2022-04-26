#pragma once
#include "Slot.h"
class SmallSlot :public Slot
{
private:
	Motor *motor1;
public:
	SmallSlot(int slotId, string productName, int price, int mmotor1Id, int motor2Id);
	~SmallSlot();
	void drop();
};

