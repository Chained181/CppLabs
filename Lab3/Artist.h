#pragma once
#include <string>
#include <vector>
#include "Person.h"
#include "IVisitor.h"

#define PROPERTIES(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class Artist : public Person, public IVisitor
{
	int concertCount = 0;
public:
	Artist();
	~Artist();

	int getConcertCount();

	void visit() override;

	PROPERTIES(std::string, musicalInstrument);
	PROPERTIES(int, rating);
};

