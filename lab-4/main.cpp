#include <iostream>
#include "database.h"
#include <Windows.h>
using namespace std;

int main()
{
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DataBase A(8);
	int menu, e_number;
	while (1)
	{
		cout << "\n1. Ввести данные\n";
		cout << "2. Вывести отсортированный список\n";
		cout << "3. Найти информацию по номеру поезда\n";
		cout << "4. Выход\n";
		cin >> menu;
		switch (menu)
		{
		case 1:
			A.Input();
			break;

		case 2:
			A.OutPut();
			break;

		case 3:
			cout << "Введите номер поезда, чтобы посмотреть информацию о нём: ";
			cin >> e_number;
			A.Search(e_number);
			break;

		case 4:
			exit(0);
			break;
		}
	}
	system("pause");
	return 0;
}
