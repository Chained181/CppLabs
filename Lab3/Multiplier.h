#pragma once
#include "ExpressionEvaluator.h"

class Multiplier : public ExpressionEvaluator
{
public:

	Multiplier();
	Multiplier(size_t n);

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	double calculate() override;
};

