#include "Container.h"
#include "Exception.h"

Container::Container()
{
	cout << "���������� ��� ������" << endl;
	data = nullptr;
	size = 0;
}

Container::~Container()
{
	if (data)
		delete[] data;
	cout << "���������� ��� ������" << endl;
}

void Container::add()
{
	string sTmp;
	int iTmp;
	try
	{
		system("CLS");
		cout << "---------| ���������� |---------" << endl;
		Train* tmp = new Train[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		cout << "������� ����� ������: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"����� �� ����� ���� ������!";
		tmp[size].setTrainNum(sTmp);
		cout << "������� ����� ����������: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"����� ���������� �� ����� ���� ������!";
		tmp[size].setEndPoint(sTmp);
		cout << "������� ����� �����������:" << endl;
		cout << "����(-��) [0-23]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 23)
			throw (string)"�������� ������ ���� �� 0 �� 23!";
		tmp[size].setTimeStartHours(sTmp);
		cout << "�����[0-59]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 59)
			throw (string)"�������� ������ ���� �� 0 �� 59!";
		if (iTmp < 10)
			sTmp = '0' + sTmp;
		tmp[size].setTimeStartMinutes(sTmp);
		if (data)
			delete[] data;
		data = tmp;
		cout << "������� ������� ��������!" << endl;
		size++;
		system("pause");
	}
	catch (string err)
	{
		cout << "[������!] " + err << endl;
		system("pause");
	}
}

void Container::red()
{
	try
	{
		system("CLS");
		string sTmp;
		int iTmp;
		cout << "---------| ��������� |---------" << endl;
		int choise1;
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "������� ����� ����� ������ ��������:" << endl;
		cin >> choise1;
		if (choise1 < 0 || choise1 >size + 1)
		{
			throw (string)"������ ������ ���!";
		}
		int choise2;
		cout << "����� �������� ��������:" << endl
			<< "1. ����� ������" << endl
			<< "2. ����� ����������" << endl
			<< "3. ����� �����������" << endl;
		cin >> choise2;
		if (choise2 < 1 || choise2 >3)
		{
			throw (string)"������ ��������� ���!";
		}
		if (choise2 == 1) {
			cout << "������� ����� ����� ������: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"����� �� ����� ���� ������!";
			data[choise1].setTrainNum(sTmp);
		}
		if (choise2 == 2) {
			cout << "������� ����� ����������: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"����� ���������� �� ����� ���� ������!";
			data[choise1].setEndPoint(sTmp);
		}
		if (choise2 == 3) {
			cout << "������� ����� �����������:" << endl;
			cout << "����(-��) [0-23]: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			iTmp = stoi(sTmp);
			if (iTmp < 0 || iTmp > 23)
				throw (string)"�������� ������ ���� �� 0 �� 23!";
			data[choise1].setTimeStartHours(sTmp);
			cout << "�����[0-59]: ";
			getline(cin, sTmp);
			iTmp = stoi(sTmp);
			if (iTmp < 0 || iTmp > 59)
				throw (string)"�������� ������ ���� �� 0 �� 59!";
			if (iTmp < 10)
				sTmp = '0' + sTmp;
			data[choise1].setTimeStartMinutes(sTmp);
		}
		cout << "������� ��� ������!" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[������] " + err << endl;
		system("pause");
	}
}

void Container::del()
{
	int index;
	system("CLS");
	cout << "---------| �������� |---------" << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ��������!";
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "�������� ������� ��� ��������: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"������ �������� �� ����������!";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "����� ������� �����!" << endl;
			size--;
			system("pause");
			return;
		}
		Train* tmp = new Train[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (index == i)
				continue;
			tmp[j] = data[i];
			j++;
		}
		delete[] data;
		data = tmp;
		size--;
		cout << "����� ������� �����!" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[������] " + err << endl;
	}
}


void Container::sort()
{
	system("CLS");
	cout << "---------| ���������� �� �������� |---------" << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ����������";
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (strcmp(data[j].getEndPoint().c_str(), data[j + 1].getEndPoint().c_str()) > 0) {
					swap(data[j], data[j + 1]);// ������ �������� �������
				}
			}
		}
	}
	catch (string err)
	{
		cout << "[������] " + err << endl;
	}
}

void Container::search()
{
	system("CLS");
	cout << "---------| ����� �� ������� |---------" << endl;
	try
	{
		if (!size)
			throw (string)"��� �������!";
		string sTime; // �����
		string sTimeFormat; // �����
		bool empty = false; // ���� ������� ������
		int iTime;
		cout << "������� ���� [0-23]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 23)
			throw (string)"�������� ������ ���� �� 0 �� 23!";
		sTimeFormat = sTime;
		cout << "������� ������ [0-59]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 59)
			throw (string)"�������� ������ ���� �� 0 �� 60!";
		for (int i = 0; i < size; i++) {
			if (stoi(sTimeFormat) < stoi(data[i].getTimeStartHours())) {
				!empty ? empty = true : false;
				cout << data[i];
			}
			else if (stoi(sTimeFormat) == stoi(data[i].getTimeStartHours())) {
				if (stoi(sTime) < stoi(data[i].getTimeStartMinutes())) {
					!empty ? empty = true : false;
					cout << data[i];
				}
			}
		}
		if (!empty)
			cout << "��� ���������� �������!" << endl;
	}
	catch (string err)
	{
		cout << "[������] " + err << endl;
	}
}

void Container::print()
{
	system("CLS");
	cout << "---------| ������ |---------" << endl << endl;
	try
	{
		if (!size)
			throw (string)"��� ������� ��� ������";
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	catch (string err)
	{
		cout << "[������] " + err << endl;
	}
}