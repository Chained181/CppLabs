#pragma once
#include <iostream>
#include "Serialize.h"
#include "Serialize.cpp"
#include <string>
#include <vector>

#define PROPERTIES(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class Artist
{
private:

public:
	Artist() = default;
	~Artist();
	Artist(std::string firstName, std::string secondName, std::string musicalInstrument, 
		std::string gender, int rating, int yearOld);

	template<class Pred>
	static void bubbleSorting(std::vector<Artist>& arr, Pred perd);


	PROPERTIES(std::string, firstName);
	PROPERTIES(std::string, secondName);
	PROPERTIES(std::string, musicalInstrument);
	PROPERTIES(std::string, gender);
	PROPERTIES(int, yearOld);
	PROPERTIES(int, rating);

	
	void serialize(const std::string& filename);
	void serialize();

	static Artist deserialize(const std::string& filename);
	static Artist deserialize();
};