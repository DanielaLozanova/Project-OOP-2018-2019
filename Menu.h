#pragma once
#include"Zoo.h"

void printCage() 
{
	cout << "The names of the cages: " << endl;
	cout << "1. Forest" << endl;
	cout << "2. Savannah" << endl;
	cout << "3. Pole" << endl;
	cout << "4. Jungle" << endl;
	cout << "5. Aquarium" << endl;
	cout << "6. Terrarium" << endl;
}
void printAnimal()
{
	cout << "The names of the animals: " << endl;
	cout << "1. Bear(Forest animal)" << endl;
	cout << "2. White bear(Pole animal)" << endl;
	cout << "3. Lion(Savannah animal)" << endl;
	cout << "4. Tiger(Savannah animal)" << endl;
	cout << "5. Lioness(Savannah animal)" << endl;
	cout << "6. Canary(Forest animal)" << endl;
	cout << "7. Eagle(Forest animal)" << endl;
	cout << "8. Cobra(Reptile animal)" << endl;
	cout << "9. Viper(Reptile animal)" << endl;
	cout << "10. Shark(Sea animal)" << endl;
	cout << "11. Puffer-fish(Sea animal)" << endl;
}

Animal* getAnimal(int idx) {
	if (idx == 1) return new SpecificAnimal("Bear", "Forest animal", { "fish", 5 }, "mammal");
	else if (idx == 2) return new SpecificAnimal("White bear", "Pole animal", { "fish", 7 }, "mammal");
	else if (idx == 3) return new SpecificAnimal("Lion", "Savannah animal", {"meat",10},"mammal");
	else if (idx == 4) return new SpecificAnimal("Tiger", "Savannah animal", { "meat",10 }, "mammal");
	else if (idx == 5) return new SpecificAnimal("Lioness", "Savannah animal", { "meat",10 }, "mammal");
	else if (idx == 6) return new SpecificAnimal("Canary", "Jungle animal", { "plants",1 }, "bird");
	else if (idx == 7) return new SpecificAnimal("Eagle", "Forest animal", { "meat",1 }, "bird");
	else if (idx == 8) return new SpecificAnimal("Cobra", "Reptile animal", { "meat",3 }, "reptile");
	else if (idx == 9) return new SpecificAnimal("Viper", "Reptile animal", { "meat",3 }, "reptile");
	else if (idx == 10) return new SpecificAnimal("Shark", "Sea animal", { "meat",4 }, "fish");
	else if (idx == 11) return new SpecificAnimal("Puffer-fish", "Sea animal", { "plants",4 }, "fish");
	else return nullptr;
}
void menu()
{
	Zoo zoo(2);
	printCage();
	char buffer[32];
	char quit[6];
	int idx=1;
	unsigned int commNum = 0;
	do
	{
		cout << "Comands: " << endl;
		cout << "1. Add Animal" << endl;
		cout << "2. Eat" << endl;
		cout << "3. Print Cage" << endl;
		cout << "4. Print Animal" << endl;
		cout << "Please enter command number: " << endl;
		cin >> commNum;
		if (commNum == 1)
		{
			printAnimal();
			cout << "Enter index: ";
			cin >> idx;
			Animal* animal = getAnimal(idx);
			if (!animal)
			{
				cout << "No such animal exists!" << endl;
			}
			else
			{
				zoo.addAnimal(animal);
			}
			delete animal;
			cin.get();
		}
		if (commNum == 2)
		{
			zoo.eat();
		}
		if (commNum == 3)
		{
			cin.get();
			char nameCage[32];
			cout << "Enter name of the cage: " << endl;
			cin.getline(nameCage, 31);
			zoo.printCage(nameCage);
		}
		if (commNum == 4)
		{
			cin.get();
			char nameAnimal[32];
			cout << "Enter name of the animal: " << endl;
			cin.getline(nameAnimal, 31);
			zoo.printAnimal(nameAnimal);
		}
		cout << "Do you want to continue? Enter Yes/No." << endl;
		cin.getline(quit, 5);
	} while (strcmp(quit, "No"));
	
}