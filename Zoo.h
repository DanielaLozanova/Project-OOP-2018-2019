#pragma once
#include"Cage.h"
#include"FoodStorage.h"

class Zoo
{
private:
	FoodStorage fs;
	Cage* cages;
	int cap;
	int pos;
	void copy(const Zoo& other);
	void resize(int cap);
	bool rightCage(int j, const Animal* a) const;//.......
	bool isPredator(const char* cageEat, const char* aEat)const;
public:
	Zoo(int cap = 4);
	Zoo(const Zoo& other);
	Zoo& operator=(const Zoo& other);
	~Zoo();
	void addAnimal(const Animal* ani);//....
	void eat();
	int getPos() const;
	void printCage(const char* name) const;
	void printAnimal(const char* name) const;
};