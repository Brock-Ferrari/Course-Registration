// Course Class

#pragma once
#include <vector>
#include <iostream>
#include "Student.h"
#include "Faculty.h"

class Course
{
public:
	Course(){}
	~Course(){}

	void setName(std::string n) { name = n; }
	void setCapacity(int c) { capacity = c; }
	void setInstructor(Faculty i) { instructor = i; }
	void addStudent(Student s)
	{
		if (students.size() < capacity)
			students.push_back(s);
		else
			std::cout << "Course capacity reached..." << std::endl;
	}
	void listCourseInfo(bool isStu, bool isIns)
	{

		std::cout << std::endl << "Course Name: \t\t" << name << std::endl << "Capacity: \t\t" << capacity << std::endl << std::endl;
		if (isIns == false)
		{
			std::cout << std::endl << "There is no instructor assigned to this course." << std::endl;
		}
		else
		{
			std::cout << "Instructor: " << instructor << std::endl;
		}
		if (isStu == false)
		{
			std::cout << std::endl << "There are no students assigned to this course." << std::endl;
		}
		else
		{
			std::cout << "Students: " << std::endl;
			for (int i = 0; i < students.size(); ++i)
			{
				std::cout << students[i] << std::endl;
			}
		}

	}
	int getCapacity() { return students.size(); }

	/*void sortStudents()
	{
		< students;
	}*/

private:
	std::string name;
	std::vector<Student> students;
	Faculty instructor;
	int capacity;
};