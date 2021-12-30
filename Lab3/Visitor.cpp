#include "Visitor.h"
#include <fstream>
#include <iostream>
Visitor::~Visitor()
{
	--countPerson();
}
Visitor::Visitor()
{
	++countPerson();
}

void Visitor::visit()
{
	takeThePlace();
}

void Visitor::takeThePlace()
{
	int countPlace = countPerson();
	int temp = 0;
	std::ifstream f("countPlace.txt");
	std::ofstream f0("countPlace.txt", std::fstream::binary | std::fstream::out | std::fstream::in);

	f >> temp;
	std::cout << "\nThere are no empty seats left: " << temp << "\n";
	f0 << temp - countPlace;
	
	f0.close();
}