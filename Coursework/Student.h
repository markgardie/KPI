#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Human.h"

using namespace std;

struct Student:Human
{
    int marks[5];
	double avgmark; //������� ������
    bool ifbudget;

};

