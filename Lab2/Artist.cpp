#include "..\Lab3\Artist.h"
#include "Artist.h"


Artist::~Artist()
{
}

Artist::Artist(std::string firstName, std::string secondName, std::string musicalInstrument, std::string gender, int rating, int yearOld)
	:firstName(firstName), secondName(secondName), gender(gender), musicalInstrument(musicalInstrument), rating(rating), yearOld(yearOld)
{
}

void Artist::serialize(const std::string& filename)
{
	Serialize<Artist> serializer(filename);

	serializer.serialize(*this);
}

void Artist::serialize()
{
	this->serialize("artistList.txt");
}

Artist Artist::deserialize(const std::string& filename)
{
	Serialize<Artist> serialize(filename);

	return serialize.deserialize();
}

Artist Artist::deserialize()
{
	return Artist::deserialize("artistList.txt");
}
