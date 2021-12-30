#include "Multiplier.h"

Multiplier::Multiplier()
    :ExpressionEvaluator::ExpressionEvaluator()
{
}

Multiplier::Multiplier(size_t n)
    :ExpressionEvaluator::ExpressionEvaluator(n)
{
}

void Multiplier::logToScreen()
{
    std::cout << this->joinOperands(" * ") << " = " << this->calculate() << "\n";

}

void Multiplier::logToFile(const std::string& fileName)
{
    std::string str = this->joinOperands(" * ");

    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);
    ofs << str + " = " + std::to_string(this->calculate()) + "\n";
    ofs.close();
}

double Multiplier::calculate()
{
    double result = this->operands[0];

    for (size_t i = 1; i < this->countOperands; i++)
        result *= this->operands[i];

    return result;
}
