#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
	string name; //���
	string mark1; //����������, ������� ��������
	string mark2; //�� ������
	string mark3; //���������� ��������� � ���� string
	string mark4; //����� ����� ���� ������������ ������� 
	string mark5; //getline()
	string ifbudget; //���������� ��� ���
	double avgmark; //������� ������
	

public:
	
	double GetAv();
	string GetN();
	string GetIfBud();
	string GetM1();
	string GetM2();
	string GetM3();
	string GetM4();
	string GetM5();
	
	void SetAv(double a);
	void SetN(string a);
	void SetM1(string a);
	void SetM2(string a);
	void SetM3(string a);
	void SetM4(string a);
	void SetM5(string a);
	void SetIB(string a);

};

