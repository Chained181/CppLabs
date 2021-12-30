#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable
{
protected:
	size_t countOperands;
	double* operands;

	std::string joinOperands(std::string s);

public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual ~ExpressionEvaluator();

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	virtual double calculate() = 0;

	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
};