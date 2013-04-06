#include <iostream>
#include "Student.h"
#include "CDate.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "SubError.h"
#include <cstring>
using namespace std;

int Student::count = 0; //��������������


const Course& Student::operator[](int subscript) const
{
    if (subscript < 0 || subscript >=courseNumber )
    {
	throw SubError();
	//cerr <<"�±�Խ��: " << subscript << endl;
	//exit( 1 ); // ����Խ�磬�˳�����
    }
    return (*courseList[subscript]); //����ֵ��ֻ������ֵ�������޸�
}

Course& Student::operator[](int subscript)
{
    if (subscript < 0 || subscript >=courseNumber )
    {
	throw SubError();
	//cerr <<"�±�Խ��: " << subscript << endl;
	//exit( 1 ); // ����Խ�磬�˳�����
    }
    return (*courseList[subscript]); //����ֵ��������ֵ�����޸�
}


ostream& operator<<(ostream& output, const Student& s)
{
    output << "������" << s.name << '\t' << "�������ڣ�" << s.birthDate << "��"
	   << "�γ���Ϣ���£�" << '\n';
    for (int i=0;i<s.courseNumber;i++)
	output << '\t' << *s.courseList[i] << '\t' << "�ɼ�: " << s.courseList[i]->getScore() << '\n';
    output << "����ɼ���" << s.calcCredit() << endl
           << "���޿�ѧ�ֺ�: " << ObligatoryCourse::totalCredit << endl
	   << "ѡ�޿�������: " << ElectiveCourse::totalCourse << endl;
    return output;
}


Student::Student()
{
    name = NULL;
    courseNumber = 0;
    birthDate.setYear(1900);
    birthDate.setMonth(1);
    birthDate.setDay(1);
    count++;
    //cout << Student::count << "���캯��" << endl;
}

Student::Student(const char* n, int y, int m, int d)
{
    name = new char[10];
    strcpy(name, n);
    courseNumber = 0;
    birthDate.setYear(y);
    birthDate.setMonth(m);
    birthDate.setDay(d);
    count++;
    //cout << Student::count << "���캯��" << endl;
}

Student::Student(const char* n, CDate &d)
{
    name = new char[10];
    strcpy(name, n);
    courseNumber = 0;
    birthDate = d;
    count++;
    //cout << Student::count << "���캯��" << endl;
}

Student& Student::addCourse(ObligatoryCourse *course)
{
    if (course != NULL)
    {
        courseList[courseNumber] = new ObligatoryCourse(*course);
        courseNumber++;
        ObligatoryCourse::totalCredit += course->getCreditHour();
    }
    return *this;
}


Student& Student::addCourse(ElectiveCourse *course)
{
    if (course != NULL)
    {
        courseList[courseNumber] = new ElectiveCourse(*course);
        courseNumber++;
        ElectiveCourse::totalCourse++;
    }
    return *this;
}

/*
  Student& Student::addCourse(const string &courseName, int creditHour)
  {
  courseList[courseNumber] = new Course(courseName,creditHour);
  courseNumber++;
  return *this;
  }
*/

double Student::calcCredit() const
{
    int i;
    double ans = 0;
    for ( i=0; i<courseNumber; ++i )
    {
	ans += courseList[i]->getAveCredit();
    }
    return ans;
}

void Student::getbirthDate() const
{
    birthDate.print();
}

int Student::getCourseNumber() const
{
    return courseNumber;
}

Course* Student::getcourseList(int i)
{
    return courseList[i];
}

bool Student::setName(const char* n)	//��bool��һ������
{
    name = new char[10];
    strcpy(name, n);
    return true;
}

bool Student::setbirthDate(CDate &d) //��bool��һ������
{
    birthDate = d;
    return true;
}

bool Student::setYear(int y)
{
    birthDate.setYear(y); //�ó�Ա��������
    return true;
}

bool Student::setMonth(int m)
{
    birthDate.setMonth(m); //�ó�Ա��������
    return true;
}

bool Student::setDay(int d)
{
    birthDate.setDay(d); //�ó�Ա��������
    return true;
}


void Student::printChoice() const
{
    int i;
    if (courseNumber != 0)
        for (i=0;i<courseNumber;i++)
            cout << "\t" << *courseList[i] <<'\n';
    else
        cout << "δѡ���κογ�." << endl;
}

void Student::printEveryChoice() const
{
    int i;
    for (i=0;i<courseNumber;i++)
	cout << "\t" << *courseList[i] << '\t' << "�ɼ�: " << courseList[i]->getScore() << '\n';
}

void Student::printCalcCredit() const
{
    cout << '\t' << "����ɼ���" << calcCredit() << endl;
}

Student::~Student()
{
    if (name != NULL) delete[] name;
    if (courseNumber != 0)
    {
	for (int i=0;i<courseNumber;i++)
	    delete courseList[i];
	courseNumber = 0;
    }

    //cout << Student::count << "��������" <<endl;
    count--;
}


