#include "Group.h"
#include <istream>
#include <sstream>
#include <iterator>

using namespace std;


Group::Group(int studnum)
{
    this->studnum = studnum;

}


void Group::SetAtributes(string name,
                         list<int> marks,
                         double coef,
                         bool budget,
                         int studnum)
{

    Student s (marks, name, budget);
    students.push_back(s);
    this->coef = coef;
    this->studnum = studnum;

}

string Group::calcavg()
{

    for (it1 = students.begin(); it1 != students.end(); ++it1) {
        int sum = 0;
        for (it2 = it1->marks.begin(); it2 != it1->marks.end(); ++it2) {
            sum+=(*it2);
        }
        it1->avgmark = sum / (*it1).marks.size();
    }

    string temp = "";
    string s;
    for (it1 = students.begin(); it1 != students.end(); ++it1)
    {
        s = temp + (*it1).name + "," + to_string((*it1).avgmark) + "\n";
        temp = s;
    }

    return s;
}

string Group::sort()
{


    list<Student>::iterator max;
    list<Student>::iterator i;
    list<Student>::iterator j;
    double temp = 0;
    for (i = students.begin(); i != students.end(); ++i)
	{
        max = i;
        for (j = i; j != students.end(); ++j)
		{
            if ((*j).avgmark > (*max).avgmark)
			{
                max = j;
			}
		}

        temp = (*i).avgmark;
        (*i).avgmark = (*max).avgmark;
        (*max).avgmark = temp;

    }


    string temps = "";
    string s;
    for (i = students.begin(); i != students.end(); ++i)
    {
        s = temps + (*i).name + "," + to_string((*i).avgmark) + "," + to_string((*i).ifbudget) + "\n";
        temps = s;
    }

    return s;

}

string Group::grants()
{
    int grantnum = studnum * coef;

    string temp = "";
    string s;
    for (it1 = students.begin(); it1 != students.end(); ++it1)
	{
        if (!(*it1).ifbudget)
		{
            ++it1;
            grantnum++;
		}
        else if (grantnum == 0) return s;
        else {

            s = temp + (*it1).name + "," + to_string((*it1).avgmark) + "\n";
            temp = s;
            grantnum--;
        }
    }

}
