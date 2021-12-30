#include <iostream>
#include "Subtractor.h"
#include "Multiplier.h"
#include "CustomExpressionEvaluator.h"
#include "Visitor.h"
#include "Artist.h"

void Loggable(ILoggable& s)
{
	s.logToScreen();
	s.logToFile("log.txt");
}

//TODO::Refactoring
void PrintPerson(Person* person)
{
	std::cout << person->get_firstName() << std::endl;
	std::cout << person->get_secondName() << std::endl;
	std::cout << person->get_yearOld() << std::endl;
	std::cout << person->get_gender() << std::endl;
}

void CreatorArtist()
{
	Artist* firstArtist = new Artist();
	firstArtist->set_firstName("Nikita");
	firstArtist->set_secondName("Kislov");
	firstArtist->set_yearOld(25);
	firstArtist->set_gender("Male");
	firstArtist->visit();
	PrintPerson(firstArtist);

	std::cout << "Count concert: " 
		<< firstArtist->getConcertCount() << std::endl
		<< "Rating:  " << firstArtist->get_rating() << "\n";

	std::cout << "\nCount artist: " << Person::countPerson() << "\n";

	delete firstArtist;
}

void SeatReservation()
{
	Visitor* firstVisitor = new Visitor();
	firstVisitor->set_firstName("Dmitry");
	firstVisitor->set_secondName("Filin");
	firstVisitor->set_yearOld(20);
	firstVisitor->set_gender("Male");
	firstVisitor->visit();
	PrintPerson(firstVisitor);

	Visitor* secondVisitor = new Visitor();
	secondVisitor->set_firstName("Michael");
	secondVisitor->set_secondName("Smolensky");
	secondVisitor->set_yearOld(20);
	secondVisitor->set_gender("Male");
	secondVisitor->visit();
	PrintPerson(secondVisitor);

	Visitor* thirdVisitor = new Visitor();
	thirdVisitor->set_firstName("Roman");
	thirdVisitor->set_secondName("Melinevsky");
	thirdVisitor->set_yearOld(20);
	thirdVisitor->set_gender("Male");
	thirdVisitor->visit();
	PrintPerson(thirdVisitor);

	std::cout << "\nCount audience: " << Person::countPerson() << "\n" ;

	delete thirdVisitor;
	delete secondVisitor;
	delete firstVisitor;
}

int main()
{
	double mass[]{ 2.5, -5, -3, 2, 10 };

	Subtractor s(2);
	s.setOperand(0, 23.65);
	s.setOperand(1, 12.15);
	
	Loggable(s);

	Multiplier m(4);
	m.setOperand(0, 2.5);
	m.setOperand(1, -3);
	m.setOperand(2, 4);
	m.setOperand(3, -1);

	Loggable(m);

	CustomExpressionEvaluator c;
	c.setOperands(mass, 5);
	c.shuffle();

	Loggable(c);


	/*Continue Lab2*/
	CreatorArtist();
	SeatReservation();
}

