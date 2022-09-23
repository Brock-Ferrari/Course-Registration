// Person Class

#pragma once
#include "Date.h"

class Person
{
public:

	Person(){}
	~Person(){}

	void setID(std::string id) { ID = id; }
	void setFirstName(std::string fN) { firstName = fN; }
	void setLastName(std::string lN) { lastName = lN; }
	void setBirthDate(int bd, int bm, int by) { birthDate.setDate(bd,bm,by); }
	
	std::string getID() { return ID; }
	std::string getFirstName() { return firstName; }
	std::string getLastName() { return lastName; }
	Date getBirthDate() { return birthDate; }

private:
	std::string ID;
	std::string firstName;
	std::string lastName;
	Date birthDate;
};