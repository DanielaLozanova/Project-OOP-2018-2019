#include "Zoo.h"

void Zoo::copy(const Zoo & other)
{
	fs = other.fs;
	this->cages = new Cage[other.cap];
	for (int i = 0; i < other.pos; ++i)
	{
		this->cages[i] = other.cages[i];
	}
	this->cap = other.cap;
	this->pos = other.pos;
}

void Zoo::resize(int cap)
{
	Cage* temp = new Cage[cap];
	for (int i = 0; i < pos; ++i)
	{
		temp[i] = cages[i];
	}
	delete[] cages;
	cages = temp;
	this->cap = cap;
}

bool Zoo::rightCage(int j, const Animal* a) const
{
	if (!strcmp(cages[j].getNameC(), "Forest")
		&& (!strcmp(a->getGroup(), "Forest animal")))
	{
		const char* temp = cages[j].foodCage();
		if (!strcmp(temp,"plants") 
			&& !strcmp(a->getFood(), temp))
		{
			return true;
		}
		else
		{
			return false;
		}
		if (isPredator(temp, a->getFood()))
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	if (!strcmp(cages[j].getNameC(), "Savannah")
		&& (!strcmp(a->getGroup(), "Savannah animal")))
	{
		const char* temp = cages[j].foodCage();
		if (!strcmp(temp, "plants")
			&& !strcmp(a->getFood(), temp))
		{
			return true;
		}
		else
		{
			return false;
		}
		if (isPredator(temp, a->getFood()))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	if (!strcmp(cages[j].getNameC(), "Jungle")
		&& (!strcmp(a->getGroup(), "Jungle animal")))
	{
		const char* temp = cages[j].foodCage();
		if (!strcmp(temp, "plants")
			&& !strcmp(a->getFood(), temp))
		{
			return true;
		}
		else
		{
			return false;
		}
		if (isPredator(temp, a->getFood()))
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	if (!strcmp(cages[j].getNameC(), "Pole")
		&& (!strcmp(a->getGroup(), "Pole animal")))
	{
		const char* temp = cages[j].foodCage();
		if (!strcmp(temp, "plants")
			&& !strcmp(a->getFood(), temp))
		{
			return true;
		}
		else
		{
			return false;
		}
		if (isPredator(temp, a->getFood()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (!strcmp(cages[j].getNameC(), "Sea")
		&& (!strcmp(a->getGroup(), "Sea animal")))
	{
		const char* temp = cages[j].foodCage();
		if (!strcmp(temp, "plants")
			&& !strcmp(a->getFood(), temp))
		{
			return true;
		}
		else
		{
			return false;
		}
		if (isPredator(temp, a->getFood()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// za terariym vsi4ki vle4ygi otivat v 1 kletka po yslovie 
	//i grypata se vodi taka
	if (!strcmp(cages[j].getSpecies(), "Reptile")
		&& (!strcmp(a->getGroup(), "Reptile animal")))
	{
		const char* temp = cages[j].foodCage();
		if (!strcmp(temp, "plants")
			&& !strcmp(a->getFood(), temp))
		{
			return true;
		}
		else
		{
			return false;
		}
		if (isPredator(temp, a->getFood()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

bool Zoo::isPredator(const char * cageEat, const char * aEat) const
{
	if (!strcmp(cageEat, aEat))
	{
		return true;
	}
	if (!strcmp(cageEat, "fish") && !strcmp(aEat, "meat")) 
	{
		return true;
	}
	if (!strcmp(cageEat, "meat") && !strcmp(aEat, "fish")) 
	{
		return true;
	}
	return false;
}

Zoo::Zoo(int cap)
{
	this->cages = new Cage[cap];
	this->cap = cap;
	this->pos = 0;
}

Zoo::Zoo(const Zoo & other)
{
	copy(other);
}

Zoo & Zoo::operator=(const Zoo & other)
{
	if (this != &other)
	{
		delete[] cages;
		copy(other);
	}
	return *this;
}

Zoo::~Zoo()
{
	delete[] cages;
}

void Zoo::addAnimal(const Animal * ani)
{
	for (int i = 0; i < pos; ++i)
	{
		if (rightCage(i, ani))
		{
			if (!cages[i].addAnimal(ani))
			{
				continue;//ako epravilnata kletka no nqma mqsto tarsi natam 
			}
			else return;//ina4e dobaveno yspe6no i si tragva
		}
	}
	//ako ne e namerena pravilna kletka
	//ako ne e imalo nali4ni svobodni mesta
	//ako izob6to ne sa6testvyva takava kletka
	if (pos == cap) resize(cap * 2);
	cages[pos].createCage(ani);
	cages[pos].addAnimal(ani);
	pos += 1;
}

void Zoo::eat() 
{
	char yn[6];
	unsigned int sum = 0;
	for (int i = 0; i < pos; ++i)
	{
		sum += cages[i].sumKG();
	}
	if (!fs.hasEnoughFood(sum))
	{
		cout << "Does not have enough food!" << endl;
		cout << "Do you want to reset storage? Please enter Yes or No: ";
		cin.get();
		cin.getline(yn, 5);
		if (!strcmp(yn, "Yes"))
		{
			fs.resetStorage(sum);
			fs.eat();
			return;
		}
		else
		{
			return;
		}
		
	}
	else
	{
		fs.eat();
	}
}


int Zoo::getPos() const
{
	return pos;
}

void Zoo::printCage(const char * name) const
{
	for (int i = 0; i < pos; ++i)
	{
		if (!strcmp(cages[i].getNameC(), name))
		{
			cages[i].printCharacteristics();
			return;
		}

	}
	cout << "This cage does not exist yet!" << endl;
}

void Zoo::printAnimal(const char * name) const
{
	for (int i = 0; i < pos; ++i)
	{
		if (cages[i].printAnimal(name))
		{
			return;
		}
	}
	cout << "This animal does not exist yet!" << endl;
}
