#include "TypeError.h"

TypeError::TypeError():message("输入数据类型错误"),t(1)
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
