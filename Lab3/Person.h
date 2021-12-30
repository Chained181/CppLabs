#pragma once
#include <vector>
#include <string>
#define PROPERTIES(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class Person
{
	static size_t& foc() { static size_t c = 0; return c; }
public:
	static size_t& countPerson() { return foc(); }
	PROPERTIES(std::string, firstName);
	PROPERTIES(std::string, secondName);
	PROPERTIES(std::string, gender);
	PROPERTIES(int, yearOld);
};

