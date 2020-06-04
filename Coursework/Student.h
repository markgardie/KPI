#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include "Human.h"

using namespace std;

struct Student:Human
{
    list<int> marks;
    double avgmark;
    bool ifbudget;

    Student(list<int>, string, bool);
    ~Student();
};

