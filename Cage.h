#pragma once
#include"Animal.h"
#include"Group.h"
#include"Predator.h"
#include"Food.h"
#include"SpecificAnimal.h"

const unsigned int maxCap = 4;

class Cage
{
private:
	Animal** animals;
	char* nameC;
	char* landskape;
	int humidity;
	int flora;
	int latitude;
	int pos;
	void copy(const Cage& other);
	void clear();
	void setCharacteristics(const char* name);
public:
	Cage(const char* nameC = "");
	Cage(const Cage& other);
	Cage& operator=(const Cage& other);
	~Cage();
	bool addAnimal(const Animal* anim);
	const char* getNameC() const;
	const char* foodCage() const;
	const char* getSpecies() const;
	unsigned int sumKG() const;
	void createCage(const Animal* an);
	void printCharacteristics() const;
	bool printAnimal(const char* name) const;
};