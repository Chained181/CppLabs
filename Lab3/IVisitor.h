#pragma once
class IVisitor
{
public:
	~IVisitor(){}
	
	virtual void visit() = 0;

};