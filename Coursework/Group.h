#pragma once
#include "Student.h"
#include <iomanip>

class Group
{
	Student *list;
	int studnum;
	double coef;
	

public:
    Group(int);
	~Group();

    void SetAtributes(int, string, string, string, string, string, string, string, double, int);


    string calcavg();
    string sort(); //��������� ������ �� �������� ������� ������
    string grants(); //����������� ������ ���������, ������� �������� ��������� � ��������� � ����

};

