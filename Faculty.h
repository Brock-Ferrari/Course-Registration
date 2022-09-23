// Faculty Class

#pragma once
#include "Person.h"

class Faculty : public Person
{
	friend std::ostream& operator<<(std::ostream& os, Faculty& f);
public:
	Faculty() {}
	~Faculty() {}

	void setDateHired(int hd, int hm, int hy) { dateHired.setDate(hd, hm, hy); }
	void setTitle(std::string t) { title = t; }
	void setRank(std::string r) { rank = r; }
	void setSalary(double s) { salary = s; }

	Date getDateHired() { return dateHired; }
	std::string getTitle() { return title; }
	std::string getRank() { return rank; }
	double getSalary() { return salary; }
private:
	Date dateHired;
	std::string title;
	std::string rank;
	double salary;
};

std::ostream& operator<<(std::ostream& os, Faculty& f)
{
	os << std::endl << "ID:\t\t\t" << f.getID() << std::endl << "Name:\t\t\t" << f.getTitle() << " " << f.getFirstName() << " " << f.getLastName() << ", " << f.getRank() << std::endl << "Birth Date:\t\t" << f.getBirthDate() << std::endl << "Hired Date:\t\t" << f.getDateHired() << std::endl << "Salary:\t\t\t" << f.getSalary() << std::endl;
	return os;
}