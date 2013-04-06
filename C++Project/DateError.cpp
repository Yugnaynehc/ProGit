#include "DateError.h"

DateError::DateError():message("ÈÕÆÚÊäÈë´íÎó!"),t(1)
{
    //type = 1;
}

DateError::~DateError()
{
	//Empty
}

const char* DateError::what() const
{
	return message;
}

const int DateError::type() const
{
	return t;
}
