#include <iostream>
#include "Student.h"
#include "CDate.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "SubError.h"
#include <cstring>
using namespace std;

int Student::count = 0; //对象数量计数器


const Course& Student::operator[](int subscript) const
{
    if (subscript < 0 || subscript >=courseNumber )
    {
	throw SubError();
	//cerr <<"下标越界: " << subscript << endl;
	//exit( 1 ); // 访问越界，退出程序
    }
    return (*courseList[subscript]); //返回值，只能作右值，不能修改
}

Course& Student::operator[](int subscript)
{
    if (subscript < 0 || subscript >=courseNumber )
    {
	throw SubError();
	//cerr <<"下标越界: " << subscript << endl;
	//exit( 1 ); // 访问越界，退出程序
    }
    return (*courseList[subscript]); //返回值，能作左值，能修改
}


ostream& operator<<(ostream& output, const Student& s)
{
    output << "姓名：" << s.name << '\t' << "出生日期：" << s.birthDate << "，"
	   << "课程信息如下：" << '\n';
    for (int i=0;i<s.courseNumber;i++)
	output << '\t' << *s.courseList[i] << '\t' << "成绩: " << s.courseList[i]->getScore() << '\n';
    output << "积点成绩：" << s.calcCredit() << endl
           << "必修课学分和: " << ObligatoryCourse::totalCredit << endl
	   << "选修课总门数: " << ElectiveCourse::totalCourse << endl;
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
    //cout << Student::count << "构造函数" << endl;
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
    //cout << Student::count << "构造函数" << endl;
}

Student::Student(const char* n, CDate &d)
{
    name = new char[10];
    strcpy(name, n);
    courseNumber = 0;
    birthDate = d;
    count++;
    //cout << Student::count << "构造函数" << endl;
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

bool Student::setName(const char* n)	//用bool留一个后门
{
    name = new char[10];
    strcpy(name, n);
    return true;
}

bool Student::setbirthDate(CDate &d) //用bool留一个后门
{
    birthDate = d;
    return true;
}

bool Student::setYear(int y)
{
    birthDate.setYear(y); //用成员函数设置
    return true;
}

bool Student::setMonth(int m)
{
    birthDate.setMonth(m); //用成员函数设置
    return true;
}

bool Student::setDay(int d)
{
    birthDate.setDay(d); //用成员函数设置
    return true;
}


void Student::printChoice() const
{
    int i;
    if (courseNumber != 0)
        for (i=0;i<courseNumber;i++)
            cout << "\t" << *courseList[i] <<'\n';
    else
        cout << "未选择任何课程." << endl;
}

void Student::printEveryChoice() const
{
    int i;
    for (i=0;i<courseNumber;i++)
	cout << "\t" << *courseList[i] << '\t' << "成绩: " << courseList[i]->getScore() << '\n';
}

void Student::printCalcCredit() const
{
    cout << '\t' << "积点成绩：" << calcCredit() << endl;
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

    //cout << Student::count << "析构函数" <<endl;
    count--;
}


