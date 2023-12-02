#pragma once
#include <iostream>
#include <string>
using namespace std;

class Train
{
	string sEndPoint; //�������� ������ ��������
	string sTrainNum; //����� ������
	string sTimeStartHours;//����� �������
	string sTimeStartMinutes;//����� �������
public:
	Train();
	Train(const Train& obj);
	~Train();

	//Seters
	void setEndPoint(string _sEndPoint);
	void setTrainNum(string _sTrainNum);
	void setTimeStartHours(string _sTimeStart);
	void setTimeStartMinutes(string _sTimeStart);

	//Geters
	string getEndPoint();
	string getTrainNum();
	string getTimeStartHours();
	string getTimeStartMinutes();

	//Metods
	friend ostream& operator<<(ostream& stream, Train& obj);
};
