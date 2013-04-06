#include "Course.h"
#include <iostream>
#include <string>
using namespace std;


ostream& operator<<(ostream& output, const Course& t)
{
	output << "�γ��� : " << t.name << '\t' << "ѧ�� : " << t.creditHour;
	return output;
}

Course::Course(Course &c)
{
	setName(c.name);
	setCreditHour(c.creditHour);
}

Course::Course(string n, int c)
{
	setName(n);
	setCreditHour(c);
}

Course::Course()
{
	setName("��");
	setCreditHour(0);
}

Course::~Course()
{

}

bool Course::setName(string n)
{
	name = n;
	return true;
}

bool Course::setCreditHour(int c)
{
	creditHour = c;
	return true;
}

