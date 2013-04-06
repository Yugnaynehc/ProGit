#include "MyException.h"

class DateError : public MyException
{
public:
	DateError();
	const char* what() const;
	const int type() const;
    virtual ~DateError();
private:
	const char *message;
	const int t;
};
