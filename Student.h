// Student Class

#pragma once
#include "Person.h"
#include <vector>
#include <algorithm>

class Student : public Person
{
	friend std::ostream& operator<<(std::ostream& os, Student& s);
public:
	Student(){}
	~Student(){}

	void setEnrollmentDate(int ed, int em, int ey) { dateEnrolled.setDate(ed, em, ey); }
	void setMajor(std::string m) { major = m; }
	void setLevel(std::string l) { level = l; }
	void setGPA(double gpa) { GPA = gpa; }

	Date getDateEnrolled() { return dateEnrolled; }
	std::string getMajor() { return major; }
	std::string getLevel() { return level; }
	double getGPA() { return GPA; }

	/*void operator<(vector<Student>& v)
	{
		sort(v.begin(), v.end());
	}*/
private:
	std::string major;
	std::string level;
	double GPA;
	Date dateEnrolled;
};

std::ostream& operator<<(std::ostream& os, Student& s)
{
	os << "ID:\t\t\t" << s.getID() << std::endl << "Name:\t\t\t" << s.getFirstName() << " " << s.getLastName() << std::endl << "Birth Date:\t\t" << s.getBirthDate() << std::endl << "Enrollment Date:\t" << s.getDateEnrolled() << std::endl << "Major:\t\t\t" << s.getMajor() << std::endl << "Level:\t\t\t" << s.getLevel() << std::endl << "GPA:\t\t\t" << s.getGPA() << std::endl;
	return os;
}