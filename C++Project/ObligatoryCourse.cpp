// ObligatoryCourse.cpp: implementation of the ObligatoryCourse class.
//
//////////////////////////////////////////////////////////////////////
#include "ObligatoryCourse.h"
#include "GradeError.h"
#include "TypeError.h"
#include <iostream>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int ObligatoryCourse::totalCredit = 0; //统计必修课总学分

/*ostream& operator<<(ostream& output, const ObligatoryCourse& t)
{
	output << "课程名 : " << t.getName() << '\t' << "学分 : " << t.getCreditHour();
	return output;
}*/

ObligatoryCourse::ObligatoryCourse(int m) : Course()
{
	setScore(m);
	//totalCredit += getCreditHour();
}

ObligatoryCourse::ObligatoryCourse(Course &c, int m) : Course(c)
{
	setScore(m);
	//totalCredit += getCreditHour();
}

ObligatoryCourse::ObligatoryCourse(string n, int c,int m) : Course(n, c)
{
	setScore(m);
	//totalCredit += getCreditHour();
}

void::ObligatoryCourse::setScore(int m)
{
	mark = m;
}

bool::ObligatoryCourse::setScore()
{
	int m;
	cout << "成绩[0-100]: ";
	cin >> m;

	if (cin.fail())
	{
        cin.clear();		//清除错误标记
        cin.ignore();	    //移除错误字符
        throw TypeError();
    }

	if (m>=0 && m<=100)
	{
		mark = m;
		return true;
	}
	else
	{
	    throw GradeError();
		cout << "格式错误，请重新输入" << endl;
		return false;
	}
}

ObligatoryCourse::~ObligatoryCourse()
{

}

double ObligatoryCourse::getAveCredit() const
{
	double weight = 0.6;
	return ( (weight*getScore()*getCreditHour())/ObligatoryCourse::totalCredit );
}

