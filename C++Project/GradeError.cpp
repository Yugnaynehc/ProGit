#include "GradeError.h"

GradeError::GradeError():message("�ɼ����ô���!"),t(1)
{
    //type = 1;
}

GradeError::~GradeError()
{
	//Empty
}

const char* GradeError::what() const
{
	return message;
}

const int GradeError::type() const
{
	return t;
}
