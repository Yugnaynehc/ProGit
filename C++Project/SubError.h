#ifndef _SUBERROR_H_
#define _SUBERROR_H_

#include "MyException.h"

class SubError : public MyException
{
public:
    SubError();
    virtual ~SubError();
    const char* what() const;
	const int type() const;
private:
    const char* message;
    const int t;
};

#endif /* _SUBERROR_H_ */
