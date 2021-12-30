#pragma once
#include "Person.h"
#include <ctime>
#include "IVisitor.h"
class Visitor : public Person, public IVisitor
{
	void takeThePlace();
public:
	Visitor();
	~Visitor();
	void visit() override;
};

