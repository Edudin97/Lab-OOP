#include "train.h"
using namespace std;

class DataBase
{
public:
	DataBase(int);
	~DataBase();
	void Input();
	void OutPut();
	void Search(const int e_number);
private:
	TRAIN* m_train;
	int Col;
};

DataBase::DataBase(int C) : m_train(new TRAIN[C]), Col(C) {}
DataBase::~DataBase() { if (m_train) delete[] m_train; }

void DataBase::Input()
{
	cout << "Введите информацию о поезде: " << endl;
	cout << "\nПункт назначения   Номер поезда   Время отправления\n" << endl;
	for (auto i = 0; i < Col; ++i)
	{
		cout << (i + 1) << ". ";
		cin >> m_train[i];
	}

	for (auto i = 0; i < Col - 1; ++i)
	{
		for (auto j = 0; j < Col - i - 1; ++j)
		{
			if (m_train[j].Number() > m_train[j + 1].Number())
			{
				TRAIN T = m_train[j];
				m_train[j] = m_train[j + 1];
				m_train[j + 1] = T;
			}
		}
	}
}

void DataBase::OutPut()
{
	cout << "\nОтсортированный список:" << endl;
	for (auto i = 0; i < Col; ++i)
	{
		cout << (i + 1) << ". " << m_train[i] << endl;
	}
}

void DataBase::Search(const int e_number)
{
	auto search = true;
	for (auto i = 0; i < Col; ++i)
	{
		if (m_train[i].Number() == e_number)
		{
			cout << m_train[i].Name() << " "
				<< m_train[i].Number() << " "
				<< m_train[i].Time() << endl;
			search = false;
		}
	}

	if (search)
	{
		cout << "Поезд не найден." << endl;
	}
}