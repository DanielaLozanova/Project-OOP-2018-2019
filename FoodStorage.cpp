#include "FoodStorage.h"

FoodStorage::FoodStorage()
{
	this->currFood = 0;
	this->isAvailable = false;
}

bool FoodStorage::hasEnoughFood(unsigned int kg) const
{
	if (!isAvailable)
	{
		return false;
	}
	if (currFood < kg)
	{
		return false;
	}
	return true;
}

void FoodStorage::resetStorage(unsigned int kg)
{
	if (isAvailable)
	{
		unsigned int diff = kg - currFood;
		currFood += diff;
	}
	else
	{
		currFood = kg;
	}
	isAvailable = true;
}

void FoodStorage::eat()
{
	isAvailable = false;
}
