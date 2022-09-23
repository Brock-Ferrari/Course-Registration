// Driver
// Brock Ferrari

#include <iostream>
#include <string>
#include "Faculty.h";
#include "Student.h";
#include "Course.h";
using namespace std;

Faculty addInstructor(); // Adds instructor to course class
Student addStudent(); // Adds student to course class
void EnterDate(Student s); // Enter date for student
void EnterDate(Faculty f); // Enter date for faculty
void tokenizeDate(char* cDate, int& month, int& day, int& year);

int main()
{
	Course course;

	cout << "Create a course.... " << endl << endl;

	cout << "Course Name: ";
	string cname; getline(cin, cname);
	course.setName(cname);

	cout << "Course Capacity (Number): ";
	int ccapacity; cin >> ccapacity;
	course.setCapacity(ccapacity);

	bool isInstructor = false;
	bool isStudents = false;



	char selection = ' ';
	while (selection != 'Q')
	{
		cout << endl << "Welcome to the Course Registration Application" << endl;
		cout << "I - Add Instructor" << endl << "S - Add Student" << endl << "L - List Course Information" << endl << "Q - Quit" << endl << endl;

		cin >> selection;
		selection = toupper(selection);

		switch (selection)
		{
			case 'I':
				if (isInstructor == false)
				{
					isInstructor = true;
					course.setInstructor(addInstructor());
				}
				else
				{
					cout << "There is already an assigned instructor" << endl;
					continue;
				}
				break;
			case 'S':
				if (course.getCapacity() < ccapacity)
				{
					isStudents = true;
					course.addStudent(addStudent());
				}
				else
				{
					cout << "Course capacity reached" << endl;
					continue;
				}
				break;
			case 'L':
				course.listCourseInfo(isStudents,isInstructor);
				break;
			case 'Q':
				cout << "quitting" << endl;
				break;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}

Faculty addInstructor()
{
	Faculty instructor;

	cout << "Instructor ID: ";
	string id = " ";
	cin >> id;
	instructor.setID(id);

	cout << "Instructor First Name: ";
	string firstname = " ";
	cin >> firstname;
	instructor.setFirstName(firstname);

	cout << "Instructor Last Name: ";
	string lastname = " ";
	cin >> lastname;
	instructor.setLastName(lastname);

	cout << "Instructor Birth Year: ";
	int byear = 0;
	cin >> byear;
	cout << "Instructor Birth Month (Number): ";
	int bmonth = 0;
	cin >> bmonth;
	cout << "Instructor Birth Day (Number): ";
	int bday = 0;
	cin >> bday;
	instructor.setBirthDate(bday,bmonth,byear);

	cout << "Instructor Hiring Year: ";
	int hyear = 0;
	cin >> hyear;
	cout << "Instructor Hiring Month (Number): ";
	int hmonth = 0;
	cin >> hmonth;
	cout << "Instructor Hiring Day (Number): ";
	int hday = 0;
	cin >> hday;
	instructor.setDateHired(hday, hmonth, hyear);

	cin.ignore();

	cout << "Instructor Title: ";
	string title = " ";
	getline(cin, title);
	instructor.setTitle(title);

	cout << endl << "Press enter to continue...." << endl;
	cin.ignore();

	cout << "Instructor Rank: ";
	string rank = " ";
	getline(cin, rank);
	instructor.setRank(rank);

	cout << "Instructor Salary: ";
	double salary = 0;
	cin >> salary;
	instructor.setSalary(salary);

	return instructor;
}

Student addStudent()
{
	Student student;

	cout << "Student ID: ";
	string id = " ";
	cin >> id;
	student.setID(id);

	cout << "Student First Name: ";
	string firstname = " ";
	cin >> firstname;
	student.setFirstName(firstname);

	cout << "Student Last Name: ";
	string lastname = " ";
	cin >> lastname;
	student.setLastName(lastname);

	cout << "Student Birth Year: ";
	int byear = 0;
	cin >> byear;
	cout << "Student Birth Month (Number): ";
	int bmonth = 0;
	cin >> bmonth;
	cout << "Student Birth Day (Number): ";
	int bday = 0;
	cin >> bday;
	student.setBirthDate(bday, bmonth, byear);

	cout << "Student Enrollment Year: ";
	int eyear = 0;
	cin >> eyear;
	cout << "Student Enrollment Month (Number): ";
	int emonth = 0;
	cin >> emonth;
	cout << "Student Enrollment Day (Number): ";
	int eday = 0;
	cin >> eday;
	student.setEnrollmentDate(eday, emonth, eyear);

	cin.ignore();

	cout << "Student Major: ";
	string major = " ";
	getline(cin, major);
	student.setMajor(major);

	cout << endl << "Press enter to continue...." << endl;
	cin.ignore();

	cout << "Student Level: ";
	string level = " ";
	getline(cin, level);
	student.setLevel(level);

	cout << "Student GPA: ";
	double GPA = 0;
	cin >> GPA;
	student.setGPA(GPA);

	return student;
}

void EnterDate(Faculty f)
{
	int m, d, y;
	char charDate[20]; //holds the date the user entered in char array
	Date realDate;  //date object; holds date after tokenization
	std::cout << "\nEnter a date (mm/dd/yyyy):  ";
	std::cin >> charDate;
	tokenizeDate(charDate, m, d, y); //separates char array into month, day, and year
	realDate.setDate(d, m, y); //sets the date of the object using the parsed values
}

void EnterDate(Student s)
{
	int m, d, y;
	char charDate[20]; //holds the date the user entered in char array
	Date realDate;  //date object; holds date after tokenization
	std::cout << "\nEnter a date (mm/dd/yyyy):  ";
	std::cin >> charDate;
	tokenizeDate(charDate, m, d, y); //separates char array into month, day, and year
	realDate.setDate(d, m, y); //sets the date of the object using the parsed values
}

void tokenizeDate(char* cDate, int& month, int& day, int& year)
{
	char seps[] = "/";
	char* token = NULL;
	char* next_token = NULL;
	token = NULL;
	next_token = NULL;
	// Establish string and get the tokens:  
	token = strtok_s(cDate, seps, &next_token);
	month = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	day = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	year = atoi(token);
}