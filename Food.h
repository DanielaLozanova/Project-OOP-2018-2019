#pragma once
#include<iostream>

class Food
{
private:
	char* food;
	unsigned int kg;
	void copy(const Food& other);
public:
	Food(const char* food = "", unsigned int kg = 0);
	Food(const Food& other);
	Food& operator=(const Food& other);
	~Food();
	void setFood(const char* food, unsigned int kg);
	const char* getFood() const;
	unsigned int getKG() const;
};