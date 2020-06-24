#include "Cage.h"

void Cage::copy(const Cage& other)
{
	this->nameC = new char[strlen(other.nameC) + 1];
	strcpy(this->nameC, other.nameC);
	this->landskape = new char[strlen(other.landskape) + 1];
	strcpy(this->landskape, other.landskape);
	this->humidity = other.humidity;
	this->flora = other.flora;
	this->latitude = other.latitude;
	this->animals = new Animal*[maxCap];
	for (int i = 0; i < other.pos; ++i)
	{
		this->animals[i] = other.animals[i]->clone();
	}
	this->pos = other.pos;
}

void Cage::clear()
{
	for (int i = 0; i < pos; ++i)
	{
		delete animals[i];
	}
	delete[] animals;
}

void Cage::setCharacteristics(const char * name)
{
	if (!strcmp(name, "Forest"))
	{
		this->landskape = new char[strlen("Roky") + 1];
		strcpy(this->landskape, "Roky");
		this->humidity = 30;
		this->flora = 50;
		this->latitude = 20;
	}
	if (!strcmp(name, "Savannah"))
	{
		this->landskape = new char[strlen("Plain") + 1];
		strcpy(this->landskape, "Plain");
		this->humidity = 45;
		this->flora = 40;
		this->latitude = -40;
	}
	if (!strcmp(name, "Pole"))
	{
		this->landskape = new char[strlen("Frozen") + 1];
		strcpy(this->landskape, "Frozen");
		this->humidity = 30;
		this->flora = 5;
		this->latitude = 90;
	}
	if (!strcmp(name, "Jungle"))
	{
		this->landskape = new char[strlen("Roky") + 1];
		strcpy(this->landskape, "Roky");
		this->humidity = 60;
		this->flora = 70;
		this->latitude = 0;
	}
	if (!strcmp(name, "Aquarium"))
	{
		this->landskape = new char[strlen("Roky") + 1];
		strcpy(this->landskape, "Roky");
		this->humidity = 100;
		this->flora = 20;
		this->latitude = -1300;
	}
	if (!strcmp(name, "Terrarium"))
	{
		this->landskape = new char[strlen("Roky") + 1];
		strcpy(this->landskape, "Roky");
		this->humidity = 20;
		this->flora = 20;
		this->latitude = -1300;
	}
}

Cage::Cage(const char * nameC)
{
	this->nameC = new char[strlen(nameC) + 1];
	strcpy(this->nameC, nameC);
	setCharacteristics(nameC);
	this->animals = new Animal*[maxCap];
	this->pos = 0;
}

Cage::Cage(const Cage & other)
{
	copy(other);
}

Cage & Cage::operator=(const Cage & other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}
	return *this;
}

Cage::~Cage()
{
	clear();
}

bool Cage::addAnimal(const Animal * anim)
{
	if (maxCap == pos)
	{
		return false;
	}
	animals[pos++] = anim->clone();
	return true;
}

const char * Cage::getNameC() const
{
	return nameC;
}

const char * Cage::foodCage() const
{
	return animals[0]->getFood();
}

const char * Cage::getSpecies() const
{
	return animals[0]->getSpecies();
}

unsigned int Cage::sumKG() const
{
	unsigned int sum = 0;
	for (int i = 0; i < pos; ++i)
	{
		sum += animals[i]->getKG();
	}
	return sum;
}


void Cage::createCage(const Animal *an)
{
	if (!strcmp(an->getGroup(), "Forest animal"))
	{
		this->nameC = new char[strlen("Forest") + 1];
		strcpy(this->nameC,"Forest");
		setCharacteristics(nameC);
	}
	if (!strcmp(an->getGroup(), "Savannah animal"))
	{
		this->nameC = new char[strlen("Savannah") + 1];
		strcpy(this->nameC, "Savannah");
		setCharacteristics(nameC);
	}
	if (!strcmp(an->getGroup(), "Pole animal"))
	{
		this->nameC = new char[strlen("Pole") + 1];
		strcpy(this->nameC, "Pole");
		setCharacteristics(nameC);
	}
	if (!strcmp(an->getGroup(), "Jungle animal"))
	{
		this->nameC = new char[strlen("Jungle") + 1];
		strcpy(this->nameC, "Jungle");
		setCharacteristics(nameC);
	}
	if (!strcmp(an->getGroup(), "Sea animal"))
	{
		this->nameC = new char[strlen("Aquarium") + 1];
		strcpy(this->nameC, "Aquarium");
		setCharacteristics(nameC);
	}
	if (!strcmp(an->getGroup(), "Reptile animal"))
	{
		this->nameC = new char[strlen("Terrarium") + 1];
		strcpy(this->nameC, "Terrarium");
		setCharacteristics(nameC);
	}
}

void Cage::printCharacteristics() const
{

	cout << "The landskape is: " << landskape << endl;
	cout << "The humidity is: " << humidity << endl;
	cout << "The flora is: " << flora << endl;
	cout << "The latitude is: " << latitude << endl;
}

bool Cage::printAnimal(const char * name) const
{
	for (int i = 0; i < pos; ++i)
	{
		if (!strcmp(animals[i]->getName(), name))
		{
			animals[i]->print();
			return true;
		}
	}
	return false;
}
