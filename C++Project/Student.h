#include "CDate.h"
#include "Course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include <iostream>
#define MAX_SIZE 16
using namespace std;

#if !defined(AFX_STUDENT_H__B9328836_CA75_4002_B06A_66A6E87ED3E6__INCLUDED_)
#define AFX_STUDENT_H__B9328836_CA75_4002_B06A_66A6E87ED3E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Student
{
	friend ostream& operator<<(ostream&, const Student&);

public:
	Student();
	Student(const char* n, CDate &d);
	Student(const char* n, int y, int m, int d);
	virtual ~Student();

	//�����±����������ȡ��ѧ����ĳ�ſγ���Ϣ
	const Course& operator[](int subscript) const;//������Ա������ֻ������Ϊ��ֵ
	Course& operator[](int subscript);	//��ͨ��Ա������Ϊ��ֵ������ͨ���ĳɺ������صĿγ���Ϣ���ÿγ̳ɼ�
	
	Student& addCourse(ObligatoryCourse *course);
	Student& addCourse(ElectiveCourse *course);
	//Student& addCourse(const string &courseName, int creditHour);
	char* getName() const {return name;}
	void getbirthDate() const;
	int getYear() {return birthDate.getYear();}
	int getMonth() {return birthDate.getMonth();}
	int getDay() {return birthDate.getDay();}
    int getCourseNumber() const;
	double calcCredit() const;

	bool setbirthDate(CDate &d);
	bool setYear(int val);
	bool setMonth(int val);
	bool setDay(int val);
	bool setName(const char* n);
    Course* getcourseList(int);

	void printChoice() const; //���ѧ��ѡ����Ϣ���������ɼ���
	void printEveryChoice() const; //��ѯ���ſγ̳ɼ�
	void printCalcCredit() const; //��ѯ����ɼ�

private:
	CDate birthDate;
	Course *courseList[MAX_SIZE];
	char* name;
	int courseNumber;
	static int count;

};

#endif // !defined(AFX_STUDENT_H__B9328836_CA75_4002_B06A_66A6E87ED3E6__INCLUDED_)
