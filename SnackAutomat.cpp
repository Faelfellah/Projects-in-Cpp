


#include "pch.h"
#include <iostream>
#include <time.h>
#include"windows.h"
#include "Automat.h"
#include "slot.h"
#include "Motor.h"
#include "CoinSlot.h"
#include "Keypad.h"
#include "DropCheck.h"
#include <iomanip>
#include<vector>

using namespace std;


int main()
{
	vector<string> Produkte =
	{ " 1: Snickers   ***  1.50 euro "," 2: Mars   ***  1.50 euro"," 3: Kinder bueno    ***   1.80 euro",
	" 4: twix  ***  1.70 euro "," 5: Oreo   ***  1.50 euro"," 6: coca cola    ***   1.90 euro",
		" 7: Sprite   ***  1.90 euro "," 8: Vittel  ***  1.90 euro"
	};
	
	Automat meinAutomat(10, 10);
	
	meinAutomat.addSlot("Snickers", 150, 1, 1, 0);
	meinAutomat.addSlot("Mars", 150, 2, 2, 1);
	meinAutomat.addSlot("kinder bueno", 180, 3, 3, 2);
	meinAutomat.addSlot("twix", 170, 4, 4, 2);
	meinAutomat.addSlot("Oreo", 150, 5, 5, 0);
	meinAutomat.addSlot("coca cola", 190, 6, 6, 1);
	meinAutomat.addSlot("sprite", 190, 7, 7, 2);
	meinAutomat.addSlot("Vittel", 190, 8, 8, 2);
   
	meinAutomat.fillAll();
	for (const auto& row : Produkte)
	{
		for (const auto& item : row)
		{
			cout << item;
		}
		cout << endl;
	}
	
	

	fixed;
	setprecision(2);
	meinAutomat.run();
	
   
}