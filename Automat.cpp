#include "pch.h"
#include "Automat.h"
#include "Slot.h"
#include "SmallSlot.h"
#include "WideSlot.h"
#include <iostream>
#include <Windows.h>
#include<string>
#include<vector>

using namespace std;


typedef enum {
	IDLE,
	COLLECT_MONEY,
	DROP,
	RETURN_MONEY,
}zustand;

Automat::Automat()
{
};

Automat::Automat(int numSlots, int numProductsPerSlot)
{
	this->numSlots = numSlots;
	this->numProductsPerSlot = numProductsPerSlot;
	this->slots = new Slot*[this->numSlots];
	this->insertPos = 0;
};

Automat::~Automat()
{
	
};
string Automat::getproductName(int slotId) {

	if (this->searchSlot(slotId) != nullptr) {
		return this->cached->getProductsName();
	}
	else
		return nullptr;
}
Slot* Automat::searchSlot(int slotId)
{
	if (cached != nullptr  && cached->getId() == slotId)
	{
		return cached;
	}

	for (int i = 0; i < insertPos; i++) {

		if (slots[i]->getId() == slotId) {
			cached = slots[i];
			return cached;
		}
	}
	return nullptr;
};

bool Automat::addSlot(string productName, int price, int slotId, int motorId1, int motorId2)
{
	if (insertPos < numSlots) {
		if (motorId2 == 0) {
			slots[insertPos++] = new SmallSlot(slotId, productName, price, motorId1, motorId2);
			return true;
		}
		else {
			slots[insertPos++] = new WideSlot(slotId, productName, price, motorId1, motorId2);
			return true;
		}
	}
	
	else
	{

		return false;
	}

}

void Automat::changeSlot(int slotId, string name, int price)
{
	if (searchSlot(slotId) != nullptr)
	{
		cached->setProductsName(name);
		cached->setPrice(price);
	}
}
int Automat::getPrice(int slotId)
{
	if (searchSlot(slotId) != nullptr) {
		return cached->getPrice();
	}
	return 0;
}
int Automat::getNumPieces(int slotId)
{
	if (searchSlot(slotId) != nullptr) {
		return cached->getNumProducts();
	}
	return 0;
}
bool Automat::isAvailable(int slotId)
{
	if (searchSlot(slotId) != nullptr) {
		if (cached->getNumProducts() > 0)
			return true;
	}
	return false;
}

bool Automat::dropSlot(int slotId)
{
	if (isAvailable(slotId) == true) {
		cached->drop();
		return true;
	}

	return false;

}
void Automat::fillAll()
{
	for (int i = 0; i < insertPos; i++) {
		fill(numProductsPerSlot, i);
	}
}


void Automat::fill(int numProduct, int slotId)
{
	if (searchSlot(slotId) != nullptr) {
		cached->setNumProducts(numProduct);
	}
}
void Automat::run()
{
	zustand setate = IDLE;
	int fortsetzen = 0;
	int eingabe = 0;
	
	
	
	while (fortsetzen != -1) {

		switch (setate) {
		case IDLE:
			if (fortsetzen == 0)
				eingabe = keypad.getSelection();
			while (isAvailable(eingabe) != true && eingabe != -1) {
				cout << "Bitte waehlen Sie eine Id aus oder mit -1 abbrechen " << endl;
				cin >> eingabe;
			}
			if (eingabe == -1) {
				fortsetzen = -1;
				break;
			}
		case COLLECT_MONEY:

			cout << getproductName(eingabe) << "  wurde ausgewaehlt " << endl;

			cout << " Es kostet " << (float)getPrice(eingabe) / 100 << " Euro" << endl;
			if (coinslot.getCoinAutomat() != -1) {
				coinslot.updateCoinAutomat();
				while (coinslot.getCoinAutomat() < getPrice(eingabe) && fortsetzen == 0 && coinslot.getCoinAutomat() != -1) {
					cout << ((float)getPrice(eingabe) / 100) - ((float)coinslot.getCoinAutomat() / 100) << " euro " << "noch zu zahlen " << endl;
					coinslot.updateCoinAutomat();
				}

				if (coinslot.getCoinAutomat() == -1) {
					coinslot.clear();
					break;
				}
		case DROP:
			if (coinslot.getCoinAutomat() != -1) {
				dropSlot(eingabe);

			}
			if (dropcheck.productReleased() == false) {
				fortsetzen = 1;
				break;
			}
		case RETURN_MONEY:
			fortsetzen = 0;
			coinslot.returnCoins(getPrice(eingabe));
			coinslot.clear();
			coinslot.clear();
			break;
			}

		}


	}
	cout << " bye bye !!" << endl;
}

;