#pragma once
#include"Animal.h"
using namespace std;
class Group: virtual public Animal
{
private:
	char* group;
	void copy(const Group& other);
public:
	Group(const char* name, const char* group = "");
	Group(const Group& other);
	Group& operator=(const Group& other);
	virtual ~Group();
	virtual void sound(const char* option) const = 0;
	virtual Animal* clone() const = 0;
	virtual void print() const;
	virtual const char* getGroup() const;
};