#pragma once
#include "Automat.h"
#include "Keypad.h"
#include<array>
class CoinSlot
{
private:
    float insertedAmount;
	array <int,8> cointValue = { 200,100,50,20,10,5,1 };
	Automat automatgeld;
	Keypad key;
	
public:
	CoinSlot();

	~CoinSlot();
	int updateCoinAutomat();
	int getCoinAutomat();
	void clear();
	void returnCoins(int price);

};

