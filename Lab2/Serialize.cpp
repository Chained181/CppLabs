#include "Serialize.h"
#include <windows.h>

template<typename T>
inline Serialize<T>::Serialize(std::string path) : path(path)
{
}

template<typename T>
inline std::string Serialize<T>::getPath()
{
	return this->path;
}

template<typename T>
inline void Serialize<T>::serialize(T item)
{
	setlocale(LC_ALL, "rus");

	std::ofstream fout;
	try
	{
		fout.open(this->path, std::ofstream::in);

		fout.write((char*)&item, sizeof(T));

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	fout.close();
}

template<typename T>
inline T Serialize<T>::deserialize()
{
	std::ifstream fin;

	T item;

	try
	{
		fin.open(this->path);
		fin.read((char*)&item, sizeof(T));
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	

	fin.close();

	return item;
}
