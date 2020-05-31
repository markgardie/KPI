#include "Student.h"



double Student::GetAv()
{
	return avgmark;
}

string Student::GetN()
{
	return name;
}

string Student::GetIfBud()
{
	return ifbudget;
}

string Student::GetM1()
{
	return mark1;
}
string Student::GetM2()
{
	return mark2;
}
string Student::GetM3()
{
	return mark3;
}
string Student::GetM4()
{
	return mark4;
}
string Student::GetM5()
{
	return mark5;
}



void Student::SetN(string name)
{
	this->name = name;
}
void Student::SetM1(string mark1)
{
	this->mark1 = mark1;
}
void Student::SetM2(string mark2)
{
	this->mark2 = mark2;
}
void Student::SetM3(string mark3)
{
	this->mark3 = mark3;
}
void Student::SetM4(string mark4)
{
	this->mark4 = mark4;
}
void Student::SetM5(string mark5)
{
	this->mark5 = mark5;
}
void Student::SetIB(string ifbudget)
{
	this->ifbudget = ifbudget;
}

void Student::SetAv(double avg)
{
	this->avgmark = avg;
}



