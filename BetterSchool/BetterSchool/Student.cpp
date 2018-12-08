#include "Student.h"



Student::Student()
{
}


Student::~Student()
{
}

void Student::init(string name, Course** courses, int crsCount)
{
	_name = name;
	_Courses = courses;
	_crsCount = crsCount;



}
string Student::getName()
{
	return _name;
}
void Student::setName(string name)
{
	_name = name;
}

double Student::getAvg()
{
	double sum = 0;
	for (int i = 0; i < _crsCount; i++)
	{
		sum += _Courses[i]->getFinalGrade();

	}

	return sum / _crsCount;
}

int Student::getCrsCount()
{
	return _crsCount;
}
Course** Student::getCourses()
{
	return _Courses;
}