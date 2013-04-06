#include "CDate.h"
#include "DateError.h"
#include <iostream>
#include <iomanip>

using namespace std;

ostream& operator<<(ostream& output, const CDate& d)
{
	output << d.year << '-' << d.month << '-' << d.day;
	return output;
}

istream& operator>>(istream& input, CDate& d)
{
    int year, month, day;
	//cout << ", (如: 1912 6 23): ";
	input >> year >> month >> day;
	d.setAll(year, month, day);
    return input;
}

CDate& CDate::operator++()
{
	this->day++;
	if (!checkDate()) this->month++;
    if (!checkDate()) this->year++;
	return *this;
}
CDate CDate::operator++(int)
{
	CDate c(*this);
	this->day++;
	if (!checkDate()) this->month++;
    if (!checkDate()) this->year++;
	return c;
}

CDate::CDate()
{
	year = 1900;
	month = 1;
	day = 1;
}

CDate::CDate(CDate &d)
{
	year = d.getYear();
	month = d.getMonth();
	day = d.getDay();
}

CDate::CDate(int y , int m , int d)
{
    year = y;
    month = m;
    day = d;
    checkDate();
}

CDate::~CDate()
{
    //dtor
}

int CDate::maxDay() const
{
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if(isLeapYear()) return 29;
            else return 28;
        default: //月错误，则返回0
            return 0;
    }
}

bool CDate::checkDate()
{
    bool flag = true; //日期是否合法，缺省合法
    //年不做任何限制

    //月应该在1~12之间
    if ((month<1)||(month>12))
    {
        month =1 ;    //将月改为合法日期
        flag = false;
    }
    //日应该在特定月的日期范围之内，即在1和本月最大天数之间
    if ((day<1)||(day>maxDay()))
    {
        day = 1;
        flag = false;
    }
    return flag;
}

bool CDate::setMonth(int m)    //需要改进，提供重新输入的方式
{
    month = m;
    if (!checkDate())
        return false;
    else
        return true;
}

bool CDate::setDay(int d)   //需要改进，提供重新输入的方式
{
    day = d;
    if (!checkDate())
        return false;
    else
        return true;
}

bool CDate::setAll(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (!checkDate())
	{
		throw DateError();
		//throw MyException();
		//return false;
	}
    else
        return true;
}

bool CDate::isLeapYear() const
{
    return ( ((year%4==0)&&(year%100)) || (year%400==0) );
}


void CDate::nextDay()
{
    day++;
    if (!checkDate()) month++;
    if (!checkDate()) year++;
}

void CDate::print() const
{
    cout << setfill('0')
         << setw(4) << year << "年"
         << setw(2) << month << "月"
         << setw(2) << day << "日"
         << endl;
}


