#include "Predator.h"

void Predator::copy(const Predator & other)
{
	this->f = other.f;
	this->species = new char[strlen(other.species) + 1];
	strcpy(this->species, other.species);
}

Predator::Predator(const Food& f,const char * species,const char* name)
	:Animal(name)
{
	this->f = f;
	this->species = new char[strlen(species) + 1];
	strcpy(this->species, species);
}

Predator::Predator(const Predator & other)
	:Animal(other)
{
	copy(other);
}

Predator & Predator::operator=(const Predator & other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete[] species;
		copy(other);
	}
	return *this;
}

Predator::~Predator()
{
	delete[] species;
}

void Predator::printFood() const
{
	cout << "Food: " << f.getFood() << endl;
	cout << "kg: " << f.getKG() << endl;
}

const char * Predator::getSpecies() const
{
	return species;
}

unsigned int Predator::eat() const
{
	return f.getKG();
}

unsigned int Predator::getKG() const
{
	return f.getKG();
}

const char * Predator::getFood() const
{
	return f.getFood();
}
