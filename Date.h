// Date Class

#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>
class Date {
	friend std::ostream& operator<<(std::ostream&, Date);
public:
	Date(int d = 0, int m = 0, int yyyy = 0) {
		setDate(d, m, yyyy);
	}
	~Date() {}
	void setDate(int  d, int m, int yyyy) {
		day = d;
		month = m;
		year = yyyy;
	}
private:
	int day;
	int month;
	int year;
};
std::ostream& operator<<(std::ostream& output, Date d) {
	output << d.month << "/" << d.day << "/" << d.year;
	return output;
}