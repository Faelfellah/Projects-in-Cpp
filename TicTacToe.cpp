

#include "pch.h"
#include <iostream>
#include<array>
#include<string>
#include<vector>

using namespace std;

int BerechneGewinner(const vector<vector<int>> &feld)
{
	for (int i = 0; i <= 2; i++) {
		if ((feld.at(i).at(0) != 0) && (feld.at(i).at(0) == feld.at(i).at(1)) && (feld.at(i).at(0) == feld.at(i).at(2)))
		{
			return feld.at(i).at(0);
		}
	}
	
	for (int i = 0; i <= 2; i++)
	{
		if ((feld.at(0).at(i) != 0) && (feld.at(0).at(i) == feld.at(1).at(i)) && (feld.at(0).at(i) == feld.at(2).at(i)))
		{
			return feld.at(0).at(i) ;
		}
	}
	if ((feld.at(0).at(0) != 0) && (feld.at(0).at(0) == feld.at(1).at(1)) && (feld.at(0).at(0) == feld.at(2).at(2)))
	{
		return feld.at(0).at(0) ;
	}
	if ((feld.at(0).at(2) != 0) && (feld.at(0).at(2) == feld.at(1).at(1)) && (feld.at(0).at(2) == feld.at(2).at(0)))
	{
		return feld.at(0).at(2);
	}
	
	return 0;
}

int main(int argc, const char *argv[])
{
	vector<vector<int>> feld = {
		{ 2,  2,  2},
		{ 2,  1,  1 },
		{ 1,  1,  2 }
	};
	
	
	int gewinner = BerechneGewinner(feld);
	

	for (const auto& row : feld)
	{
		cout << " | ";
		for (const auto& item : row)
		{
			cout << item << " | ";
		}
		cout << endl;
	}
	cout << gewinner << "  hat das Spiel gewonnen!! " << endl;

	
}

