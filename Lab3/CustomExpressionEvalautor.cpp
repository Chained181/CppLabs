#include "CustomExpressionEvaluator.h"

void CustomExpressionEvaluator::logToScreen()
{
	std::string str = "";

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
			: "(" + std::to_string(this->operands[i]) + ")";

		if (i != this->countOperands - 1)
				str += i < 1 ? " + " : " * ";
	}

	std::cout << str << " = " << this->calculate() << "\n";
}

void CustomExpressionEvaluator::logToFile(const std::string& fileName)
{
	std::string str = "";
	std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
			: "(" + std::to_string(this->operands[i]) + ")";

		if (i != this->countOperands - 1)
			str += i < 1 ? " + " : " * ";
	}

	ofs << str << " = " << this->calculate() << "\n";
	ofs.close();
}


void CustomExpressionEvaluator::shuffle()
{
	double firstElement = 0;

	for (size_t i = 0; i < this->countOperands; i++)
	{
		if (!(floor(this->operands[i]) == this->operands[i]))
		{
			firstElement = i;
			break;
		}
	}

	double lastElement = 0;

	for (size_t j = 0; j < this->countOperands; j++)
	{
		if (!(floor(this->operands[j]) == this->operands[j]))
		{
			lastElement = j;
		}
	}

	shuffle(firstElement, lastElement);
}

void CustomExpressionEvaluator::shuffle(size_t i, size_t j)
{
	if (!(floor(this->operands[i]) == this->operands[i]) 
		|| !(floor(this->operands[j]) == this->operands[j]))
	{
		auto temp = this->operands[j];
		this->operands[j] = this->operands[i];
		this->operands[i] = temp;
	}
}

double CustomExpressionEvaluator::calculate()
{
	double result = this->operands[0];

	for (size_t i = 1; i < this->countOperands; i++)
	{
		if (i > 1)
			result *= this->operands[i];
		else
			result += this->operands[i];
	}

	return result;
}