#include "Group.h"

void Group::copy(const Group & other)
{
	this->group = new char[strlen(other.group) + 1];
	strcpy(this->group, other.group);
}

Group::Group(const char* name,const char * group)
	:Animal(name)
{
	this->group = new char[strlen(group) + 1];
	strcpy(this->group, group);
}

Group::Group(const Group & other)
	:Animal(other)
{
	copy(other);
}

Group & Group::operator=(const Group& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete[] group;
		copy(other);
	}
	return *this;
}

Group::~Group()
{
	delete[] group;
}

void Group::print() const
{
	cout << "Group is: " << getGroup() << endl;
}
const char* Group::getGroup() const
{
	return group;
}
