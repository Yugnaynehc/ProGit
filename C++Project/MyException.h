#ifndef _MYEXCEPTION_H_
#define _MYEXCEPTION_H_

class MyException
{
public:
    MyException();
	virtual const char* what() const = 0;
	virtual const int type() const = 0;
    virtual ~MyException();
};

#endif /* _MYEXCEPTION_H_ */
