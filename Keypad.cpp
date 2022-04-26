#include "pch.h"
#include "Keypad.h"
#include <iostream>

using namespace std;

Keypad::Keypad()
{
	
}


Keypad::~Keypad()
{
}
int Keypad::getSelection() {
	static int eingabe =0;
	cout << "Bitte waehlen Sie Id des Faches oder mit -1 abrrechen" << endl;
	cin >> eingabe;
	if (eingabe != -1)
		return eingabe;
	else
		return -1;
}


