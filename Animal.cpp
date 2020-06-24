#include"Animal.h"

Animal::Animal(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Animal::copy(const Animal& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}
Animal::Animal(const Animal& other)
{
	copy(other);
}
Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		delete[] name;
		copy(other);
	}
	return *this;
}
Animal::~Animal()
{
	delete[] name;
}
const char* Animal::getName()const
{
	return name;
}

void Animal::print() const
{
	cout << "Animal name: " << getName() << endl;
}
