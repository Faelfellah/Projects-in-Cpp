#include "pch.h"
#include "DropCheck.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;
DropCheck::DropCheck()
{
}


DropCheck::~DropCheck()
{
}
bool DropCheck::productReleased() {
	int i = (rand() % 100) + 1;
	
	if (i <= 100 && i >= 90)
		return false;
	else
		return true;
}