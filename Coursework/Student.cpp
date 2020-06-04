#include "Student.h"

Student::Student (list<int> marks, string name, bool ifbudget) {
    list<int>:: iterator it;

    for (it = marks.begin(); it != marks.end(); ++it) {
        this->marks.push_back(*it);
    }

    //this->marks.merge(marks);
    this->name = name;
    this->ifbudget = ifbudget;
}

Student::~Student () {

}
