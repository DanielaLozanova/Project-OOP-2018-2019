#include "Food.h"

void Food::copy(const Food & other)
{
	this->food = new char[strlen(other.food) + 1];
	strcpy(this->food, other.food);
	this->kg = other.kg;
}

Food::Food(const char * food, unsigned int kg)
{
	setFood(food, kg);
}

Food::Food(const Food & other)
{
	copy(other);
}

Food & Food::operator=(const Food & other)
{
	if (this != &other)
	{
		delete[] food;
		copy(other);
	}
	return *this;
}

Food::~Food()
{
	delete[] food;
}

void Food::setFood(const char * food, unsigned int kg)
{	
	this->food = new char[strlen(food) + 1];
	strcpy(this->food, food);
	this->kg = kg;
}

const char* Food::getFood() const
{
	return food;
}


unsigned int Food::getKG() const
{
	return kg;
}