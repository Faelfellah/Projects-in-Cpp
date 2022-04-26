#pragma once
#include "pch.h"
#include "Slot.h"
#include <string>
#include "pch.h"
#include"Keypad.h"
#include"Dropcheck.h"
#include"CoinSlot.h"

using namespace std;

class Automat
{
private:
	Slot** slots;
	int numSlots;
	int numProductsPerSlot;
	Slot *cached;
	int insertPos;
	Keypad keypad;
	DropCheck dropcheck;
	CoinSlot coinslot;
	
public:
	Automat();


	Automat(int numSlots, int numProductsPerSlot);
	~Automat();
	Slot*  searchSlot(int slotId);
	bool addSlot(string  productName, int price, int slotId, int motorId1, int motorId2);
	
	void changeSlot(int ´slotId, string name, int price);
	string getproductName(int slotId);
	int getPrice(int slotId);
	int getNumPieces(int slotId);
	bool isAvailable(int slotId);
	bool dropSlot(int slotId);
	void fillAll();
	void fill(int  numProduct, int slotId);
	void run();
   
	
};