#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "Human.h"
#include "Subject.h"
#include <list>
#include <iterator>

using namespace std;

struct Teacher:Human {
    list<Subject> subjects;
};


#endif // TEACHER_H
