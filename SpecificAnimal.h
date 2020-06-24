#pragma once
using namespace std;
#include"Animal.h"
#include"Group.h"
#include"Predator.h"
#include"Food.h"
const Food f1{ "meat",1 };
class SpecificAnimal :public Group, public Predator
{
public:
	SpecificAnimal(const char* name = "", const char* group = "", const Food& food = f1, const char* species = "");
	SpecificAnimal(const SpecificAnimal& other);
	SpecificAnimal& operator=(const SpecificAnimal& other);
	virtual ~SpecificAnimal() {};
	virtual void sound(const char* option) const;
	virtual Animal* clone() const;
	virtual void print() const;
	virtual unsigned int eat() const;
	virtual unsigned int getKG()const;
};