#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student
{
	string name; //ФИО
	string mark1; //переменные, которые отвечают
	string mark2; //за оценки
	string mark3; //специально обьявлены в типе string
	string mark4; //чтобы можно было использовать функцию 
	string mark5; //getline()
	string ifbudget; //бюджетники или нет
	double avgmark; //средняя оценка
	

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

