#ifndef CDATE_H
#define CDATE_H
#include <iostream>

class CDate
{
	friend std::ostream& operator<<(std::ostream&, const CDate&);
	friend std::istream& operator>>(std::istream&, CDate&);

    public:
		CDate();
		CDate(CDate &d);
        CDate(int y, int m, int d);
        virtual ~CDate();

		CDate& operator++();
		CDate operator++(int);
        int getYear() const { return year; }
        void setYear(int val) { year = val; }
        int getMonth() const { return month; }
        bool setMonth(int val);
        int getDay() const { return day; }
        bool setDay(int val);
        int maxDay() const;
        bool checkDate();
        bool isLeapYear() const;
        void nextDay();
		bool setAll(int y, int m, int d);
        void print() const;

    private:
        int year;
        int month;
        int day;
};


#endif // CDATE_H
