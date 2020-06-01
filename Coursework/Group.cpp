#include "Group.h"
#include <istream>
#include <sstream>

using namespace std;


Group::Group(int studnum)
{
    this->studnum = studnum;
    list = new Student[studnum];
}

Group::~Group()
{
	delete[] list;
}


void Group::SetAtributes(int studindex, string name,
                         int m [],
                         double coef,
                         bool budget,
                         int studnum)
{

    for (int i = 0; i < 5; i++) {
        list[studindex].marks[i] = m[i];
    }
    list[studindex].name = name;
    list[studindex].ifbudget = budget;
    this->coef = coef;
    this->studnum = studnum;
}

string Group::calcavg()
{
	for (int i = 0; i < studnum; i++)
	{
        list[i].avgmark = (list[i].marks[0] +  list[i].marks[1] +  list[i].marks[2]+  list[i].marks[3]+  list[i].marks[4]) / 5;  //преобразовываем string в int и расчитываем среднее арифметическое
	}

    string temp = "";
    string s;
    for (int i = 0; i < studnum; i++)
    {
        s = temp + list[i].name + "," + to_string(list[i].avgmark) + "\n";
        temp = s;
    }

    return s;
}

string Group::sort()
{
    int max = 0; //переменная сохраняет индекс максимального элемента
    double temp = 0;
    for (int i = 0; i < studnum; i++) //отвечат за отсортированную часть
	{
        max = i;
        for (int j = i; j < studnum; j++) //внутренний цикл отвечает за неотсортированную часть
		{
            if (list[j].avgmark > list[max].avgmark) //если находится элемент больше текущего
			{
                max = j; //то меняем индекс
			}
		}

        temp = list[i].avgmark; //меняем их местами
        list[i].avgmark = list[max].avgmark;
        list[max].avgmark = temp;

    }


    string temps = "";
    string s;
    for (int i = 0; i < studnum; i++)
    {
        s = temps +list[i].name + "," + to_string(list[i].avgmark) + "," + to_string(list[i].ifbudget) + "\n";
        temps = s;
    }

    return s;

}

string Group::grants()
{
	int grantnum = studnum * coef; //кол-во студентов, которые получают стипендию

    string temp = "";
    string s;
    for (int i = 0; i < grantnum; i++)
	{
        if (!list[i].ifbudget) //если студент не бюджетник
		{
            i++; //то пропускаем его и переходим к следующему
			grantnum++; //и увеличиваем переменную, чтобы набрать нужно кол-во студентов
		}
        else {

            s = temp + list[i].name + "," + to_string(list[i].avgmark) + "\n";
            temp = s;
        }
    }

    return s;
}
