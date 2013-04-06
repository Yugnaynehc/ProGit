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

int ElectiveCourse::totalCourse = 0; //ͳ��ѡ�޿�������


/*ostream& operator<<(ostream& output, const ElectiveCourse& t)
{
	output << "�γ��� : " << t.getName() << '\t' << "ѧ�� : " << t.getCreditHour();
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
	cout << "�ȼ�[A-E]: ";
	cin >> g;

	if (cin.fail())  //��ʵ��������õģ�char���Ͷ�int�ǲ��ᱨcin.fail��
	{
        cin.clear();		    //���������
        cin.sync();	//�Ƴ������ַ�
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
		cout << "��ʽ��������������" << endl;
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

