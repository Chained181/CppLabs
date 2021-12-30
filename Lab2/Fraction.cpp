#include "Fraction.h"

inline Fraction::Fraction(int x, int y)
{
	this->x = x;
	this->y = y;
	++foc();
}

Fraction::~Fraction()
{
	--foc();
}

void Fraction::printAsFraction(Fraction decimal_fraction)
{
	std::cout << decimal_fraction.x << " / " << decimal_fraction.y << std::endl;
}

void Fraction::printAsFraction(char* decimal_fraction)
{
	char* secondNum = NULL;
	char* firstNum = strtok_s(decimal_fraction, "/", &secondNum);

	if (secondNum != nullptr && *secondNum != NULL)
		std::cout << (float)atoi(firstNum) / (float)atoi(secondNum) << std::endl;
	else
		std::cout << "Invalid formatter: " << decimal_fraction << std::endl;
}

void Fraction::printAsFraction(double decimal_fraction)
{
	std::stringstream ss;
	ss << decimal_fraction;
	char* str = _strdup(ss.str().data());

	char* secondNum = NULL;
	char* firstNum = strtok_s(str, ".", &secondNum);

	int lenght = strnlen_s(secondNum, sizeof secondNum);

	int y = pow(10, lenght);

	Fraction f(decimal_fraction * y, y);
	f.reduce();

	std::cout << f.x << " / " << f.y << std::endl;
}

void Fraction::reduce()
{
	int gcdn = gcd(abs(this->x), this->y);

	this->x /= gcdn;
	this->y /= gcdn;
}


int Fraction::gcd(int x, int y)
{
	return (x == 0) ? y : gcd(y % x, x);
}


Fraction Fraction::operator-(const Fraction& b)
{
	int cd = y * b.y;	
	int ns = x * b.y - b.x * y; 

	Fraction subtr(ns, cd); 
	reduce();

	return subtr;
}

Fraction Fraction::operator+(const Fraction& b)
{
	int cd = y * b.y;
	int ns = x * b.y + b.x * y; 

	Fraction sum(ns, cd);
	reduce();

	return sum;
}

Fraction Fraction::operator/(const Fraction& f)
{
	this->x *= f.y;
	this->y *= f.x;

	reduce();

	return *this;
}

Fraction Fraction::operator*(const Fraction& f)
{
	this->x *= f.x;
	this->y *= f.y;

	reduce();

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	os << (float)obj.x / (float)obj.y;
	return os;
}
