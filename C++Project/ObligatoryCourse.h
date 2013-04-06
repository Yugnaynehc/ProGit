// ObligatoryCourse.h: interface for the ObligatoryCourse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OBLIGATORYCOURSE_H__B70A628C_D1AD_4405_8FA6_E385B0E45154__INCLUDED_)
#define AFX_OBLIGATORYCOURSE_H__B70A628C_D1AD_4405_8FA6_E385B0E45154__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Course.h"

class ObligatoryCourse : public Course
{
	//friend std::ostream& operator<<(std::ostream&, const ObligatoryCourse&);
public:
	ObligatoryCourse(int=0);
	ObligatoryCourse(Course &c, int=0);
	ObligatoryCourse(string, int, int=0);
	virtual ~ObligatoryCourse();
	void setScore(int);
	virtual bool setScore();
	virtual int getScore() const { return mark; }
	virtual double getAveCredit() const;
	static int totalCredit;

private:
	int mark;

};

#endif // !defined(AFX_OBLIGATORYCOURSE_H__B70A628C_D1AD_4405_8FA6_E385B0E45154__INCLUDED_)
