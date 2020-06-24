#pragma once
using namespace std;
#include"Animal.h"
#include"Food.h"
const Food f2{ "meat",1 };
class Predator :virtual public Animal
{
private:
	Food f;
	char* species;
	void copy(const Predator& other);
public:
	Predator(const Food& food = f2,const char* species = "",const char* name = "");
	Predator(const Predator& other);
	Predator& operator=(const Predator& other);
	virtual ~Predator();
	virtual void sound(const char* option) const = 0;
	virtual Animal* clone() const = 0;
	void printFood() const;
	virtual const char* getSpecies() const;
	virtual unsigned int eat() const;
	virtual unsigned int getKG() const;
	virtual const char* getFood() const;
};