#include "pch.h"
#include "CoinSlot.h"
#include <iostream>
#include "Automat.h"
#include "Keypad.h"

using namespace std;
CoinSlot::CoinSlot()
{
	this->insertedAmount = 0;
}


CoinSlot::~CoinSlot()
{
}
int CoinSlot::updateCoinAutomat() {
	static float i = 0;
	int a=0;
	
		cout << " bitte der Rest einwerfen oder mit -1 abbrechen " << endl;
		if (this->insertedAmount == 0 && this->insertedAmount != -1) {
			i = 0;
			clear();
			cin >> insertedAmount;
			if (insertedAmount != -1) {
				i = i + (insertedAmount * 100);
				insertedAmount = i;
				return (int)insertedAmount;
				cin >> insertedAmount;
			}
			else return (int)insertedAmount;
		}


		else if (insertedAmount != 0 && insertedAmount != -1) {
			cin >> insertedAmount;
			if (insertedAmount != -1) {
				i = i + (insertedAmount * 100);
				insertedAmount = i;

				return(int)insertedAmount;
			}
			else
				return (int)insertedAmount;
		}

		else
			return (int)insertedAmount;
	
}
int CoinSlot::getCoinAutomat() {
	return (int)insertedAmount;
}
void CoinSlot::clear() {
	insertedAmount = 0;
}
void CoinSlot::returnCoins(int price) {
	
	int rueckgeld = getCoinAutomat() - price;
	for (int i = 0; i < 8; i++) {
		int zahl = 0;
		while (rueckgeld != 0 && (rueckgeld / cointValue[i]) != 0) {
			rueckgeld = rueckgeld - cointValue[i];
			zahl++;
		}
		if (zahl != 0 && cointValue[i] >= 100)
			cout << zahl << " x " << (float)cointValue[i] / 100 << " euro" << endl;
		else if (zahl != 0 && cointValue[i] <= 100)
			cout << zahl << " x " << (float)cointValue[i] / 100 << " cent" << endl;
	}
}