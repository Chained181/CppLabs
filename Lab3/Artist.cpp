#include "Artist.h"
#include <ctime>

Artist::~Artist()
{
	--countPerson();
}

Artist::Artist()
{
	++countPerson();
}

void Artist::visit()
{
	srand(time(NULL));
	this->rating = std::rand() % 5;
	this->concertCount++;
}

int Artist::getConcertCount()
{
	return this->concertCount;
}