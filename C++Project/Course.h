#if !defined(AFX_COURSE_H__3A3D4E02_08C9_48E5_B46F_580F16DC2986__INCLUDED_)
#define AFX_COURSE_H__3A3D4E02_08C9_48E5_B46F_580F16DC2986__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <iostream>
using namespace std;

class Course
{
	friend std::ostream& operator<<(std::ostream&, const Course&);

	public:
		Course();
		Course(Course &c);
		Course(string, int);
		virtual ~Course();
		string getName() const {return name;}
		int getCreditHour() const {return creditHour;}
		bool setName(string);
		bool setCreditHour(int);
		virtual bool setScore() = 0;
		virtual int getScore() const = 0;
		virtual double getAveCredit() const = 0;
	private:
		string name;
		int creditHour;


};

#endif // !defined(AFX_COURSE_H__3A3D4E02_08C9_48E5_B46F_580F16DC2986__INCLUDED_)
