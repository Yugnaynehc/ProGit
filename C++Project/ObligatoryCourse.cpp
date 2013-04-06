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

int ObligatoryCourse::totalCredit = 0; //ͳ�Ʊ��޿���ѧ��

/*ostream& operator<<(ostream& output, const ObligatoryCourse& t)
{
	output << "�γ��� : " << t.getName() << '\t' << "ѧ�� : " << t.getCreditHour();
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
	cout << "�ɼ�[0-100]: ";
	cin >> m;

	if (cin.fail())
	{
        cin.clear();		//���������
        cin.ignore();	    //�Ƴ������ַ�
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
		cout << "��ʽ��������������" << endl;
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

