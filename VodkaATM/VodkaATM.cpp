// VodkaATM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include "ATM.h"
#include "Language.h"
using namespace std;

int main()
{
	SingleATM atm = SingleATM(123456, true, "Daegu", 500000);
}
