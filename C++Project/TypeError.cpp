#include "TypeError.h"

TypeError::TypeError():message("�����������ʹ���"),t(1)
{
    //type = 1;
}

TypeError::~TypeError()
{
	//Empty
}

const char* TypeError::what() const
{
	return message;
}

const int TypeError::type() const
{
	return t;
}
