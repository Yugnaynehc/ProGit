// ElectiveCourse.cpp: implementation of the ElectiveCourse class.
//
//////////////////////////////////////////////////////////////////////
#include "ElectiveCourse.h"
#include "GradeError.h"
#include "TypeError.h"
#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int ElectiveCourse::totalCourse = 0; //统计选修课总门数


/*ostream& operator<<(ostream& output, const ElectiveCourse& t)
{
	output << "课程名 : " << t.getName() << '\t' << "学分 : " << t.getCreditHour();
	return output;
}*/

ElectiveCourse::ElectiveCourse(char g):Course()
{
	setGrade(g);
	//totalCourse++;
}

ElectiveCourse::ElectiveCourse(Course &c, char g):Course(c)
{
	setGrade(g);
	//totalCourse++;
}

ElectiveCourse::ElectiveCourse(string n, int c, char g):Course(n, c)
{
	setGrade(g);
	//totalCourse++;
}

void ElectiveCourse::setGrade(char g)
{
	grade = g;
}

bool ElectiveCourse::setScore()
{
	char g;
	cout << "等级[A-E]: ";
	cin >> g;

	if (cin.fail())  //其实这段是无用的，char类型读int是不会报cin.fail的
	{
        cin.clear();		    //清除错误标记
        cin.sync();	//移除错误字符
        throw TypeError();
    }

	if (g>='A' && g<='E')
	{
		grade = g;
		cin.sync();
		return true;
	}
	else
	{
	    cin.sync();
	    throw GradeError();
		cout << "格式错误，请重新输入" << endl;
		return false;
	}
}

ElectiveCourse::~ElectiveCourse()
{

}

int ElectiveCourse::getScore() const
{
	switch(grade)
	{
	case 'A': return 95;
	case 'B': return 85;
	case 'C': return 75;
	case 'D': return 65;
	case 'E': return 55;
	case 'a': return 95;
	case 'b': return 85;
	case 'c': return 75;
	case 'd': return 65;
	case 'e': return 55;
	}
	return 0;
}


double ElectiveCourse::getAveCredit() const
{
	double weight = 0.4;
	return ( weight*getScore()/totalCourse );
}

