#pragma once
#include<iostream>
using namespace std;
class Animal
{
private:
	char* name;
	void copy(const Animal& other);
public:
	Animal(const char* name = "");
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();
	virtual void sound(const char* option) const = 0;
	virtual Animal* clone() const = 0;
	const char* getName() const;
	virtual void print() const;
	virtual unsigned int eat() const = 0;
	virtual const char* getGroup() const = 0;
	virtual const char* getSpecies() const = 0;
	virtual unsigned int getKG() const=0;
	virtual const char* getFood() const = 0;
};