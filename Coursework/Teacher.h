#ifndef TEACHER_H
#define TEACHER_H
#include <iostream>
#include "Human.h"
#include "Subject.h"

using namespace std;

struct Teacher:Human {
    Subject *subjects;
};


#endif // TEACHER_H
