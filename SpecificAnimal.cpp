#include"SpecificAnimal.h"

SpecificAnimal::SpecificAnimal(const char * name, const char * group, const Food & f, const char * species)
	:Animal(name), Group(name, group), Predator(f, species, name)
{

}
SpecificAnimal::SpecificAnimal(const SpecificAnimal& other)
	: Animal(other), Group(other), Predator(other)
{

}
SpecificAnimal & SpecificAnimal::operator=(const SpecificAnimal & other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		Group::operator=(other);
		Predator::operator=(other);
	}
	return *this;
}


void SpecificAnimal::sound(const char* option) const
{
	if (!strcmp("Bear", getName())) cout << "Rooo" << endl;
	else if (!strcmp("White bear", getName())) cout << "Rooo" << endl;
	else if (!strcmp("Lion", getName())) cout << "Roar" << endl;
	else if(!strcmp("Tiger", getName())) cout << "Roar" << endl;
	else if(!strcmp("Lioness", getName())) cout << "Roar" << endl;
	else if(!strcmp("Canary", getName())) cout << "Chip chip" << endl;
	else if(!strcmp("Eagle", getName())) cout << "Hee" << endl;
	else if (!strcmp("Cobra", getName())) cout << "Sssss" << endl;
	else if (!strcmp("Viper", getName())) cout << "Sssss" << endl;
	else if (!strcmp("Shark", getName())) cout << "Soundless" << endl;
	else if (!strcmp("Puffer-fish", getName())) cout << "Soundless" << endl;
	else
	{
		cerr << "No such sound"<<endl;
		return;
	}
}

Animal* SpecificAnimal::clone() const
{
	return new SpecificAnimal(*this);
}

void SpecificAnimal::print() const
{
	Animal::print();
	Group::print();
	printFood();
	cout << "Species: " << getSpecies() << endl;
	cout << "The sound is: ";
	sound(getName());
}

unsigned int SpecificAnimal::eat() const
{
	return Predator::eat();
}

unsigned int SpecificAnimal::getKG() const
{
	return Predator::getKG();
}
