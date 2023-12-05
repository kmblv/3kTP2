#include "Train.h"

ostream& operator<<(ostream& stream, Train& obj)
{
	stream << "----------| Поезд |-----------" << endl
		<< "Пункт назначения: " << obj.getEndPoint() << endl
		<< "Номер: " << obj.getTrainNum() << endl
		<< "Время отправления: " << obj.getTimeStartHours() << ":" << obj.getTimeStartMinutes() << endl;
	return stream;
}

Train::Train()
{
	cout << "Констуктор был вызван" << endl;
	sEndPoint = "";
	sTrainNum = "";
	sTimeStartHours = "";
	sTimeStartMinutes = "";
}

Train::Train(const Train& obj)
{
	cout << "Конструктор копирования был вызван" << endl;
	sEndPoint = obj.sEndPoint;
	sTrainNum = obj.sTrainNum;
	sTimeStartHours = obj.sTimeStartHours;
	sTimeStartMinutes = obj.sTimeStartMinutes;
}

Train::~Train()
{
	cout << "Деструктор был вызван" << endl;
}

void Train::setEndPoint(string _sEndPoint)
{
	sEndPoint = _sEndPoint;
}

void Train::setTrainNum(string _sTrainNum)
{
	sTrainNum = _sTrainNum;
}

void Train::setTimeStartHours(string _sTimeStart)
{
	sTimeStartHours = _sTimeStart;
}

void Train::setTimeStartMinutes(string _sTimeStart)
{
	sTimeStartMinutes = _sTimeStart;
}

string Train::getEndPoint()
{
	return sEndPoint;
}

string Train::getTrainNum()
{
	return sTrainNum;
}

string Train::getTimeStartHours()
{
	return sTimeStartHours;
}

string Train::getTimeStartMinutes()
{
	return sTimeStartMinutes;
}