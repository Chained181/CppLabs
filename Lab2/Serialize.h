#pragma once
#include <iostream>
#include <fstream>
#include <string>

template<typename T>
class Serialize
{
private:
	std::string path;
public:
	Serialize() = default;
	Serialize(std::string path);

	std::string getPath();

	void serialize(T item);
	T deserialize();
};
