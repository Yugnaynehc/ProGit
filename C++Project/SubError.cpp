#include "SubError.h"

SubError::SubError():message("�±����Խ��!"),t(1)
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

