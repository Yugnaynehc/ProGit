// ElectiveCourse.h: interface for the ElectiveCourse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELECTIVECOURSE_H__71A3083E_1466_42EE_9AF4_92835F1B7709__INCLUDED_)
#define AFX_ELECTIVECOURSE_H__71A3083E_1466_42EE_9AF4_92835F1B7709__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Course.h"

class ElectiveCourse : public Course
{
	//friend std::ostream& operator<<(std::ostream&, const ElectiveCourse&);
public:
	ElectiveCourse(char=' ');
	ElectiveCourse(Course &c, char=' ');
	ElectiveCourse(string, int, char=' ');
	virtual ~ElectiveCourse();
	void setGrade(char);
	virtual bool setScore();
	virtual int getScore() const;
	virtual double getAveCredit() const;
	static int totalCourse;

private:
	char grade;

};

#endif // !defined(AFX_ELECTIVECOURSE_H__71A3083E_1466_42EE_9AF4_92835F1B7709__INCLUDED_)
