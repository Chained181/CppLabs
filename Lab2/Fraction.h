#include <iostream>
#include <math.h>
#include <sstream>
#include <iostream>
#pragma once
class Fraction
{
private:
	int x;
	int y;
	static size_t& foc() { static size_t c = 0; return c; }
	void reduce();

public:
	Fraction(int x, int y);	
	~Fraction();
	static size_t& countF() { return foc(); }

	/// <summary>
	/// print res obj classes
	/// </summary>
	/// <param name="decimal_fraction"></param>
	static void printAsFraction(Fraction decimal_fraction);

	/// <summary>
	/// print string
	/// </summary>
	/// <param name="decimal_fraction"></param>
	static void printAsFraction(char* decimal_fraction);

	/// <summary>
	/// print double number
	/// </summary>
	/// <param name="decimal_fraction"></param>
	static void printAsFraction(double decimal_fraction);


	static int gcd(int x, int y);

	Fraction operator-(const Fraction& f);
	Fraction operator+(const Fraction& f);
	Fraction operator/(const Fraction& f);
	Fraction operator*(const Fraction& f);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);
};
