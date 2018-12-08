#include "Course.h"
#include <iostream>
using namespace std;
class Student
{
public:
	void init(string name, Course** courses, int crsCount);

	string getName();
	void setName(string name);
	int getCrsCount();
	Course** getCourses();
	double getAvg();


private:
	string _name;
	Course** _Courses;//array of pointers to Course
	int _crsCount;
};