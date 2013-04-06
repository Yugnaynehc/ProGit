#ifndef _TYPEERROR_H_
#define _TYPEERROR_H_

#include "MyException.h"

class TypeError : public MyException
{
public:
    TypeError();
    const char* what() const;
	const int type() const;
    virtual ~TypeError();
private:
    const char* message;
    const int t;
};

#endif /* _TYPEERROR_H_ */
