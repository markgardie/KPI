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


void Group::SetAtributes(int studindex,
                         string name,
                         string m1,
                         string m2,
                         string m3,
                         string m4,
                         string m5,
                         string ifbudget,
                         double coef,
                         int studnum)
{
    list[studindex].SetN(name);
    list[studindex].SetM1(m1);
    list[studindex].SetM2(m2);
    list[studindex].SetM3(m3);
    list[studindex].SetM4(m4);
    list[studindex].SetM5(m5);
    list[studindex].SetIB(ifbudget);
    this->coef = coef;
    this->studnum = studnum;
}

string Group::calcavg()
{
	for (int i = 0; i < studnum; i++)
	{
		list[i].SetAv((stod(list[i].GetM1()) + stod(list[i].GetM2()) + stod(list[i].GetM3()) + stod(list[i].GetM4()) + stod(list[i].GetM5())) / 5);  //��������������� string � int � ����������� ������� ��������������
	}

    string temp = "";
    string s;
    for (int i = 0; i < studnum; i++)
    {
        s = list[i].GetN() + "," + to_string(list[i].GetAv()) + "\n" + temp;
        temp = s;
    }

    return s;
}

string Group::sort()
{
	
    for (int i = 0; i < studnum - 1; i++) //������� �� ��������������� �����
	{
		int max = i; //���������� ��������� ������ ������������� ��������
        for (int j = i+1; j < studnum; j++) //���������� ���� �������� �� ����������������� �����
		{
			if (list[j].GetAv() > list[max].GetAv()) //���� ��������� ������� ������ ��������
			{
				max = j; //�� ������ ������
			}
		}
		if (max != i) //���� ��������� ������ ��������������� ����� �� ��������� � �������� ������������� ��������
		{
			double temp = list[i].GetAv(); //������ �� �������
			list[i].SetAv(list[max].GetAv());
			list[max].SetAv(temp);
		}
	}


    string temp = "";
    string s;
    for (int i = studnum-1; i > 0; i--)
    {
        s = list[i].GetN() + "," + to_string(list[i].GetAv()) + "," + list[i].GetIfBud() + "\n" + temp;
        temp = s;
    }

    return s;

}

string Group::grants()
{
	int grantnum = studnum * coef; //���-�� ���������, ������� �������� ���������

    string temp = "";
    string s;
    for (int i = grantnum - 1; i > 0; i--)
	{
        if (list[i].GetIfBud() == "�") //���� ������� �� ���������
		{
            i--; //�� ���������� ��� � ��������� � ����������
			grantnum++; //� ����������� ����������, ����� ������� ����� ���-�� ���������
		}
        else {

            s = list[i].GetN() + "," + to_string(list[i].GetAv()) + "\n" + temp;
            temp = s;
        }
    }

    return s;
}
