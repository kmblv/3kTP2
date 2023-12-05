#include <iostream>
#include <fstream>
#include "Container.h"
#include "Exception.h"
#include <cstring>

int getWords();

int main()
{
	setlocale(LC_ALL, "Russian");
	Container Table;
	char menu;
	int iCount;
	do
	{
		system("cls");
		cout << "----------| МЕНЮ |----------" << endl;
		cout << "1. Добавить поезд" << endl
			<< "2. Удалить поезд" << endl
			<< "3. Измененить данные" << endl
			<< "4. Отсортировать по алфивиту" << endl
			<< "5. Вывод" << endl
			<< "6. Найти поезд по времени" << endl
			<< "7. Посчитать количество слов, состоящих из 4 и менее букв" << endl
			<< "0. Выход" << endl
			<< "Ваш выбор: ";
		cin >> menu;
		if (!(cin.peek() == '\n' || cin.peek() == EOF))
		{
			cin.ignore(INT_MAX, '\n');
			throw Exception("Нет поездов!");
			system("pause");
			continue;
		}
		cin.ignore(INT_MAX, '\n');
		try {


			switch (menu)
			{
			case '1':
				Table.add();
				break;
			case '2':
				Table.del();
				break;
			case '3':
				Table.red();
				break;
			case '4':
				Table.sort();
				break;
			case '5':
				Table.print();
				break;
			case '6':
				Table.search();
				break;
			case '7':
				getWords();
				break;
			case '0':
				return 0;
			default:
				throw Exception("Выберите значение от 0 до 7\n");
				break;
			}
		}
		catch (Exception error) {
			cout << error;
		}
		system("pause");
	} while (true);
	system("pause");
	return 0;
}

int getWords()
{
	std::ifstream inputFile("Text.txt");
	if (!inputFile.is_open()) {
		std::cerr << "Ошибка открытия файла!" << std::endl;
		return 1;
	}

	std::string word;
	int wordCount = 0;
	while (inputFile >> word) {
		bool isAllAlpha = true;
		for (char c : word) { // проверяем каждый символ в слове
			if (!std::isalpha(c)) { // если встретился не буквенный символ
				isAllAlpha = false;
				break;
			}
		}
		if (isAllAlpha && !word.empty()) {
			wordCount++; // увеличиваем счетчик слов
		}
	}

	std::cout << "Количество слов: " << wordCount << std::endl;

	inputFile.close(); // закрываем файл
	return 0;
}
