#include "SubError.h"

SubError::SubError():message("下标访问越界!"),t(1)
{
    //type = 1;
}

SubError::~SubError()
{
	//Empty
}

const char* SubError::what() const
{
	return message;
}

const int SubError::type() const
{
	return t;
}

