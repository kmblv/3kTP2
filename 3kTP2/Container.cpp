#include "Container.h"
#include "Exception.h"

Container::Container()
{
	cout << "Констуктор был вызван" << endl;
	data = nullptr;
	size = 0;
}

Container::~Container()
{
	if (data)
		delete[] data;
	cout << "Деструктор был вызван" << endl;
}

void Container::add()
{
	string sTmp;
	int iTmp;
	try
	{
		system("CLS");
		cout << "---------| Добавление |---------" << endl;
		Train* tmp = new Train[size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = data[i];
		}
		cout << "Введите номер поезда: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"Номер не может быть пустым!";
		tmp[size].setTrainNum(sTmp);
		cout << "Введите пункт назначения: ";
		getline(cin, sTmp);
		if (sTmp.empty())
			throw (string)"Пункт назначения не может быть пустым!";
		tmp[size].setEndPoint(sTmp);
		cout << "Введите время отправления:" << endl;
		cout << "Часа(-ов) [0-23]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 23)
			throw (string)"Значение должно быть от 0 до 23!";
		tmp[size].setTimeStartHours(sTmp);
		cout << "Минут[0-59]: ";
		getline(cin, sTmp);
		iTmp = stoi(sTmp);
		if (iTmp < 0 || iTmp > 59)
			throw (string)"Значение должно быть от 0 до 59!";
		if (iTmp < 10)
			sTmp = '0' + sTmp;
		tmp[size].setTimeStartMinutes(sTmp);
		if (data)
			delete[] data;
		data = tmp;
		cout << "Элемент успешно добавлен!" << endl;
		size++;
		system("pause");
	}
	catch (string err)
	{
		cout << "[Ошибка!] " + err << endl;
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
		cout << "---------| Изменение |---------" << endl;
		int choise1;
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "Введите какой поезд хотите изменить:" << endl;
		cin >> choise1;
		if (choise1 < 0 || choise1 >size + 1)
		{
			throw (string)"Такого поезда нет!";
		}
		int choise2;
		cout << "Какой параметр изменить:" << endl
			<< "1. Номер поезда" << endl
			<< "2. Пункт назначения" << endl
			<< "3. Время отправления" << endl;
		cin >> choise2;
		if (choise2 < 1 || choise2 >3)
		{
			throw (string)"Такого параметра нет!";
		}
		if (choise2 == 1) {
			cout << "Введите новый номер поезда: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"Номер не может быть пустым!";
			data[choise1].setTrainNum(sTmp);
		}
		if (choise2 == 2) {
			cout << "Введите пункт назначения: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			if (sTmp.empty())
				throw (string)"Пункт назначения не может быть пустым!";
			data[choise1].setEndPoint(sTmp);
		}
		if (choise2 == 3) {
			cout << "Введите время отправления:" << endl;
			cout << "Часа(-ов) [0-23]: ";
			cin.ignore(INT_MAX, '\n');
			getline(cin, sTmp);
			iTmp = stoi(sTmp);
			if (iTmp < 0 || iTmp > 23)
				throw (string)"Значение должно быть от 0 до 23!";
			data[choise1].setTimeStartHours(sTmp);
			cout << "Минут[0-59]: ";
			getline(cin, sTmp);
			iTmp = stoi(sTmp);
			if (iTmp < 0 || iTmp > 59)
				throw (string)"Значение должно быть от 0 до 59!";
			if (iTmp < 10)
				sTmp = '0' + sTmp;
			data[choise1].setTimeStartMinutes(sTmp);
		}
		cout << "Элемент был изменён!" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[Ошибка] " + err << endl;
		system("pause");
	}
}

void Container::del()
{
	int index;
	system("CLS");
	cout << "---------| Удаление |---------" << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для удаления!";
		for (int i = 0; i < size; i++)
		{
			cout << i << ". " << data[i].getTrainNum() << endl;
		}
		cout << "Выберите элемент для удаления: ";
		cin >> index;
		if (index < 0 || index > size - 1)
			throw (string)"Такого элемента не существует!";
		if (size == 1)
		{
			delete[] data;
			data = nullptr;
			cout << "Поезд успешно удалён!" << endl;
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
		cout << "Поезд успешно удалён!" << endl;
		system("pause");
	}
	catch (string err)
	{
		cout << "[Ошибка] " + err << endl;
	}
}


void Container::sort()
{
	system("CLS");
	cout << "---------| Сортировка по алфавиту |---------" << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для сортировки";
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (strcmp(data[j].getEndPoint().c_str(), data[j + 1].getEndPoint().c_str()) > 0) {
					swap(data[j], data[j + 1]);// меняем элементы местами
				}
			}
		}
	}
	catch (string err)
	{
		cout << "[Ошибка] " + err << endl;
	}
}

void Container::search()
{
	system("CLS");
	cout << "---------| Поиск по времени |---------" << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов!";
		string sTime; // Время
		string sTimeFormat; // Время
		bool empty = false; // Флаг пустоты вывода
		int iTime;
		cout << "Введите часы [0-23]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 23)
			throw (string)"Значение должно быть от 0 до 23!";
		sTimeFormat = sTime;
		cout << "Введите минуты [0-59]: ";
		cin >> sTime;
		iTime = stoi(sTime);
		if (iTime < 0 || iTime > 59)
			throw (string)"Значение должно быть от 0 до 60!";
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
			cout << "Нет подходящих поездов!" << endl;
	}
	catch (string err)
	{
		cout << "[Ошибка] " + err << endl;
	}
}

void Container::print()
{
	system("CLS");
	cout << "---------| Список |---------" << endl << endl;
	try
	{
		if (!size)
			throw (string)"Нет поездов для вывода";
		for (int i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	catch (string err)
	{
		cout << "[Ошибка] " + err << endl;
	}
}