#pragma once
#include "Student.h"
#include <iomanip>
#include <list>
#include <iterator>

class Group
{
    list<Student> students;
	int studnum;
	double coef;
    list<Student>:: iterator it1;
    list<int>:: iterator it2;
	

public:
    Group(int);

    void SetAtributes(string, list<int>, double, bool, int);


    string calcavg();
    string sort();
    string grants();

};

