#include <iostream>

using namespace std;

class Course
{
public:
	//Methods
	void init(string name, int test1, int test2, int exam);

	int* getGradesList();
	string getName();
	double getFinalGrade();


private:
	string _name;
	int _grades[3]; //array of size 3 => test1, test2, exam
	double _avg;
};