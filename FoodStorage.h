#pragma once
#include<iostream>
using namespace std;

class FoodStorage
{
	unsigned int currFood;
	bool isAvailable;
public:
	FoodStorage();
	bool hasEnoughFood(unsigned int kg) const;
	void resetStorage(unsigned int kg);
	void eat();
};