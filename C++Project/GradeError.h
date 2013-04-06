#ifndef _GRADEERROR_H_
#define _GRADEERROR_H_

#include "MyException.h"

class GradeError : public MyException
{
public:
    GradeError();
    const char* what() const;
	const int type() const;
	virtual ~GradeError();
private:
    const char* message;
    const int t;
};

#endif /* _GRADEERROR_H_ */

