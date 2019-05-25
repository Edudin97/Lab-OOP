#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

template <class T> class stack
{
public:
	stack() { cout << "Debug - stack created. Type of stack - " << typeid(T).name() << endl; };
	~stack() { ourstack.clear(); cout << "Debug - stack of " << typeid(T).name() << " destroyed" << endl; };
	void push(T value) { ourstack.push_back(value); cout << "Debug - stack pushed with [ " << value << " ];" << endl; }; // ��������� � ����� ����� �������
	void pop() { if (!empty()) { cout << "Debug - stack popped, deleted element [ " << ourstack.back() << " ];" << endl; ourstack.pop_back(); } }; // ������� ��������� �������
	T   top() const { return ourstack.back(); }; // ���������� ��������� �������
	void print() const { cout << ourstack.back(); }; // �������� ��������� �������. �������� ���������� ����� iostream/cout
	void clear() { ourstack.clear(); }; // ������� ���� ����
	bool empty() { return ourstack.empty(); };
	int size() const { return ourstack.size(); }; // ������ �����
private:
	vector <T> ourstack;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "����� ������. ���18-01, ������� 6;" << endl << endl;
	cout << "�� ���� ��������� ��������� ������� ������ ���������� �������� ������ �," << endl
		<< "��������, ������������� � ����������� ���������� ���������� ������ �. " << endl
		<< "��� ��������, ��� ������ ������ � ������������ ��� ������� ������ �. " << endl
		<< "� �������� ���������� ������ ����� ���� ������ ���� �����, ���������" << endl
		<< "�������������, ���� ����� �� ����������� ���������� � ��������, std::vector. " << endl
		<< "�������� ������� ��� ��������� �������, ����������� �������������, ��������� " << endl
		<< "� ����. 3.1. ���������� � ������ � ������������� ����������� ������ " << endl
		<< "(�������� ������, ����, ������������� �������, �������� ������) ��. � �������� " << endl
		<< "(�. 114-127), � ����� � ������ ����� ���������� [2] (������� 9)." << endl;

	system("pause");
	system("cls");

	stack<int> numbers;
	cout << "Size of stack : " << numbers.size() << endl;
	numbers.push(15);
	numbers.push(14);
	numbers.push(13);
	numbers.push(11);
	numbers.push(10);
	cout << "Size of stack : " << numbers.size() << endl;
	cout << "At top of stack : " << numbers.top() << endl;
	numbers.pop();
	numbers.pop();
	numbers.pop();
	numbers.pop();
	if (numbers.empty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Size of stack : " << numbers.size() << endl;
		cout << "At top of stack : " << numbers.top() << endl;
	}

	system("pause");
	system("cls");

	stack<double> numbers_2;
	cout << "Size of stack : " << numbers_2.size() << endl;
	numbers_2.push(1.5);
	numbers_2.push(1.4);
	numbers_2.push(1.3);
	numbers_2.push(1.1);
	numbers_2.push(1.0);
	cout << "Size of stack : " << numbers_2.size() << endl;
	cout << "At top of stack : " << numbers_2.top() << endl;
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	numbers_2.pop();
	if (numbers_2.empty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Size of stack : " << numbers_2.size() << endl;
		cout << "At top of stack : " << numbers_2.top() << endl;
	}

	system("pause");
	system("cls");

	stack<string> numbers_3;
	cout << "Size of stack : " << numbers_3.size() << endl;
	numbers_3.push("String 5");
	numbers_3.push("String 4");
	numbers_3.push("String 3");
	numbers_3.push("String 2");
	numbers_3.push("String 1");
	cout << "Size of stack : " << numbers_3.size() << endl;
	cout << "At top of stack : " << numbers_3.top() << endl;
	numbers_3.pop();
	numbers_3.pop();
	if (numbers_3.empty())
		cout << "Stack is empty" << endl;
	else
	{
		cout << "Size of stack : " << numbers_3.size() << endl;
		cout << "At top of stack : " << numbers_3.top() << endl;
	}

	system("pause");
	return 0;
}